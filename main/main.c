

#include "MPU_6500_lib.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define MAIN_TAG __FILE__

static void accelerometer(void *params);
static void gyroscope(void *params);

void app_main()
{
   MPU_6500_lib_initialize();
   mpu_6500_who_am_i();
   xTaskCreate(accelerometer, "accelerometer", 2*2048, NULL, 1, NULL);
   // xTaskCreate(gyroscope, "gyroscope", 2 * 2048, NULL, 1, NULL);
}

static void accelerometer(void *params)
{
   while (1)
   {
      accel_data_t *accel_data = get_accelerometer_data();
      double accel_x_data = ((accel_data->accel_x_data.register_h_data << 8) | accel_data->accel_x_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      double accel_y_data = ((accel_data->accel_y_data.register_h_data << 8) | accel_data->accel_y_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      double accel_z_data = ((accel_data->accel_z_data.register_h_data << 8) | accel_data->accel_z_data.register_l_data) * MPU_6500_ACCEL_4G_FULL_SCALE_RESOLUTION;
      printf("Accelerations: { %f, %f, %f }\n", accel_x_data, accel_y_data, accel_z_data);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
}

static void gyroscope(void *params)
{
   while (1)
   {
      gyro_data_t *gyro_data = get_gyroscope_data();
      double gyro_x_data = ((gyro_data->gyro_x_data.register_h_data << 8) | gyro_data->gyro_x_data.register_l_data); // * MPU_6500_GYRO_500_DPS_FULL_SCALE_RESOLUTION;
      double gyro_y_data = ((gyro_data->gyro_y_data.register_h_data << 8) | gyro_data->gyro_y_data.register_l_data); // * MPU_6500_GYRO_500_DPS_FULL_SCALE_RESOLUTION;
      double gyro_z_data = ((gyro_data->gyro_z_data.register_h_data << 8) | gyro_data->gyro_z_data.register_l_data); // * MPU_6500_GYRO_500_DPS_FULL_SCALE_RESOLUTION;
      printf("Orientation: { %f, %f, %f }\n\n", gyro_x_data, gyro_y_data, gyro_z_data);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
}
