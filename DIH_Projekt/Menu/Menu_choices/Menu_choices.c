/*
 * MenuChoice.c
 *
 * Created: 29-05-2019 10:44:20
 *  Author: kenne
 */ 

#include "lcd/lcd.h"
#include "Pre_display/Pre_display.h"

/// Menu_choise viser valg mulighederne på displayet
void Menu_choices(){
	
	Pre_display();
	
	lcd_puts("Distance");
	lcd_gotoxy(10,0);
	lcd_puts(": A\n");
	lcd_puts("Temperatur: B");
	lcd_gotoxy(15, 1);
	
}