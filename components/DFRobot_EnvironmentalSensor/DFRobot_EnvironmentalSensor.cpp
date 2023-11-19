#include "DFRobot_EnvironmentalSensor.h"
#include "esphome/core/log.h"
#include "src/DFRobot_EnvironmentalSensor.h"

namespace esphome {
namespace dfrobotenvironmentalsensor {

static const char *const TAG = "dfrobotenvironmentalsensor.sensor";

void DFRobotEnvironmentalSensorComponent::setup() {
  ESP_LOGD(TAG, "Setting up DFRobot environmental sensor");
  environment_ = DFRobot_EnvironmentalSensor(SEN050X_DEFAULT_DEVICE_ADDRESS, &Wire);
  environment_.begin();
  ESP_LOGD(TAG, "Conected to environmental sensor");
};

void DFRobotEnvironmentalSensorComponent::update() {
  ESP_LOGV(TAG, "Starting update");
  float temperature = environment_.getTemperature(TEMP_C);
  temperature_sensor_->publish_state(temperature);

  int pressure = environment_.getAtmospherePressure(HPA);
  pressure_sensor_->publish_state(pressure);

  auto humidity = environment_.getHumidity();
  humidity_sensor_->publish_state(humidity);

  auto uv = environment_.getUltravioletIntensity();
  uv_sensor_>publish_state(uv);

  auto lumens = environment_.getLuminousIntensity();
  light_sensor_>publish_state(lumens);
  ESP_LOGV(TAG, "Published readings");
}
}  // namespace dfrobotenvironmentalsensor
}  // namespace esphome