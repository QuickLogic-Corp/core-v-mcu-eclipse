/*==========================================================
 * Copyright 2020 QuickLogic Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *==========================================================*/

/*==========================================================
 *
 *    File   : main.c
 *    Purpose: 
 *                                                          
 *=========================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libs/cli/include/cli.h"
#include "periph-tasks/include/write_uart_task.h"
#include "libs/utils/include/dbg_uart.h"
//#include "qlsh_commands.h"

// Sub menus
const struct cli_cmd_entry uart1[];

// UART functions
static void uart1_tx(const struct cli_cmd_entry *pEntry);

// Main menu
const struct cli_cmd_entry my_main_menu[] = {
    CLI_CMD_SUBMENU( "uart1", uart1, "commands for uart1" ),
    CLI_CMD_TERMINATE()
};

// UART1 menu
const struct cli_cmd_entry uart1[] =
{
	CLI_CMD_SIMPLE( "tx", uart1_tx, "<string>: write <string> to uart1" ),
    CLI_CMD_TERMINATE()
};

// UART functions
static void uart1_tx(const struct cli_cmd_entry *pEntry)
{
	char*	pzArg = NULL;
    (void)pEntry;
    // Add functionality here
    while (CLI_peek_next_arg() != NULL) {
    	if (pzArg != NULL) {
    		vUartTxChar(1, ' ');
    	}
    	CLI_string_ptr_required("string", &pzArg);
    	vUartTxBuf(1, pzArg, strlen(pzArg));
    }
    vUartTxBuf(1, "\r\n", 2);
    return;
}





