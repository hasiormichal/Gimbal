/*
 * servo.c
 *
 * Created: 23.04.2022 13:09:04
  * Authors:
  * Michał Hasior
  * Maciek Łukaszewski
  * Damian Grzesło
  * Patryk Sądecki
 */ 
#include "servo.h"
#include <math.h>

#include <avr/sfr_defs.h>

	extern uint8_t samples;
	extern int x_sum, y_sum, z_sum;
	extern int x, y, z;



void calculate_servo_value(Servo* servo0,Servo* servo1,Servo* servo2,float yaw, float roll, float pitch)
{
	float newyaw = yaw *1273 + 999;
	pitch = pitch*1273 + 999;
	roll =roll*1273 + 999;
	servo0->value = newyaw;
	
}


void servo328PB_init()
{
	DDRB = 0x6;
	DDRD = 0x1;
	// PB1, PB2, PD0


	//TCCR1A = COM1A1, COM1B1, WGM11 - wysokie
	TCCR1A = 0xA2;
	//TCCR1B = WGM12, WGM13 - wysokie
	//TCCR1B = CS11 - prescale /8
	TCCR1B = 0x1A;
	//fast PWM
	//similar setup for other
	// we don't need OCR2B
	TCCR3A = 0x82;
	TCCR3B = 0x1A;

	ICR1 = PWM_TOP;
	ICR3 = PWM_TOP;

	// initial setup servos
	OCR1A = 2999u;
	OCR1B = 2999u;
	OCR3A = 2999u;

}

void servo_update(int servo0,int servo1,int servo2){
	OCR1A = servo0;
	OCR1B = servo1;
	OCR3A = servo2;     // return x,y,z
}
