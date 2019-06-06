/*
 * Afstand.c
 *
 * Created: 04-06-2019 10:46:16
 *  Author: kenne
 */ 

#include "avr/io.h"
#define F_CPU 16E6
#include "util/delay.h"

#include "ColumnScan/ColumnScan.h"
#include "ReadRow/ReadRow.h"
#include "Afstand_display/Afstand_display.h"
#include "../Afstand/Afstand_beregner/Afstand_beregner.h"
#include "lcd/lcd.h"

unsigned int afstand_column = 1;
unsigned int afstand_row;

void Afstand()
{
	unsigned int afstand_exit = 1;	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
		
	while (afstand_exit == 1)
	{
		afstand_column = ColumnScan(afstand_column);
		afstand_row = ReadRow();
		
		if (afstand_column + afstand_row == 11)
		{
			afstand_exit = 9;
		}
		else
		{
			Afstand_beregner();
		}
	}
}
