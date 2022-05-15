/*
 * accel.c
 *
 * Created: 23.04.2022 13:22:53
 * Authors:
 * Michał Hasior
 * Maciek Łukaszewski
 * Damian Grzesło
 * Patryk Sądecki
 */ 
#include "accel.h"
#include "twi_master.h"

extern ret_code_t error_code;

void ERROR_CHECK(ret_code_t error_code)
{
	if (error_code != SUCCESS)
	{
		/* error code and loop indefinitely until reset */
		while (1); // loop indefinitely
	}
}


void mpu_init(void)
{
	uint8_t data[2] = {PWR_MGMT_1, 0};
	error_code = tw_master_transmit(MPU6050_ADDR, data, sizeof(data), false);
	ERROR_CHECK(error_code);
}

void mpu_get_int_accel(mpu_int_data_t* mpu_data){
		ret_code_t error_code;
		/* 2 registers for each of accel x, y and z data */
		uint8_t data[6];
		
		data[0] = ACCEL_XOUT_H;
		error_code = tw_master_transmit(MPU6050_ADDR, data, 1, true);
		ERROR_CHECK(error_code);
		
		error_code = tw_master_receive(MPU6050_ADDR, data, sizeof(data));
		ERROR_CHECK(error_code);
		
		/* Default accel config +/- 2g */
		mpu_data->x = (int16_t)(data[0] << 8 | data[1]);
		mpu_data->y = (int16_t)(data[2] << 8 | data[3]);
		mpu_data->z = (int16_t)(data[4] << 8 | data[5]);

}

void mpu_get_gyro_accel(mpu_gyro_data_t* mpu_data){
		ret_code_t error_code;
		/* 2 registers for each of gyro x, y and z data */
		uint8_t data[6];
		
		data[0] = GYRO_XOUT_H;
		error_code = tw_master_transmit(MPU6050_ADDR, data, 1, true);
		ERROR_CHECK(error_code);
		
		error_code = tw_master_receive(MPU6050_ADDR, data, sizeof(data));
		ERROR_CHECK(error_code);
		
		/* Default gyro config */
		mpu_data->x = (int16_t)(data[0] << 8 | data[1]);
		mpu_data->y = (int16_t)(data[2] << 8 | data[3]);
		mpu_data->z = (int16_t)(data[4] << 8 | data[5]);

}

void mpu_set_accel_sensivity(uint8_t sensivity){
	ret_code_t error_code;
	
	uint8_t wsk[2] = {ACCEL_CONFIG,sensivity}; 
	error_code =  tw_master_transmit(MPU6050_ADDR, wsk, 2, true);
	ERROR_CHECK(error_code);

}
void mpu_set_gyro_sensivity(){
	ret_code_t error_code;
	
	uint8_t wsk[2] = {GYRO_CONFIG,0x00}; 
	error_code =  tw_master_transmit(MPU6050_ADDR,wsk , 2, true);
	ERROR_CHECK(error_code);
}