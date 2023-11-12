#pragma once
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"

namespace esphome {
namespace dfrobotenvironmentalsensor {

class DFRobotEnvironmentalSensorComponent : PollingComponent {
  public:
    void set_temperature_sensor(sensor::Sensor *temperature_sensor) { temperature_sensor_ = temperature_sensor; }
    void set_pressure_sensor(sensor::Sensor *pressure_sensor) { pressure_sensor_ = pressure_sensor; }
    void set_humidity_sensor(sensor::Sensor *humidity_sensor) { humidity_sensor_ = humidity_sensor; }
    void set_uv_sensor(sensor::Sensor *uv_sensor) { uv_sensor_ = uv_sensor; }
    void set_light_sensor(sensor::Sensor *light_sensor) { light_sensor_ = light_sensor; }

    // ========== INTERNAL METHODS ==========
    // (In most use cases you won't need these)
    void setup() override;
    void dump_config() override;
    float get_setup_priority() const override;
    void update() override;

  protected:
    sensor::Sensor *temperature_sensor_{nullptr};
    sensor::Sensor *pressure_sensor_{nullptr};
    sensor::Sensor *humidity_sensor_{nullptr};
    sensor::Sensor *uv_sensor_{nullptr};
    sensor::Sensor *light_sensor_{nullptr};

  };
}  // namespace dfrobotenvironmentalsensor
}  // namespace esphome
