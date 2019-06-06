/*
 * Afstand_display.c
 *
 * Created: 04-06-2019 11:26:49
 *  Author: kenne
 */ 

#include <stdlib.h>
#include "stdio_setup.h"
#include <avr/io.h>

#include "lcd/lcd.h"

void Afstand_display(float distance)
{
	lcd_clrscr();
	
	char buffer[4];
	
	if (distance < 20)
	{
		lcd_puts("STOP");
	}
	else
	{		
		sprintf(buffer, "%0.2f C", distance);		
		lcd_puts(buffer);
		lcd_gotoxy(5, 0);
		lcd_puts("cm");
	}
}