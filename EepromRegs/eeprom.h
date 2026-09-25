/* 
 * File:   eeprom.h
 * Author: dell
 *
 * Created on 22 September, 2026, 3:40 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

void eeprom_write(unsigned char address, unsigned char data);
unsigned char eeprom_read(unsigned char address);

void eeprom_write_int(unsigned int value);
unsigned int eeprom_read_int(void);


#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

