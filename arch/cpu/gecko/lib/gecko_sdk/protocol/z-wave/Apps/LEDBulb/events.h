/**
 * @file
 *
 * Definitions of events for the LED Bulb Certified App.
 *
 * @copyright 2020 Silicon Laboratories Inc.
 */
#ifndef APPS_LEDBULB_EVENTS_H_
#define APPS_LEDBULB_EVENTS_H_

#include <ev_man.h>

/**
 * Defines events for the application.
 *
 * These events are not referred to anywhere else than in the application. Hence, they can be
 * altered to suit the required application flow.
 *
 * The events are located in a separate file to make it possible to include them in other
 * application files. An example could be a peripheral driver that enqueues an event when something
 * specific happens.
 */
typedef enum EVENT_APP_LED_BULB
{
  EVENT_EMPTY = DEFINE_EVENT_APP_NBR,
  EVENT_APP_INIT,
  EVENT_APP_REFRESH_MMI,
  EVENT_APP_FLUSHMEM_READY,
  EVENT_APP_SMARTSTART_IN_PROGRESS,
  EVENT_APP_BUTTON_LEARN_RESET_SHORT_PRESS,
  EVENT_APP_BUTTON_LEARN_RESET_LONG_PRESS,
}
EVENT_APP;

#endif /* APPS_LEDBULB_EVENTS_H_ */
