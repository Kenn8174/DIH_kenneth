/*
 * MenuTemp.c
 *
 * Created: 29-05-2019 12:32:55
 *  Author: kenne
 */ 

#include "lcd/lcd.h"
#include "Pre_display/Pre_display.h"

/// Temp_choices viser bare hvad brugeren kan vælge imellem */
void Temp_choices(){
	
	Pre_display();

	lcd_puts("Auto: A");
	lcd_gotoxy(0,1);
	lcd_puts("User: B");
	lcd_gotoxy(15, 1);
	
}