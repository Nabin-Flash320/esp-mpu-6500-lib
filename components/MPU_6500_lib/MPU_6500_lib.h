
#ifndef _MPU_6500_LIB_H_
#define _MPU_6500_LIB_H_

#include "stdint.h"

#define MPU_TAG         __FILE__
#define GET_LINE        __LINE__

#define MPU_6500_ADDRESS_0      0x68
#define MPU_6500_ADDRESS_1      0x69

#define ACK_CHECK_EN            0x1

#define MPU_6500_SDA_IO_NUM     (2)
#define MPU_6500_SCL_IO_NUM     (3)
#define MPU_6500_I2C_NUM        I2C_NUM_0

#define MPU_6500_ACCEL_2G_FULL_SCALE_RESOLUTION         0.000061 // 0.000061g/LSB
#define MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION         0.000122 // 0.000122g/LSB
#define MPU_6500_ACCEL_8G_FULL_SCALE_RESOLUTION         0.000244 // 0.000244g/LSB
#define MPU_6500_ACCEL_16G_FULL_SCALE_RESOLUTION        0.000488 // 0.000488g/LSB

typedef struct{
    uint8_t register_h_data;
    uint8_t register_l_data;
}register_data_t;

typedef struct{
    register_data_t accel_x_data;
    register_data_t accel_y_data;
    register_data_t accel_z_data;
}accel_data_t;

typedef struct{
    register_data_t gyro_x_data;
    register_data_t gyro_y_data;
    register_data_t gyro_z_data;
}gyro_data_t;


void MPU_6500_lib_initialize();
accel_data_t* get_accelerometer_data();
gyro_data_t* get_gyroscope_data();


#endif //_MPU_6500_LIB_H_
