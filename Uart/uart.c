#include <XC.h>
#include "uart.h"
#define _XTAL_FREQ  16000000

void uart_init()
{
    TRISC7  =  1;            // RX
    TRISC6  =  0;            // TX
    
    TXSTA   =  0X26;
    
    RCSTA   =  0X90;
    SPBRG   =  103;
}

void uart_sent_letter(char letter)
{
    while(TXIF==0);                   // check the flag is equal zero
    TXREG = letter;                   // assign the data in 'txreg'flag.
}

void uart_sent_text(char *text)
{
    while(*text)                       // Check if the current character is not '\0' or false
    {
        uart_sent_letter(*text);       // Send the current character
        text++;                        // Move the pointer to the next character
    
    }
    
}

char uart_read()                       // Wait until data is received
{
   return RCREG;                       // Read and return received character   
}

int uart_ready()
{
    if(OERR)
    {
        CREN = 0;
        CREN = 1;
    }
    return RCIF;
}

int uart_read_string(char *message, int max_len)
{
    int i = 0;
    char ch;

    while(1)
    {
        if(uart_ready())                // end of string when enter is pressed
        {
            ch = uart_read();

            if(ch == '\r' || ch == '\n')  // store character if there is space
            {
                break;
            }

            if(i < max_len - 1)
            {
                message[i] = ch;
                i++;
            }
        }
    }
    message[i] = '\0';                     // imp: terminate the string
}