#include "contiki.h"
#include "dev/leds.h"
#include "sys/etimer.h"

#include <stdio.h> 
static struct etimer helloworld_timer;
static struct etimer led_timer;
static uint8_t counter;

PROCESS(hello_world_process, "Hello world led");
AUTOSTART_PROCESSES(&hello_world_process);

PROCESS_THREAD(hello_world_process, ev, data)
{
  
  
  PROCESS_BEGIN();

  counter = 0;

  etimer_set(&led_timer, CLOCK_SECOND * 20 ); 
  etimer_set(&helloworld_timer, CLOCK_SECOND * 10);

  while(1) {
    

    PROCESS_YIELD();

    if (ev == PROCESS_EVENT_TIMER && data == &helloworld_timer)
    {
      printf("Hello, world and jawad\n");
      PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&helloworld_timer));
      etimer_reset(&helloworld_timer);
    }

      if(ev == PROCESS_EVENT_TIMER && data == &led_timer) {
        if(counter % 2 == 0) {
          leds_on(LEDS_ALL);
        } else {
          leds_off(LEDS_ALL);
        }
        counter++;
        etimer_set(&led_timer, CLOCK_SECOND);
        }
  }

  PROCESS_END();
  }

