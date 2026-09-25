/* 
 * File:   LCD.h
 * Author: dell
 *
 * Created on 13 September, 2026, 10:57 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

    void lcd_init();
    void lcd_command(unsigned char cmd);
    void lcd_on_off_cmd(unsigned char cmd);
    void lcd_data(unsigned char data);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

