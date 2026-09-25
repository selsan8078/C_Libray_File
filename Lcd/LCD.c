#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ  16000000
#define RS RC0
#define RW RC1
#define EN RC2

void lcd_init()
{  
    // RC0, RC1, RC2 as output
    TRISC0 = 0;
    TRISC1 = 0;
    TRISC2 = 0;

    // RB4-RB7 as output
    TRISB4 = 0;
    TRISB5 = 0;
    TRISB6 = 0;
    TRISB7 = 0;
 
}
void lcd_on_off_cmd(void)
{
    
}
void lcd_command(unsigned char cmd)
{
    RS = 0;       // RS = 0 ? Command
    RW = 0;       // RW = 0 ? Write

    // Send upper 4 bits: bit 7,6,5,4
    RB4 = (cmd >> 4) & 1;   // bit 4 ? D4
    RB5 = (cmd >> 5) & 1;   // bit 5 ? D5
    RB6 = (cmd >> 6) & 1;   // bit 6 ? D6
    RB7 = (cmd >> 7) & 1;   // bit 7 ? D7

    EN = 1;
    __delay_ms(2);
    EN = 0;
    __delay_ms(2);

    // Send lower 4 bits: bit 3,2,1,0
    RB4 = (cmd >> 0) & 1;   // bit 0 ? D4
    RB5 = (cmd >> 1) & 1;   // bit 1 ? D5
    RB6 = (cmd >> 2) & 1;   // bit 2 ? D6
    RB7 = (cmd >> 3) & 1;   // bit 3 ? D7

    EN = 1;
    __delay_ms(2);
    EN = 0;
    __delay_ms(2);
}


void lcd_data(unsigned char data)
{
    RS = 1;       // RS = 1 ? Data
    RW = 0;       // RW = 0 ? Write

    // Send upper 4 bits
    RB4 = (data >> 4) & 1;   // D4
    RB5 = (data >> 5) & 1;   // D5
    RB6 = (data >> 6) & 1;   // D6
    RB7 = (data >> 7) & 1;   // D7

    EN = 1;
    __delay_ms(2);
    EN = 0;
    __delay_ms(2);

    // Send lower 4 bits
    RB4 = (data >> 0) & 1;   // D4
    RB5 = (data >> 1) & 1;   // D5
    RB6 = (data >> 2) & 1;   // D6
    RB7 = (data >> 3) & 1;   // D7

    EN = 1;
    __delay_ms(2);
    EN = 0;
    __delay_ms(2);
}

