/*
 * print_task.c
 *
 *  Created on: Jan 26, 2021
 *      Author: gregmartin
 */

#define __PRINT_TASK_C__

#include "target/core-v-mcu/include/core-v-mcu-config.h"
#include <periph-tasks/include/write_uart_task.h>
#include <string.h>
#include "hal/include/hal_fc_event.h"

static TaskHandle_t xTasktoNotify[N_UART];
static QueueHandle_t xPrtQueue[N_UART];  // Print queue
void vSendString(uint8_t uart_id, uint8_t *pcString, uint32_t len)
{
	print_t mymessage;
	
	configASSERT(mymessage.str = pvPortMalloc(len));
	memcpy (mymessage.str, pcString, len);
	mymessage.len = len;
	xQueueSend(xPrtQueue[uart_id], &mymessage, portMAX_DELAY);
}

uint32_t getline(uart_channel_t *uart, uint8_t *str, uint32_t len) {
	uint32_t ret = 0;
	uint8_t last_char = 0;

	uart = (uart_channel_t*)UDMA_CH_ADDR_UART0;
	while ( (ret < (len-2)) && (last_char != 0xd)) {
		if (uart->valid == 1) {
			last_char = (uint8_t)(uart->data & 0xff);
			if (last_char == 0xd)  // if cr add
				str[ret++] = 0xa;  // linefeed
			str[ret++] = last_char;
		}
	}
	return ret--;
}


static void ISR_uart0_handler() {
	BaseType_t *pxHigherPriorityTaskWoken;
	configASSERT(xTasktoNotify[0]);

	vTaskNotifyGiveFromISR(xTasktoNotify[0],
	                       &pxHigherPriorityTaskWoken );
	portYIELD_FROM_ISR( pxHigherPriorityTaskWoken );
}

static void ISR_uart1_handler() {
	BaseType_t *pxHigherPriorityTaskWoken;
	configASSERT(xTasktoNotify[0]);

	vTaskNotifyGiveFromISR(xTasktoNotify[1],
	                       &pxHigherPriorityTaskWoken );
	portYIELD_FROM_ISR( pxHigherPriorityTaskWoken );
}

void prvWriteUart0Task (void *pvParameters)
{
	uart_channel_t *uart;
	print_t str_struct;

	volatile uint32_t *udma_cg = (uint32_t*)UDMA_CH_ADDR_CTRL;
	xPrtQueue[0] = xQueueCreate(PrintQueueLength, sizeof(print_t));
	configASSERT(xPrtQueue[0]);
    /* Set handlers. */
    pi_fc_event_handler_set(SOC_EVENT_UDMA_UART_RX(0), ISR_uart0_handler);
    pi_fc_event_handler_set(SOC_EVENT_UDMA_UART_TX(0), ISR_uart0_handler);
    /* Enable SOC events propagation to FC. */
    hal_soc_eu_set_fc_mask(SOC_EVENT_UDMA_UART_RX(0));
    hal_soc_eu_set_fc_mask(SOC_EVENT_UDMA_UART_TX(0));

	*udma_cg |= UDMA_CTRL_UART0_CLKEN;  // turn on uart clock ?;
	uart = (uart_channel_t*)UDMA_CH_ADDR_UART0;
	uart->setup = (5000000/115200) << 16 | // Baud rate divisor
			(3 << 1) | // 8-bits
			(1 << 4) | // use polling on read
			(1 << 8) | // tx enable
			(1 << 9) ; // rx enable
	xTasktoNotify[0] = xTaskGetCurrentTaskHandle();
	for (;;) {
		xQueueReceive(xPrtQueue[0], &str_struct, portMAX_DELAY);
		uart->tx_saddr = str_struct.str;
		uart->tx_size = str_struct.len;
		uart->tx_cfg = 0x10; //enable the transfer
        ulTaskNotifyTake(pdTRUE,          /* Clear the  value before exiting. */
                         portMAX_DELAY );
        vPortFree(str_struct.str);

	}
}

void prvWriteUart1Task (void *pvParameters)
{
	uart_channel_t *uart;
	print_t str_struct;

	volatile uint32_t *udma_cg = (uint32_t*)UDMA_CH_ADDR_CTRL;
	xPrtQueue[1] = xQueueCreate(PrintQueueLength, sizeof(print_t));
	configASSERT(xPrtQueue[1]);
    /* Set handlers. */
    pi_fc_event_handler_set(SOC_EVENT_UDMA_UART_RX(1), ISR_uart1_handler);
    pi_fc_event_handler_set(SOC_EVENT_UDMA_UART_TX(1), ISR_uart1_handler);
    /* Enable SOC events propagation to FC. */
    hal_soc_eu_set_fc_mask(SOC_EVENT_UDMA_UART_RX(1));
    hal_soc_eu_set_fc_mask(SOC_EVENT_UDMA_UART_TX(1));

	*udma_cg |= UDMA_CTRL_UART1_CLKEN;  // turn on uart clock ?;
	uart = (uart_channel_t*)UDMA_CH_ADDR_UART1;
	uart->setup = (5000000/115200) << 16 | // Baud rate divisor
			(3 << 1) | // 8-bits
			(1 << 4) | // use polling on read
			(1 << 8) | // tx enable
			(1 << 9) ; // rx enable
	xTasktoNotify[1] = xTaskGetCurrentTaskHandle();
	for (;;) {
		xQueueReceive(xPrtQueue[1], &str_struct, portMAX_DELAY);
		uart->tx_saddr = str_struct.str;
		uart->tx_size = str_struct.len;
		uart->tx_cfg = 0x10; //enable the transfer
        ulTaskNotifyTake(pdTRUE,          /* Clear the  value before exiting. */
                         portMAX_DELAY );
        vPortFree(str_struct.str);

	}
}
