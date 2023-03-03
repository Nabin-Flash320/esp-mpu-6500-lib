
#ifndef _MPU_6500_DATAS_H_
#define _MPU_6500_DATAS_H_

// ****************************** Datas for MPU_CONFIG_REGISTER ******************************
// [6]
#define MPU_CONFIG_REGISTER_FIFO_MODE_BIT_NO_ADDITIONAL_WRITE                           0x00
#define MPU_CONFIG_REGISTER_FIFO_MODE_BIT_ADDITIONAL_WRITE                              0x20
// [5:3]
#define MPU_CONFIG_REGISTER_EXT_SYNC_SET_FUNCTION_DISABLED                              0x00 
// ------------------------------ Datas for MPU_CONFIG_REGISTER ------------------------------


// ****************************** Datas for MPU_GYRO_CONFIG_REGISTER ******************************
// [7]
#define MPU_GYRO_CONFIG_REGISTER_X_AXIS_SELF_TEST_DISABLE                               0x00
#define MPU_GYRO_CONFIG_REGISTER_X_AXIS_SELF_TEST_ENABLE                                0x80
// [6]
#define MPU_GYRO_CONFIG_REGISTER_Y_AXIS_SELF_TEST_DISABLE                               0x00
#define MPU_GYRO_CONFIG_REGISTER_Y_AXIS_SELF_TEST_ENABLE                                0x40
// [5]
#define MPU_GYRO_CONFIG_REGISTER_Z_AXIS_SELF_TEST_DISABLE                               0x00
#define MPU_GYRO_CONFIG_REGISTER_Z_AXIS_SELF_TEST_ENABLE                                0x20
// [4:3]
#define MPU_GYRO_CONFIG_REGISTER_FULL_SCALE_250_DPS                                     0x00
#define MPU_GYRO_CONFIG_REGISTER_FULL_SCALE_500_DPS                                     0x08
#define MPU_GYRO_CONFIG_REGISTER_FULL_SCALE_1000_DPS                                    0x10
#define MPU_GYRO_CONFIG_REGISTER_FULL_SCALE_2000_DPS                                    0x18
// [1:0]
#define MPU_GYRO_CONFIG_REGISTER_DLPF_BYPASS                                            0x00
// ------------------------------ Datas for MPU_GYRO_CONFIG_REGISTER ------------------------------


// ****************************** Datas for MPU_ACCEL_CONFIG_REGISTER ******************************
// [7]
#define MPU_ACCEL_CONFIG_REGISTER_X_AXIS_SELF_TEST_DISABLE                              0x00
#define MPU_ACCEL_CONFIG_REGISTER_X_AXIS_SELF_TEST_ENABLE                               0x80
// [6]  
#define MPU_ACCEL_CONFIG_REGISTER_Y_AXIS_SELF_TEST_DISABLE                              0x00
#define MPU_ACCEL_CONFIG_REGISTER_Y_AXIS_SELF_TEST_ENABLE                               0x40
// [5]
#define MPU_ACCEL_CONFIG_REGISTER_Z_AXIS_SELF_TEST_DISABLE                              0x00
#define MPU_ACCEL_CONFIG_REGISTER_Z_AXIS_SELF_TEST_ENABLE                               0x20
// [4:3]
#define MPU_ACCEL_CONFIG_REGISTER_FULL_SCALE_2G                                         0x00
#define MPU_ACCEL_CONFIG_REGISTER_FULL_SCALE_4G                                         0x08
#define MPU_ACCEL_CONFIG_REGISTER_FULL_SCALE_8G                                         0x10
#define MPU_ACCEL_CONFIG_REGISTER_FULL_SCALE_16G                                        0x18
// ------------------------------ Datas for MPU_ACCEL_CONFIG_REGISTER -----------------------------


// ****************************** Datas for MPU_ACCEL_CONFIG_REGISTER_2 ******************************
// [3]
#define MPU_ACCEL_CONFIG_REGISTER_DLPF_BYPASS                                           0x00
// [2:0]
#define MPU_ACCEL_CONFIG_REGISTER_DLPF_CONFIG                                           0x00
// ------------------------------ Datas for MPU_ACCEL_CONFIG_REGISTER_2 -----------------------------


// ****************************** Datas for MPU_FIFO_ENABLE_REGISTER ******************************
// [7]
#define MPU_FIFO_ENABLE_REGISTER_TEMP_OUT_DISABLE                                       0x00
#define MPU_FIFO_ENABLE_REGISTER_TEMP_OUT_ENABLE                                        0x80
// [6]
#define MPU_FIFO_ENABLE_REGISTER_GYRO_X_OUT_DISABLE                                     0x00
#define MPU_FIFO_ENABLE_REGISTER_GYRO_X_OUT_ENABLE                                      0x40
// [5]
#define MPU_FIFO_ENABLE_REGISTER_GYRO_Y_OUT_DISABLE                                     0x00
#define MPU_FIFO_ENABLE_REGISTER_GYRO_Y_OUT_ENABLE                                      0x20
// [4]
#define MPU_FIFO_ENABLE_REGISTER_GYRO_Z_OUT_DISABLE                                     0x00
#define MPU_FIFO_ENABLE_REGISTER_GYRO_Z_OUT_ENABLE                                      0x10
// [3]
#define MPU_FIFO_ENABLE_REGISTER_ACCEL_OUT_DISABLE                                      0x00
#define MPU_FIFO_ENABLE_REGISTER_ACCEL_OUT_ENABLE                                       0x08
// ------------------------------ Datas for MPU_FIFO_ENABLE_REGISTER -----------------------------


// ****************************** Datas for MPU_SIGNAL_PATH_RESET_REGISTER ******************************
// [2]
#define MPU_SIGNAL_PATH_RESET_REGISTER_GYRO_RESET                                       0x04    
// [1]
#define MPU_SIGNAL_PATH_RESET_REGISTER_ACCEL_RESET                                      0x02            
// [0]
#define MPU_SIGNAL_PATH_RESET_REGISTER_TEMP_RESET                                       0x01
// ------------------------------ Datas for MPU_SIGNAL_PATH_RESET_REGISTER -----------------------------


// ****************************** Datas for MPU_USER_CTRL_REGISTER ******************************
// [7]
#define MPU_USER_CTRL_REGISTER_DMP_DISABLE                                              0x00
#define MPU_USER_CTRL_REGISTER_DMP_ENABLE                                               0x80
// [6]
#define MPU_USER_CTRL_REGISTER_FIFO_DISABLE                                             0x00
#define MPU_USER_CTRL_REGISTER_FIFO_ENABLE                                              0x40
// [5]
#define MPU_USER_CTRL_REGISTER_I2C_MASTER_DISABLE                                       0x00
#define MPU_USER_CTRL_REGISTER_I2C_MASTER_ENABLE                                        0x20
// [3]
#define MPU_USER_CTRL_REGISTER_DMP_RESET_DISABLE                                        0x00
#define MPU_USER_CTRL_REGISTER_DMP_RESET_ENABLE                                         0x08
// [2]
#define MPU_USER_CTRL_REGISTER_FIFO_RESET_DISABLE                                       0x00                                       
#define MPU_USER_CTRL_REGISTER_FIFO_RESET_ENABLE                                        0x04
// [1]
#define MPU_USER_CTRL_REGISTER_I2C_MASTER_RESET_DISABLE                                 0x00                                
#define MPU_USER_CTRL_REGISTER_I2C_MASTER_RESET_ENABLE                                  0x02
// ------------------------------ Datas for MPU_USER_CTRL_REGISTER -----------------------------


// ****************************** Datas for MPU_POWER_MANGEMENT_REGISTER_1 ******************************
// [7]
#define MPU_POWER_MANGEMENT_REGISTER_1_DEVICE_RESET                                     0x80
// [6]
#define MPU_POWER_MANGEMENT_REGISTER_1_DEVICE_SLEEP                                     0x40
// [5]
#define MPU_POWER_MANGEMENT_REGISTER_1_DEVICE_CYCLE                                     0x20
// [4]
#define MPU_POWER_MANGEMENT_REGISTER_1_GYRO_STANDBY                                     0x10
// [3]
#define MPU_POWER_MANGEMENT_REGISTER_1_TEMPERATURE_DISABLE                              0x08
#define MPU_POWER_MANGEMENT_REGISTER_1_TEMPERATURE_ENABLE                               0x00
// [2:0]
#define MPU_POWER_MANGEMENT_REGISTER_1_SELECT_INTERNAL_OSCILLATOR                       0x00
#define MPU_POWER_MANGEMENT_REGISTER_1_SELECT_BEST_CLOCK_SOURCE                         0x10
#define MPU_POWER_MANGEMENT_REGISTER_1_STOPO_CLOCK_AND_RESET_TIMING_GENERATOR           0x10
// ------------------------------ Datas for MPU_POWER_MANGEMENT_REGISTER_1 -----------------------------


// ****************************** Datas for MPU_POWER_MANGEMENT_REGISTER_2 ******************************
// [7:6]
#define MPU_POWER_MANGEMENT_REGISTER_2_LOW_POWER_WAKEUP_FREQUENCY_1_25_HZ               0x00
#define MPU_POWER_MANGEMENT_REGISTER_2_LOW_POWER_WAKEUP_FREQUENCY_5_HZ                  0x40
#define MPU_POWER_MANGEMENT_REGISTER_2_LOW_POWER_WAKEUP_FREQUENCY_20_HZ                 0x80
#define MPU_POWER_MANGEMENT_REGISTER_2_LOW_POWER_WAKEUP_FREQUENCY_40_HZ                 0xC0
// [5]
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_X_AXIS_DISABLE                             0x20
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_X_AXIS_ENABLE                              0x00
// [4]
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_Y_AXIX_DISABLE                             0x10
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_Y_AXIX_ENABLE                              0x00
// [3]
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_Z_AXIX_DISABLE                             0x08
#define MPU_POWER_MANGEMENT_REGISTER_2_ACCEL_Z_AXIX_ENABLE                              0x00
// [2]
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_X_AXIS_DISABLE                              0x04
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_X_AXIS_ENABLE                               0x00
// [1]
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_Y_AXIX_DISABLE                              0x02
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_Y_AXIX_ENABLE                               0x00
// [0]
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_Z_AXIX_DISABLE                              0x01
#define MPU_POWER_MANGEMENT_REGISTER_2_GYRO_Z_AXIX_ENABLE                               0x00
// ------------------------------ Datas for MPU_POWER_MANGEMENT_REGISTER_2 -----------------------------

#endif //_MPU_6500_DATAS_H_

