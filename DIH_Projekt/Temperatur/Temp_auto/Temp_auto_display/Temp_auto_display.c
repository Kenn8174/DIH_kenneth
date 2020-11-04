/*
 * Temp_auto_display.c
 *
 * Created: 04-06-2019 09:18:01
 *  Author: kenne
 */ 


#include <stdlib.h>
#include <stdio.h>
#include "stdio_setup.h"
#include <avr/io.h>
#include "../Temp_beregner/Temp_beregner.h"
#include "lcd/lcd.h"

///Display til Temp_auto. Viser Temperaturen.
void Temp_auto_display(float TempC)
{
	char buffer[4];
	
	DHT_Init();
	int array[5][8];
	if (DHT_GetResponse())
	{
		DHT_Read(array);
		
		lcd_clrscr();
		lcd_puts("Temp: ");
		lcd_gotoxy(8,0);
		//sprintf(buffer, "%0.2f C", TempC);
		sprintf(buffer, "%0.2f C", ConvertToDecimanl(array, 3));
		lcd_puts(buffer);
	}
}