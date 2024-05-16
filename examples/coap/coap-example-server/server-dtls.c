#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contiki.h"
#include "coap-engine.h"
#include "coap-secure-engine.h"  // Necessary for secure CoAP functionalities

#if PLATFORM_SUPPORTS_BUTTON_HAL
#include "dev/button-hal.h"
#else
#include "dev/button-sensor.h"
#endif

/* Log configuration */
#include "sys/log.h"
#define LOG_MODULE "App"
#define LOG_LEVEL LOG_LEVEL_APP

extern coap_resource_t
  res_hello,
  res_mirror,
  res_chunks,
  res_separate,
  res_push,
  res_event,
  res_sub,
  res_b1_sep_b2;

#if PLATFORM_HAS_LEDS
extern coap_resource_t res_leds, res_toggle;
#endif

#if PLATFORM_HAS_LIGHT
#include "dev/light-sensor.h"
extern coap_resource_t res_light;
#endif

#if PLATFORM_HAS_BATTERY
#include "dev/battery-sensor.h"
extern coap_resource_t res_battery;
#endif

#if PLATFORM_HAS_TEMPERATURE
#include "dev/temperature-sensor.h"
extern coap_resource_t res_temperature;
#endif

PROCESS(er_example_server, "Erbium Example Server");
AUTOSTART_PROCESSES(&er_example_server);

PROCESS_THREAD(er_example_server, ev, data)
{
  PROCESS_BEGIN();

  // Initialize both standard and secure CoAP engines
  coap_engine_init();
  coap_secure_engine_init(); // Initialize the secure CoAP engine for DTLS support

  LOG_INFO("Starting Secure Erbium CoAP Server\n");

  // Activate resources
  coap_activate_resource(&res_hello, "test/hello");
  coap_activate_resource(&res_mirror, "debug/mirror");
  coap_activate_resource(&res_chunks, "test/chunks");
  coap_activate_resource(&res_separate, "test/separate");
  coap_activate_resource(&res_push, "test/push");
#if PLATFORM_HAS_BUTTON
  coap_activate_resource(&res_event, "sensors/button");
#endif
  coap_activate_resource(&res_sub, "test/sub");
  coap_activate_resource(&res_b1_sep_b2, "test/b1sepb2");
#if PLATFORM_HAS_LEDS
  coap_activate_resource(&res_toggle, "actuators/toggle");
#endif
#if PLATFORM_HAS_LIGHT
  coap_activate_resource(&res_light, "sensors/light");
  SENSORS_ACTIVATE(light_sensor);
#endif
#if PLATFORM_HAS_BATTERY
  coap_activate_resource(&res_battery, "sensors/battery");
  SENSORS_ACTIVATE(battery_sensor);
#endif
#if PLATFORM_HAS_TEMPERATURE
  coap_activate_resource(&res_temperature, "sensors/temperature");
  SENSORS_ACTIVATE(temperature_sensor);
#endif

  while(1) {
    PROCESS_WAIT_EVENT();
#if PLATFORM_HAS_BUTTON
    if(ev == button_hal_release_event || (ev == sensors_event && data == &button_sensor)) {
      LOG_DBG("*******BUTTON*******\n");
      res_event.trigger(); // Trigger events specific to button press
      res_separate.resume(); // Resume separate response handler if used
    }
#endif
  }

  PROCESS_END();
}
