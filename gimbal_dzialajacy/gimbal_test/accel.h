/*
 * accel.h
 *
 * Created: 23.04.2022 13:22:45
 * Authors:
 * Michał Hasior
 * Maciek Łukaszewski
 * Damian Grzesło
 * Patryk Sądecki
 */ 


#ifndef ACCEL_H_
#define ACCEL_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "twi_master.h"

#define MPU6050_ADDR	0x68

/* MPU6050 register address */
#define ACCEL_XOUT_H	0x3B
#define ACCEL_XOUT_L	0x3C
#define ACCEL_YOUT_H	0x3D
#define ACCEL_YOUT_L	0x3E
#define ACCEL_ZOUT_H	0x3F
#define ACCEL_ZOUT_L	0x40

#define GYRO_XOUT_H		0x43

#define PWR_MGMT_1		0x6B
#define ACCEL_CONFIG	0x1C
#define GYRO_CONFIG		0x1B
#define TWO_G_SCALE			(uint8_t)0
#define FOUR_G_SCALE		(uint8_t)8 //b00001000
#define EIGTH_G_SCALE		(uint8_t)16 //0b00010000
#define SIXTEEN_G_SCALE		(uint8_t)24 //0b00011000


typedef struct
{
	int x;
	int y;
	int z;
}mpu_int_data_t;


typedef struct
{
	int x;
	int y;
	int z;
}mpu_gyro_data_t;


void ERROR_CHECK(ret_code_t error_code);
void mpu_init(void);
void mpu_get_int_accel(mpu_int_data_t*);
void mpu_get_gyro_accel(mpu_gyro_data_t*);
void mpu_set_accel_sensivity(uint8_t);
void mpu_set_gyro_sensivity();

#endif /* ACCEL_H_ */