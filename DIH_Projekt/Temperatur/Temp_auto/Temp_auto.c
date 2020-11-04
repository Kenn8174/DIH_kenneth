/*
 * Temp_auto.c
 *
 * Created: 03-06-2019 11:04:42
 *  Author: kenne
 */ 

#define F_CPU 16E6
#include <util/delay.h>
#include <stdlib.h>
#include "stdio_setup.h"
#include <avr/io.h>

#include "lcd/lcd.h"
#include "ColumnScan/ColumnScan.h"
#include "ReadRow/ReadRow.h"
#include "Temp_beregner/Temp_beregner.h"
#include "Pre_display/Pre_display.h"
#include "../Menu/Menu.h"

unsigned int temo_column = 1;
unsigned int temp_row;


///Temp_auto kører rundt i loop indtil brugeren holder stjernen i bund. På samme tid bliver temperaturen beregnet og sætter blæserens hastighed op eller ned.
void Temp_auto()
{
	unsigned int temp_ex = 1;
	//lcd_init(LCD_DISP_ON_CURSOR_BLINK);	
	
	while (temp_ex == 1)
	{
		temo_column = ColumnScan(temo_column);
		temp_row = ReadRow();
		
		
		if (temo_column + temp_row == 11)
		{
			Menu();
			//temp_ex = 9;
		}
		
		Temp_beregner();  //SKAL IKKE BRUGES! BRUG DE ANDRE METHODER!
						
	}
}