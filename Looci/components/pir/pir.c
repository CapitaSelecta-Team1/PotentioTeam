#include "contiki.h"
#include "looci.h"
#include "event-types.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif

struct state{struct etimer et;};

static bool pressed;

#define LOOCI_COMPONENT_NAME pir_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES(PIR);
COMPONENT_NO_RECEPTACLES();
LOOCI_COMPONENT("Pir Component", struct state);

static uint8_t activate(struct state* compState, void* data){

	printf("Pir component activated\r\n");

    // Activate timer
    ETIMER_SET(&compState->et, CLOCK_SECOND);

	return 1;
}

static uint8_t deactivate(struct state* compState, void* data){
	ETIMER_STOP(&compState->et);
	return 1;
}

static uint8_t time(struct state* compState, void* data){

	// TODO PUBLISH DIGITAL VALUE
	// PUBLISH_EVENT(PIR,true, sizeof(bool));

	ETIMER_RESET(&compState->et);
	return 1;
}

COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_DEACTIVATE(deactivate)
COMP_FUNC_TIMER(time)
COMP_FUNCS_END(NULL)
