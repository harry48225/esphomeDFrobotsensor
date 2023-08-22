#include "esphome.h"
#include "DFRobot_EnvironmentalSensor.h"


class MyCustomSensor : public PollingComponent {
 public:
  DFRobot_EnvironmentalSensor environment = DFRobot_EnvironmentalSensor(/*addr = */SEN050X_DEFAULT_DEVICE_ADDRESS, /*pWire = */&Wire);
  Sensor *temperature_sensor = new Sensor();
  Sensor *pressure_sensor = new Sensor();
  Sensor *humidity_sensor = new Sensor();
  Sensor *ultraviolet_sensor = new Sensor();
  Sensor *luminous_intensity_sensor = new Sensor();

  MyCustomSensor() : PollingComponent(15000) { }

  void setup() override {
    environment.begin();
  }

  void update() override {
    // This is the actual sensor reading logic.
    float temperature = environment.getTemperature(TEMP_C);
    temperature_sensor->publish_state(temperature);

    int pressure = environment.getAtmospherePressure(HPA);
    pressure_sensor->publish_state(pressure);

    auto humidity = environment.getHumidity();
    humidity_sensor->publish_state(humidity);

    auto uv = environment.getUltravioletIntensity();
    ultraviolet_sensor->publish_state(uv);

    auto lumens = environment.getLuminousIntensity();
    luminous_intensity_sensor->publish_state(lumens);
  }
};
