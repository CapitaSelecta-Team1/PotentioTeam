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

#define LOOCI_COMPONENT_NAME button_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES(BUTTON_READING);
COMPONENT_NO_RECEPTACLES();
LOOCI_COMPONENT("Button Component", struct state);

static uint8_t activate(struct state* compState, void* data){

	printf("Button component activated\r\n");

	//Enable all external interrupts
    EIMSK = 0xff;

    //Enable listening to all interrupts (on rising edge)
    EICRA = 0x03;

    // Set pressed to false
    pressed = false;

    // Activate timer
    ETIMER_SET(&compState->et, CLOCK_SECOND);

	return 1;
}

static uint8_t deactivate(struct state* compState, void* data){
	ETIMER_STOP(&compState->et);
	return 1;
}

static uint8_t time(struct state* compState, void* data){
	if(pressed){
		PUBLISH_EVENT(BUTTON_READING,true, sizeof(bool));
		pressed = false;
	}
	ETIMER_RESET(&compState->et);
	return 1;
}

ISR(INT0_vect)
{
    pressed = true;
}

COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_DEACTIVATE(deactivate)
COMP_FUNC_TIMER(time)
COMP_FUNCS_END(NULL)
