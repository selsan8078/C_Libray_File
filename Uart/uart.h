/* 
 * File:   uart.h
 * Author: dell
 *
 * Created on 16 September, 2026, 5:26 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif
void uart_init();                   //Directions
void uart_sent_letter(char letter); //character
void uart_sent_text(char *text);    //String
char uart_read();                   //received character
int  uart_ready();                  //check uart is enable
int uart_read_string(char *message, int max_len);




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

