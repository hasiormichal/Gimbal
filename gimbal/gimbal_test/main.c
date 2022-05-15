/*
 * main.c
 *
 * Created: 4/2/2022 4:29:18 PM
 * Authors:
 * Michał Hasior
 * Maciek Łukaszewski
 * Damian Grzesło
 * Patryk Sądecki
 */ 


#define F_CPU 16000000UL
//#define FOUR_G_SCALE
//#define EIGTH_G_SCALE
//#define SIXTEEN_G_SCALE

#include <xc.h>
#include "twi_master.h"
#include "uart.h"
#include "servo.h"
#include "accel.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>
#define ERROR_ACCEL_X -0.8098
#define ERROR_ACCEL_Y 2.0055
#define ERROR_GYRO_X 1.59
#define ERROR_GYRO_Y 174.5891
#define ERROR_GYRO_Z 1.43
#define START_VALUE_1 3009
#define START_VALUE_3 2930
#define START_VALUE_2 3200

// --------- global inicjalizations -----------
	ret_code_t error_code;

	volatile uint16_t milis; 
	uint8_t samples = 0;
	int x_sum, y_sum, z_sum;
	int x, y, z;
	Servo servo0;
	Servo servo1;
	Servo servo2;

	float Xangle;
	float Yangle;
	float Zangle;
	
	float gyroAngleX;
	float gyroAngleY;
	float gyroAngleZ;
	
	float yaw = 0;
	float roll = 0;
	float pitch = 0;
	
	float yawOld = 0;
	float rollOld = 0;
	float pitchOld = 0;
	
	mpu_int_data_t int_accel_new;
	mpu_int_data_t int_accel_test;
	mpu_gyro_data_t int_gyro;
	mpu_gyro_data_t int_gyro_test;
	float elepsedTime;
//------------- END global inicjalizations -------------------


int main(void)
{	 
	// --------- timer 0 init
	TCCR0A  = 0x00; //normal mode
	OCR0A = 25;
	TCNT0   = 0x00;
	TIMSK0 |= 0x02;
	TCCR0B = (1<<CS01) | (1<<CS00); // preskaler 64 and start clock
	
	//TCCR0A  = 0x02; //ctc mode  10us
    //OCR0A = 20;
    //TCNT0   = 0x00;
    //TIMSK0 |= 0x02;
    //TCCR0B = (1<<CS01); //| (1<<CS00); // preskaler 8 and start clock
	/* Initialize project configuration */
	
	
	tw_init(TW_FREQ_400K, true); // set I2C Frequency, enable internal pull-up
	mpu_init();
	mpu_set_accel_sensivity(EIGTH_G_SCALE);
	servo328PB_init();
	mpu_set_gyro_sensivity();
	// ---------- init variable --------------
	
		    servo0.index = 0;
		    servo0.value = START_VALUE_1;
		    servo1.index = 1;
		    servo1.value = START_VALUE_2;
		    servo2.index = 2;
		    servo2.value = START_VALUE_3;

		milis = 0;
		TCNT0   = 0x00;
		sei();
		
		/*	error calculation - only once 
		float gx =0;
		float gy =0;
		float gz =0;

		float ax =0;
		float ay =0;
		float az =0;
		float anglex =0;
		float angley =0;

		for(int k = 0;k<1000;k++){
			mpu_get_int_accel(&int_accel_test);
			
			ax = int_accel_test.x;
			ay = int_accel_test.y;
			az = int_accel_test.z;
			anglex += (atan(ay / sqrt(pow(az,2)+pow(ax,2))) * 180/M_PI)  ;
			angley += ((-1)*atan(ax / sqrt(pow(az,2)+pow(ay,2))) * 180/M_PI) ;
	}
		volatile float ERROR_AX = anglex/1000;
		volatile float ERROR_AY = angley/1000;
		float gx_er = 0;
		float gy_er = 0;
		float gz_er = 0;
	for(int k = 0;k<1000;k++){
		mpu_get_gyro_accel(&int_gyro_test);
		
		gx = int_gyro_test.x;
		gy = int_gyro_test.y;
		gz = int_gyro_test.z;
		gx_er += gx/131;
		gy_er += gy/131;
		gz_er += gz/131;
	}
	volatile float ERROR_GX = gx_er/1000;
	volatile float ERROR_GY = gy_er/1000;
	volatile float ERROR_Gz = gz_er/1000;*/

	while (1){
		mpu_get_int_accel(&int_accel_new);
		
		float Xaccel = (float)int_accel_new.x / 4966;
		float Yaccel = (float)int_accel_new.y / 4966;
		float Zaccel = (float)int_accel_new.z / 4966;
		
		
		Xangle = (atan(Yaccel / sqrt(pow(Zaccel,2)+pow(Xaccel,2))) * 180/M_PI) + ERROR_ACCEL_X ;
		Yangle = ((-1)*atan(Xaccel / sqrt(pow(Zaccel,2)+pow(Yaccel,2))) * 180/M_PI) + ERROR_ACCEL_Y;
		
		mpu_get_gyro_accel(&int_gyro);
		elepsedTime = (float)milis/10000; //in seconds
		milis = 0;
		
		float Xgyro = (float)int_gyro.x /131 + ERROR_GYRO_X;
		float Ygyro = ((float)int_gyro.y +ERROR_GYRO_Y) /131 ;
		float Zgyro = (float)int_gyro.z / 131  + ERROR_GYRO_Z ;

		gyroAngleX = gyroAngleX + Xgyro*elepsedTime;
		gyroAngleY = gyroAngleY + Ygyro*elepsedTime;
		gyroAngleZ = gyroAngleZ + Zgyro*elepsedTime;
		yaw = yaw + Zgyro*elepsedTime;					// 90 -> +8 -90 -> -8
		roll = 0.97*gyroAngleX + 0.03*Xangle;			//90 -> +12 -90 -> -12
		pitch = 0.97*gyroAngleY + 0.03*Yangle;			//90 -> +12 -90 -> -12

		//calculate_servo_value(&servo0, &servo1, &servo2,yaw,roll,pitch);
		//yawOld = sqrt((pow(yaw,2) + pow(yawOld,2))/2);
		//rollOld = sqrt((pow(roll,2) + pow(rollOld,2))/2);
		//pitchOld = sqrt((pow(pitch,2) + pow(pitchOld,2))/2);
		servo0.value = (int)(yaw*1000/4  + START_VALUE_1 ) ;			//2000 na 90 stopni -> 90 stopni = 8(gyro) * 1000 = 8000(chcemy inta) -> 8000/4 = 2000 ->>>>OK DZIALA
		servo1.value = (int)(- pitch*1000/6 + START_VALUE_2);			//2000 na 90 stopni -> 90 stopni = 12* 1000 = 12000(chcemy inta) -> 8000/6 = 2000 ->>>>OK DZIALA
		servo2.value = (int)( roll*1000/6 + START_VALUE_3);				//2000 na 90 stopni -> 90 stopni = 12* 1000 = 12000(chcemy inta) -> 8000/6 = 2000 ->>>>
		
		if( servo0.value >= 4400)
			servo0.value = 4400;
		if( servo0.value <= 1500)
			servo0.value = 1500;
		if( servo1.value >= 4400)
			servo1.value = 4400;
		if( servo1.value <= 2000)
			servo1.value = 2000;
		if( servo2.value >= 4400)
			servo2.value = 4400;
		if( servo2.value <= 1500)
			servo2.value = 1500;
		
		
		//================== PID -===================
		
		int integral0 = 0;
		int integral1 = 0;
		int integral2 = 0;
		
		for(int i=0; i<50; i++){
			int curentposition0 = OCR1A;
			int curentposition1 = OCR1B;
			int curentposition2 = OCR3A;
			
			int error0 = servo0.value - curentposition0;
			int error1 = servo1.value - curentposition1;
			int error2 = servo2.value - curentposition2;
			
			integral0 += error0;
			integral1 += error1;
			integral2 += error2;
			
			curentposition0 += error0*0.3 + integral0*0.01;
			curentposition1 += error1*0.3 + integral1*0.01;
			curentposition2 += error2*0.3 + integral2*0.01;
			
			servo_update(curentposition0,curentposition1,curentposition2);
		}
		// ===================== pid end ==================

		
		

	}
}


ISR(TIMER0_COMPA_vect) //call interruption
{
	milis++;
}


