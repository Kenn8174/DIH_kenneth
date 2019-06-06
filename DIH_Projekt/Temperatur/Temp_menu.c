/*
 * Temperature.c
 *
 * Created: 29-05-2019 12:20:23
 *  Author: kenne
 */ 

#define F_CPU 16E6
#include <util/delay.h>
#include <stdlib.h>
#include "stdio_setup.h"
#include <avr/io.h>
#include "ColumnScan/ColumnScan.h"
#include "ReadRow/ReadRow.h"
#include "Temp_decoder/Temp_decoder.h"
#include "Temp_choices/Temp_choices.h"
#include "../Menu/Menu.h"


///Menuen til Temperatur, hvor brugeren kan vælge imelle auto og user.
/** Temp_menu er menuen til temperatur, her har brugeren mulighed for at vælge imellem Auto eller User. 
Auto vil læse temperaturen i rummet og justere blæseren hastighed.
User giver brugeren mulighed for selv at justere blæsrens hastighed. */
void Temp_menu(){
	
	_delay_ms(1000);
	
	unsigned int columnTemp = 1;
	unsigned int rowTemp = 90;
	
	unsigned int ex = 1;
	
	Temp_choices();
	
	while (ex == 1)
	{
		_delay_ms(25);
		
		columnTemp = ColumnScan(columnTemp);
		rowTemp = ReadRow();
		
		if (columnTemp + rowTemp == 11)
		{
			Menu();
			//ex = 9;
		}
					
		Temp_decoder(columnTemp, rowTemp);	
		
	}
}