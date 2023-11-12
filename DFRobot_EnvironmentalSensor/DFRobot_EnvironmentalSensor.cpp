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
}  // namespace dfrobotenvironmentalsensor
}  // namespace esphome
