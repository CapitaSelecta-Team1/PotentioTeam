#include "contiki.h"
#include "looci.h"

#include "utils.h"
#include "timer_utils.h"
#include <avr/pgmspace.h>
#include "sensors.h"
#include "event-types.h"
#include "adc.h"

#include <stdint.h>
#include <stdio.h>

#include "process.h"
#include "event-types.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif

#define LOW_1 0
#define LOW_2 267
#define LOW_3 577
#define LOW_4 841

struct state{
	int pot;
	looci_event_t* event;
};

#define LOOCI_NR_PROPERTIES 0

LOOCI_PROPERTIES();
COMPONENT_INTERFACES(LIGHT_READING);
COMPONENT_RECEPTACLES(ANY_EVENT);
LOOCI_COMPONENT("potmeter", struct state);
COMPONENT_THREAD( ev, data)
{
	COMPONENT_BEGIN(struct state,compState);
	compState->pot = 0;

    //Enable all external interupts
    // INT0 used for the button
    EIMSK = 0xff;
    //Enable listening to all interupts (on rising edge)
    EICRA = 0x03;

	while(1) {
		LOOCI_EVENT_RECEIVE(compState->event);
	}

	COMPONENT_END();
}

ISR(INT0_vect)
{
    int p = readADC(0);
    printf("Hello ADC=%d\n",p);
}
