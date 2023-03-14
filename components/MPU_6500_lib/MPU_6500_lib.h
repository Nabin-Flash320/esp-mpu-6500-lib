
#ifndef _MPU_6500_LIB_H_
#define _MPU_6500_LIB_H_

#define MPU_TAG         __FILE__
#define GET_LINE        __LINE__

#define MPU_6500_ADDRESS_0      0x68
#define MPU_6500_ADDRESS_1      0x69

#define ACK_CHECK_EN            0x1

#define MPU_6500_SDA_IO_NUM     (2)
#define MPU_6500_SCL_IO_NUM     (3)
#define MPU_6500_I2C_NUM        I2C_NUM_0



void MPU_6500_lib_initialize();

#endif //_MPU_6500_LIB_H_
