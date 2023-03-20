

#ifndef _MPU_6500_REGISTER_H_
#define _MPU_6500_REGISTER_H_

// The register map can be found in datasheet given below:
// https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6500-Register-Map2.pdf

// Link to the library 
// https://github.com/natanaeljr/esp32-MPU-driver


// ------------------------------ MPU gyro Offset registers ------------------------------
    /*  
        These registers holds respective offset values for gyroscope  in MPU to remove DC biad from the sensor output.
        Therefore the value in this register is added to the gyroscope sensor value before going into the sensor register. 
    */
#define MPU_X_GYRO_OFFSET_REGISTER_H        0x13    // [15:8]
#define MPU_X_GYRO_OFFSET_REGISTER_L        0x14    // [7:0]
#define MPU_Y_GYRO_OFFSET_REGISTER_H        0x15    // [15:8]
#define MPU_Y_GYRO_OFFSET_REGISTER_L        0x16    // [7:0]
#define MPU_Z_GYRO_OFFSET_REGISTER_H        0x17    // [15:8]
#define MPU_Z_GYRO_OFFSET_REGISTER_L        0x18    // [7:0]
//   MPU gyro Offset registers ******************************


// ------------------------------ MPU sample rate divider register ------------------------------
#define MPU_SMPLRT_DIV_REGISTER             0x19    // [7:0]
// ****************************** MPU sample rate divider register ******************************


// ------------------------------ MPU config registers ------------------------------
    /* "MPU_CONFIG_REGISTER"
        8-bit R/W register that configures different aspects of MPU-6500
            1. [7] -> Reserved
            2. [6] -> FIFO_MODE
            3. [5:3] -> Enables the FSYNC pin data to be sampled
            4. [2:0] -> For the DLPF to be used
    */
#define MPU_CONFIG_REGISTER                 0x1A
    /* "MPU_GYRO_CONFIG_REGISTER"
        8-bit R/W register that configures gyroscope in MPU-6500
            1. [7] -> Gyro self test at x-axis
            2. [6] -> Gyro self test at y-axis
            3. [8] -> Gyro self test at z-axis
            4. [4:3] -> Gyro Full Scale Select from (+-)2500dps to (+-)2000dps
            5. [2] -> Reserved
            6. [1:0] -> Used to bypass DLPF
    */
#define MPU_GYRO_CONFIG_REGISTER            0x1B
    /* "MPU_ACCEL_CONFIG_REGISTER"
        8-bit R/W register that configures accelerometer in MPU-6500
            1. [7] -> Acceleration self test at x-axis
            2. [6] -> Acceleration self test at y-axis
            3. [8] -> Acceleration self test at z-axis
            4. [4:3] -> Acceleration Full Scale Select from (+-)2g to (+-)16g
            5. [2:0] -> Reserved
    */
#define MPU_ACCEL_CONFIG_REGISTER           0x1C
    /* "MPU_ACCEL_CONFIG_REGISTER_2"
            Second 8-bit R/W register that configures accelerometer in MPU-6500
                1. [7:6] -> Reserved
                2. [5:4] -> Reserved
                3. [3] -> Used to bypass DLPF
                4. [2:0] -> Accelerometer low pass filter setting
    */
#define MPU_ACCEL_CONFIG_REGISTER_2         0x1D
// ****************************** MPU config registers ******************************


// ------------------------------ MPU FIFO enable register ------------------------------
    /* "MPU_FIFO_ENABLE_REGISTER"
            8-bit R/W register that configures FIFO in MPU-6500
                1. [7] -> Write TEMP_OUT_H and TEMP_OUT_L to the FIFO at the sample rate
                2. [6] -> Write GYRO_XOUT_H and GYRO_XOUT_L to the FIFO at the sample rate
                3. [5] -> Write GYRO_YOUT_H and GYRO_YOUT_L to the FIFO at the sample rate
                4. [4] -> Write GYRO_ZOUT_H and GYRO_ZOUT_L to the FIFO at the sample rate
                5. [3] -> Write ACCEL_XOUT_H, ACCEL_XOUT_L, ACCEL_YOUT_H, ACCEL_YOUT_L, ACCEL_ZOUT_H, and ACCEL_ZOUT_L to the FIFO at the sample rate
                6. [2] -> Write EXT_SENS_DATA registers associated to SLV_2 to the FIFO at the sample rate
                7. [1] -> Write EXT_SENS_DATA registers associated to SLV_1 to the FIFO at the sample rate
                8. [0] -> write EXT_SENS_DATA registers associated to SLV_0 to the FIFO at the sample rate
    */
#define MPU_FIFO_ENABLE_REGISTER            0x23
// ****************************** MPU FIFO enable register ******************************


// ------------------------------ MPU data registers ------------------------------
    // Acceleration
#define MPU_ACCEL_XOUT_REGISTER_H           0x3B 
#define MPU_ACCEL_XOUT_REGISTER_L           0x3C
#define MPU_ACCEL_YOUT_REGISTER_H           0x3D 
#define MPU_ACCEL_YOUT_REGISTER_L           0x3E 
#define MPU_ACCEL_ZOUT_REGISTER_H           0x3F 
#define MPU_ACCEL_ZOUT_REGISTER_L           0x40
    // Temperature
#define MPU_TEMP_OUT_REGISTER_H             0x41
#define MPU_TEMP_OUT_REGISTER_L             0x42
    // Gyroscope
#define MPU_GYRO_XOUT_REGISTER_H            0x43
#define MPU_GYRO_XOUT_REGISTER_L            0x44
#define MPU_GYRO_YOUT_REGISTER_H            0x45
#define MPU_GYRO_YOUT_REGISTER_L            0x46
#define MPU_GYRO_ZOUT_REGISTER_H            0x47
#define MPU_GYRO_ZOUT_REGISTER_L            0x48
// ****************************** MPU data registers ******************************


// ------------------------------ MPU signal reset register ------------------------------
    /* "MPU_SIGNAL_PATH_RESET_REGISTER"
            8-bit R/W register that resets in MPU-6500
                1. [7:3] -> Reserved
                2. [2] -> Reset gyro digital signal path
                3. [1] -> Reset accel digital signal path
                4. [0] -> Reset temp digital signal path
    */
#define MPU_SIGNAL_PATH_RESET_REGISTER      0x68
// ****************************** MPU signal reset register ******************************


// ------------------------------ MPU user control register ------------------------------
    /* "MPU_USER_CTRL_REGISTER"
            8-bit R/W register for user control in MPU-6500
                1. [7] -> '1' Enables DMP features
                2. [6] -> '1' Enables FIFO operation features
                3. [5] -> '1' Enable the I2C Master I/F module; pins ES_DA and ES_SCL are isolated from pins SDA/SDI and SCL/ SCLK.
                4. [4] -> '1' Reset I2C Slave module and put the serial interface in SPI mode only
                5. [3] -> This bit resets the DMP when set to 1 while DMP_EN equals 0
                6. [2] -> '1' Reset FIFO module
                7. [1] -> '1' Reset I2C Master module
                8. [0] -> '1' Reset all gyro digital signal path, accel digital signal path, and temp digital signal path. This bit also clears all the sensor registers.   
    */
#define MPU_USER_CTRL_REGISTER              0x6A
// ****************************** MPU user control register ******************************

// ------------------------------ MPU power management registers ------------------------------
    /* "MPU_POWER_MANGEMENT_REGISTER_1"
            8-bit R/W register that is used for power managment in MPU-6500
                1. [7] -> '1' sets chip to sleep mode
                2. [6] -> '1' Enables chip to cycle between sleep and taking samples at the given rate.
                3. [5] -> '1' When set, the gyro drive and pll circuitry are enabled, but the sense paths are disabled
                4. [4] -> '1' Disables the temperature sensor
                5. [3] -> This bit resets the DMP when set to 1 while DMP_EN equals 0
                6. [2:0] -> Selects the clock source
    */
#define MPU_POWER_MANGEMENT_REGISTER_1      0x6B
    /* "MPU_POWER_MANGEMENT_REGISTER_2"
            8-bit R/W register that is used for power managment in MPU-6500
                1. [7:6] -> Specifies the frequency of wake-ups during Accelerometer Only Low Power Mode.
                2. [5] -> '1' Disables accelerometer at x-axis.
                3. [4] -> '1' Disables accelerometer at y-axis.
                4. [3] -> '1' Disables accelerometer at z-axis.
                5. [2] -> '1' Disables gyroscope at x-axis.
                6. [1] -> '1' Disables gyroscope at y-axis.
                7. [0] -> '1' Disables gyroscope at z-axis.
    */
#define MPU_POWER_MANGEMENT_REGISTER_2      0x6C
// ****************************** MPU power management registers ******************************


// ------------------------------ MPU FIFO count registers ------------------------------
    /* These are the read only registers that indicates the number of bytes written in FIFO. Higher nibbles of "MPU_FIFO_COUNT_REGISTER_H" registers, [7:5], are reserved.*/
#define MPU_FIFO_COUNT_REGISTER_H           0x72
#define MPU_FIFO_COUNT_REGISTER_L           0x73
// ****************************** MPU FIFO count registers ******************************


// ------------------------------ MPU who am I registers ------------------------------
    /*
        This register is a read-only register used to verify the identity of the device. The contents of WHO_AM_I is an 8-bit device
        ID. The default value of the register is 0x70 for MPU-6500. This is different from the I2C address of
        the device as seen on the slave I2C controller by the applications processor. The I2C address of the
        MPU-6500 is 0x68 or 0x69 depending upon the value driven on AD0 pin.
    */
#define MPU_WHO_AM_I_REGISTER               0x75
// ------------------------------ MPU who am I registers ------------------------------


#endif    // _MPU_6500_REGISTER_H_
