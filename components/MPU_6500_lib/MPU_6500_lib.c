

#include "esp_log.h"
#include "esp_err.h"
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "MPU_6500_lib.h"
#include "MPU_6500_registers.h"
#include "MPU_6500_datas.h"

static void mpu_6500_i2c_init();
static uint8_t mpu_6500_who_am_i();
// ---------------- MPU 6500 configs ----------------
static esp_err_t mpu_6500_reset_device_and_wake();
static esp_err_t mpu_6500_select_clock_source(uint8_t clock_source);
static esp_err_t mpu_6500_set_gyro_full_scale(uint8_t full_scale);
static esp_err_t mpu_6500_set_accel_full_scale(uint8_t full_scale);
static esp_err_t mpu_6500_set_dlpf_config(uint8_t dlpf_config);
static esp_err_t mpu_6500_set_sample_divider(uint8_t sample_divider);
// **************************************************
static esp_err_t read_reg(uint8_t *data, uint8_t register_addr);
static esp_err_t write_reg(uint8_t data, uint8_t register_addr);


void MPU_6500_lib_initialize()
{
    // Initialize I2C protocol
    mpu_6500_i2c_init();
    ESP_LOGI(MPU_TAG, "(%d, func: %s) I2C was initialized successfully.\n", GET_LINE, __func__);

    ESP_LOGE(MPU_TAG, "---------------- MPU 6500 configs ----------------");
    mpu_6500_reset_device_and_wake();
    mpu_6500_select_clock_source(MPU_POWER_MANGEMENT_REGISTER_1_SELECT_BEST_CLOCK_SOURCE);
    mpu_6500_set_gyro_full_scale(MPU_GYRO_CONFIG_REGISTER_FULL_SCALE_500_DPS);
    mpu_6500_set_accel_full_scale(MPU_ACCEL_CONFIG_REGISTER_FULL_SCALE_4G);
    mpu_6500_set_dlpf_config(MPU_CONFIG_REGISTER_DLPF_CONFIG_41_HZ);
    mpu_6500_set_sample_divider(100);
    ESP_LOGE(MPU_TAG, "**************************************************\n");

    // Checking the identity of the device.
    uint8_t identity = mpu_6500_who_am_i();
    ESP_LOGI(MPU_TAG, "(%d, func: %s) Value of WHO_AM_I_REGISTER is 0x%x", GET_LINE, __func__, identity);
}

static void mpu_6500_i2c_init()
{
    esp_err_t error = ESP_OK;
    const i2c_config_t mpu_6500_init_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = MPU_6500_SDA_IO_NUM,
        .scl_io_num = MPU_6500_SCL_IO_NUM,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000
    };

    error = i2c_param_config(MPU_6500_I2C_NUM, &mpu_6500_init_config);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d)Error confugring I2C params.(code:%s)", GET_LINE, esp_err_to_name(error));
    }
    else
    {
        ESP_LOGI(MPU_TAG, "(%d)I2C params confiugred successfully!", GET_LINE);
    }
    
    error = i2c_driver_install(MPU_6500_I2C_NUM, I2C_MODE_MASTER, 0, 0, 0);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d)Error installing I2C driver.(code:%s)", GET_LINE, esp_err_to_name(error));
    }
    else
    {
        ESP_LOGI(MPU_TAG, "(%d)I2C driver installed successfully!", GET_LINE);
    }

}

static esp_err_t mpu_6500_reset_device_and_wake()
{
    // Resetting device by setting bit 7 of the power managment 1 register.
    esp_err_t error = write_reg(MPU_POWER_MANGEMENT_REGISTER_1_DEVICE_RESET, MPU_POWER_MANGEMENT_REGISTER_1);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't reset the register.", GET_LINE, __func__);
    }
    else 
    {
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Register reset successfully.", GET_LINE, __func__);
    }

    // Awake the device by resetting power management 1 register.
    error = write_reg(MPU_POWER_MANGEMENT_REGISTER_1_DEVICE_WAKE, MPU_POWER_MANGEMENT_REGISTER_1);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't wake the device.", GET_LINE, __func__);
    }
    else 
    {
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Device awakened successfully.", GET_LINE, __func__);
    }
    return error;
}

static esp_err_t mpu_6500_select_clock_source(uint8_t clock_source)
{
    esp_err_t error = ESP_OK;

    error = write_reg(clock_source, MPU_POWER_MANGEMENT_REGISTER_1);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't select clock source.", GET_LINE, __func__);
    }
    else 
    {
        uint8_t clock = 0;
        error = read_reg(&clock, MPU_POWER_MANGEMENT_REGISTER_1);
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Clock setting is 0x%x", GET_LINE, __func__, (0x0F & clock));
    }
    return error;
}

static esp_err_t mpu_6500_set_gyro_full_scale(uint8_t full_scale)
{
    esp_err_t error = ESP_OK;
    error = write_reg(full_scale, MPU_GYRO_CONFIG_REGISTER);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't configure gyro full scale.", GET_LINE, __func__);
    }
    else 
    {
        uint8_t gyro_full_scale = 0;
        error = read_reg(&gyro_full_scale, MPU_GYRO_CONFIG_REGISTER);
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Gyro full scale setting is 0x%x", GET_LINE, __func__, (0x18 & gyro_full_scale));
    }
    return error;
}

static esp_err_t mpu_6500_set_accel_full_scale(uint8_t full_scale)
{
    esp_err_t error = ESP_OK;
    error = write_reg(full_scale, MPU_ACCEL_CONFIG_REGISTER);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't configure acceleration full scale.", GET_LINE, __func__);
    }
    else 
    {
        uint8_t accel_full_scale = 0;
        error = read_reg(&accel_full_scale, MPU_ACCEL_CONFIG_REGISTER);
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Accelerometer full scale setting is 0x%x", GET_LINE, __func__, (0x18 & accel_full_scale));
    }
    return error;
}

static esp_err_t mpu_6500_set_dlpf_config(uint8_t dlpf_config)
{
    esp_err_t error = ESP_OK;
    error = write_reg(dlpf_config, MPU_CONFIG_REGISTER);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't configure DLPF.", GET_LINE, __func__);
    }
    else 
    {
        uint8_t dlpf_config = 0;
        error = read_reg(&dlpf_config, MPU_CONFIG_REGISTER);
        ESP_LOGI(MPU_TAG, "(%d, func: %s) DLPF setting is 0x%x", GET_LINE, __func__, (0x07 & dlpf_config));
    }
    return error;
}

static esp_err_t mpu_6500_set_sample_divider(uint8_t sampling_rate)
{
    esp_err_t error = ESP_OK;
    uint16_t mpu_6500_internal_sampling_rate = 1000;
    uint16_t mpu_6500_divider_value = (mpu_6500_internal_sampling_rate / sampling_rate) - 1;
    error = write_reg((uint8_t)mpu_6500_divider_value, MPU_SMPLRT_DIV_REGISTER);
    if(ESP_OK != error)
    {
        ESP_LOGE(MPU_TAG, "(%d, func: %s) Couldn't write to the sample rate divider register.", GET_LINE, __func__);
    }
    else 
    {
        ESP_LOGI(MPU_TAG, "(%d, func: %s) Sampling rate is %d and the divider value %d", GET_LINE, __func__, sampling_rate, mpu_6500_divider_value);
    }
    return error;
}

static uint8_t mpu_6500_who_am_i()
{
    uint8_t identity = 0;
    read_reg(&identity, MPU_WHO_AM_I_REGISTER);
    return identity; 
}

static esp_err_t write_reg(uint8_t data, uint8_t register_addr)
{
    esp_err_t error = ESP_OK;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_start(cmd));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, (MPU_6500_ADDRESS_0 << 1) | I2C_MASTER_WRITE, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, register_addr, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, data, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_stop(cmd));
    i2c_master_cmd_begin(MPU_6500_I2C_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return error;
}

static esp_err_t read_reg(uint8_t *data, uint8_t register_addr)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_start(cmd));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, (MPU_6500_ADDRESS_0 << 1) | I2C_MASTER_WRITE, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, register_addr, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_start(cmd));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_write_byte(cmd, (MPU_6500_ADDRESS_0 << 1) | I2C_MASTER_READ, ACK_CHECK_EN));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_read_byte(cmd, data, I2C_MASTER_NACK));
    ESP_ERROR_CHECK_WITHOUT_ABORT(i2c_master_stop(cmd));
    i2c_master_cmd_begin(MPU_6500_I2C_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ESP_OK;
}