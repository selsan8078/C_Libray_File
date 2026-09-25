
#include <xc.h>
#include "eeprom.h"

void eeprom_write(unsigned char address, unsigned char data)
{
    // Wait until previous write is finished
    while(EECON1bits.WR);

    // Select EEPROM address
    EEADR = address;

    // Put data to write
    EEDATA = data;

    // Select DATA EEPROM
    EECON1bits.EEPGD = 0;

    // Enable EEPROM write
    EECON1bits.WREN = 1;

    // Disable interrupts during unlock sequence
    INTCONbits.GIE = 0;

    // Required EEPROM unlock sequence
    EECON2 = 0x55;
    EECON2 = 0xAA;

    // Start EEPROM write
    EECON1bits.WR = 1;

    // Wait until writing is finished
    while(EECON1bits.WR);

    // Disable EEPROM write
    EECON1bits.WREN = 0;

    // Enable interrupts again
    INTCONbits.GIE = 1;
}


unsigned char eeprom_read(unsigned char address)
{
    // Select EEPROM address
    EEADR = address;

    // Select DATA EEPROM
    EECON1bits.EEPGD = 0;

    // Start EEPROM read
    EECON1bits.RD = 1;

    // Return EEPROM data
    return EEDATA;
}


void eeprom_write_int(unsigned int value)
{
    unsigned char low_byte;
    unsigned char high_byte;

    // Get lower 8 bits
    low_byte = value & 0xFF;

    // Get upper 8 bits
    high_byte = (value >> 8) & 0xFF;

    // Store low byte at EEPROM address 0
    eeprom_write(0, low_byte);

    // Store high byte at EEPROM address 1
    eeprom_write(1, high_byte);
}


unsigned int eeprom_read_int(void)
{
    unsigned int value;

    unsigned char low_byte;
    unsigned char high_byte;

    // Read low byte
    low_byte = eeprom_read(0);

    // Read high byte
    high_byte = eeprom_read(1);

    // Combine both bytes
    value = low_byte | ((unsigned int)high_byte << 8);

    return value;
}