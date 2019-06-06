/*
 * Temp_user.c
 *
 * Created: 03-06-2019 14:57:47
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
#include "../Temp_user/Temp_user_decoder/Temp_user_decoder.h"
#include "../Temp_user/Temp_user_display/Temp_user_display.h"
#include "../Menu/Menu.h"

unsigned int user_column = 1;
unsigned int user_row;

/// Temp_user giver brugen om at styrre blæseren manuelt. Brugeren vælger mellem 0-9 og blæseren vil så øge eller nedsætte hastigheden efter brugerens valg.
void Temp_user()
{
	_delay_ms(1000);
	
	unsigned int user_exit = 1;
	//lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	Temp_user_display();
	while (user_exit == 1)
	{
		user_column = ColumnScan(user_column);
		user_row = ReadRow();
		
		Temp_user_decoder(user_column, user_row);
		
		if (user_column + user_row == 11)
		{
			Menu();
			//user_exit = 2;
		}
	}
}