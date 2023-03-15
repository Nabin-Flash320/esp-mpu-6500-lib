

#include "MPU_6500_lib.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define MAIN_TAG __FILE__

static void accelerometer(void* params);
static void gyroscope(void* params);

void app_main()
{
   MPU_6500_lib_initialize();
   xTaskCreate(accelerometer, "accelerometer", 2*2048, NULL, 1, NULL);
   // xTaskCreate(gyroscope, "gyroscope", 2*2048, NULL, 1, NULL);
}

static void accelerometer(void* params)
{
   while(1)
   {
      accel_data_t* accel_data = get_accelerometer_data();
      double accel_x_data = ((accel_data->accel_x_data.register_h_data << 8) | accel_data->accel_x_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      double accel_y_data = ((accel_data->accel_y_data.register_h_data << 8) | accel_data->accel_y_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      double accel_z_data = ((accel_data->accel_z_data.register_h_data << 8) | accel_data->accel_z_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      // ESP_LOGI(MAIN_TAG, "(%d, func: %s) {X, Y, Z} = {%f, %f, %f}", GET_LINE, __func__, (accel_x_data), (accel_y_data), (accel_z_data));
      printf("{%f, %f, %f}\n", accel_x_data, accel_y_data, accel_z_data);
      vTaskDelay(50 / portTICK_PERIOD_MS);
   }
}

static void gyroscope(void* params)
{
   while(1)
   {
      gyro_data_t* gyro_data = get_gyroscope_data();
      uint16_t gyro_x_data = (gyro_data->gyro_x_data.register_h_data << 8) | gyro_data->gyro_x_data.register_l_data;
      uint16_t gyro_y_data = (gyro_data->gyro_y_data.register_h_data << 8) | gyro_data->gyro_y_data.register_l_data;
      uint16_t gyro_z_data = (gyro_data->gyro_z_data.register_h_data << 8) | gyro_data->gyro_z_data.register_l_data;
      ESP_LOGI(MAIN_TAG, "(%d, func: %s) {X, Y, Z} = {%d, %d, %d}\n", GET_LINE, __func__, gyro_x_data, gyro_y_data, gyro_z_data);
      vTaskDelay(1500 / portTICK_PERIOD_MS);
   }
}
