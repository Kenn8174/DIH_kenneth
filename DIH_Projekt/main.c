
#include "Menu/Menu.h"
#include "Init/Init.h"
#define F_CPU 16E6
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd/lcd.h"

///Main gør ikke det store end at køre Menu() i loop. Menuen kunne rent teoretisk også ligge her i main.
int main(void)
{
	//UartInit();
	Init();
	

	//while(1) {
		Menu();
	//}
}