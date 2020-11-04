/*
 * Temp_beregner.h
 *
 * Created: 03-06-2019 11:15:04
 *  Author: kenne
 */ 


#ifndef TEMP_BEREGNER_H_
#define TEMP_BEREGNER_H_

#ifdef F_CPU
#define F_CPU 16000000UL
#endif

#define DHT_PORT PORTB
#define DHT_DDR DDRB
#define DHT_PIN PINB
#define DHT_BIT PB3

#define set_bit(port, bit) (port) |= (1<<(bit))
#define clear_bit(port, bit) (port) &= ~(1<<(bit))

void Temp_beregner(void);
void DHT_Init(void);
int DHT_GetResponse(void);
void DHT_Read(int (*array)[8]);
int ConvertToDecimanl(int (*array)[8], int byte);


#endif /* TEMP_BEREGNER_H_ */