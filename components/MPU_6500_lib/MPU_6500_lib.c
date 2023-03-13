

#include "esp_log.h"
#include "esp_err.h"
#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "MPU_6500_lib.h"
#include "MPU_6500_registers.h"
#include "MPU_6500_datas.h"

static void mpu_6500_i2c_init();
static void mpu_6500_reset_device_and_wake();
static uint8_t mpu_6500_who_am_i();
static esp_err_t read_reg(uint8_t *data, uint8_t register_addr);
static esp_err_t write_reg(uint8_t data, uint8_t register_addr);


void MPU_6500_lib_initialize()
{
    // Initialize I2C protocol
    mpu_6500_i2c_init();

    // Reset the device.

    // Wake up the device

    // Set values to "MPU_USER_CTRL_REGISTER" according to requirements.


    ESP_LOGI(MPU_TAG, "(%d, func: %s) I2C was initialized successfully.", GET_LINE, __func__);
    mpu_6500_reset_device_and_wake();
    mpu_6500_who_am_i();

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

static void mpu_6500_reset_device_and_wake()
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
}

static uint8_t mpu_6500_who_am_i()
{
    uint8_t who_am_i = 0;
    read_reg(&who_am_i, MPU_WHO_AM_I_REGISTER);
    ESP_LOGI(MPU_TAG, "(%d, func: %s) Value of WHO_AM_I_REGISTER is 0x%x", GET_LINE, __func__, who_am_i);
    return who_am_i; 
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