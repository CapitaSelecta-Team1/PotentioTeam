#include "contiki.h"
#include "looci.h"
#include "event-types.h"
#include "energest.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif

struct state{struct etimer et;};

static bool movement_detected;

static unsigned long rx_start_time;
static unsigned long lpm_start_time;
static unsigned long cpu_start_time;
static unsigned long tx_start_time;

#define LOOCI_COMPONENT_NAME pir_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES( PIR );
COMPONENT_NO_RECEPTACLES();
LOOCI_COMPONENT("Pir Component", struct state);

static uint8_t activate(struct state* compState, void* data){

	printf("Pir component activated\r\n");

	//Enable all external interrupts
    EIMSK = 0xff;

    //Enable listening to all interrupts (on rising edge)
    EICRA = 0x03;

    // Activate timer
    ETIMER_SET(&compState->et, CLOCK_SECOND);

	rx_start_time = energest_type_time(ENERGEST_TYPE_LISTEN);
	lpm_start_time = energest_type_time(ENERGEST_TYPE_LPM);
	cpu_start_time = energest_type_time(ENERGEST_TYPE_CPU);
	tx_start_time = energest_type_time(ENERGEST_TYPE_TRANSMIT);

	return 1;
}

static uint8_t deactivate(struct state* compState, void* data){
	ETIMER_STOP(&compState->et);
	return 1;
}

static uint8_t time(struct state* compState, void* data){
	if(movement_detected){
		printf("PIR component publishing event. \r\n");
		PUBLISH_EVENT(PIR,true, sizeof(bool));
		movement_detected = false; 
	}

	printf("energy listen %lu tx %lu cpu %lu lpm %lu\n",
	energest_type_time(ENERGEST_TYPE_LISTEN) - rx_start_time,
	energest_type_time(ENERGEST_TYPE_TRANSMIT) - tx_start_time,
	energest_type_time(ENERGEST_TYPE_CPU) - cpu_start_time,
	energest_type_time(ENERGEST_TYPE_LPM) - lpm_start_time);

	ETIMER_RESET(&compState->et);

	return 1;
}

ISR(INT0_vect)
{
    movement_detected = true;
}


COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_DEACTIVATE(deactivate)
COMP_FUNC_TIMER(time)
COMP_FUNCS_END(NULL)
