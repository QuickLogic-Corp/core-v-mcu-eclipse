#ifndef __PRINT_TASK_H__
#define __PRINT_TASK_H__

#include <FreeRTOS.h>
#include <queue.h>

#ifdef __PRINT_TASK_C__
#define EXTERN
#else
#define EXTERN extern
#endif

typedef struct {
	volatile uint8_t *rx_saddr;
	volatile uint32_t rx_size;
	volatile uint32_t rx_cfg;
	volatile uint32_t unused1;
	volatile uint8_t *tx_saddr;
	volatile uint32_t tx_size;
	volatile uint32_t tx_cfg;
	volatile uint32_t unused2;
	volatile uint32_t status;
	volatile uint32_t setup;
	volatile uint32_t error;
	volatile uint32_t irq_en;
	volatile uint32_t valid;
	volatile uint32_t data;
} uart_channel_t;

#define PrintQueueLength	(3)
typedef struct {
	uint8_t *str;
	uint32_t len;
} print_t;

void vSendString(uint8_t uart_id, uint8_t *pcString, uint32_t len);

void prvWriteUart0Task (void *pvParameters);
void prvWriteUart1Task (void *pvParameters);


#endif
