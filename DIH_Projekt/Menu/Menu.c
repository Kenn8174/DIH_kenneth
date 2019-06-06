/*
 * Menu.c
 *
 * Created: 29-05-2019 09:02:46
 *  Author: kenneth
 */ 

#define F_CPU 16E6
#include <util/delay.h>
#include <stdlib.h>
#include "stdio_setup.h"
#include <avr/io.h>
#include "ColumnScan/ColumnScan.h"
#include "ReadRow/ReadRow.h"
#include "Menu_choices/Menu_choices.h"
//unsigned int x = 1;


/// Menuen er det første som bliver vist på displayed, her har brugeren mulighed for at vælge imellem (Afstand) og (Temperatur).
void Menu(){
		
	_delay_ms(1000);
	
	unsigned int column = 1;
	unsigned int row = 90;
	
	Menu_choices();
	
	while (1)
	{		
		
		column = ColumnScan(column);
		row = ReadRow();
		
		Menu_decoder(column, row);
		
		_delay_ms(25);
	}
	
}