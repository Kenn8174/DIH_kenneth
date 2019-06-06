/*
 * Temp_user_display.c
 *
 * Created: 05-06-2019 14:37:46
 *  Author: kenne
 */ 

#include <stdlib.h>
#include "stdio_setup.h"
#include <avr/io.h>

#include "Pre_display/Pre_display.h"
#include "lcd/lcd.h"

///Display til Temp_user.
void Temp_user_display(float TempC)
{		
	Pre_display();
	
	lcd_puts("Vælg mellem 0-9");
	lcd_gotoxy(0,1);
}