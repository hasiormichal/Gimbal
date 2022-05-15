/*
 * servo.h
 *
 * Created: 23.04.2022 13:09:44
 * Authors:
 * Michał Hasior
 * Maciek Łukaszewski
 * Damian Grzesło
 * Patryk Sądecki
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_TOP (39999u)
#define SEVRO_MIN (999u)
#define SEVRO_MAX  (4999u)
#define samples_num 16

#include "accel.h"
typedef struct
{
	int index;
	int value;
}Servo;


void calculate_servo_value(Servo* ,Servo*,Servo*,float, float, float);
void servo328PB_init();
void servo_update(int,int,int);



#endif /* SERVO_H_ */