#include "contiki.h"
#include "looci.h"
#include "event-types.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif


struct state{
};

const static struct state initVar PROGMEM = {};

#define LOOCI_COMPONENT_NAME relay_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES();
COMPONENT_NO_RECEPTACLES(ALARM);
LOOCI_COMPONENT_INIT("Relay Component", struct state, &initVar);

static uint8_t activate(struct state* compState, void* data){
	printf("Relay component activated\r\n");
	return 1;
}

static uint8_t event(struct state* compState, core_looci_event_t* event){
	printf("event is happening\r\n");
	DDRE |= 1 << PE7; //Output == 1 op pin 7 van categorie PE, input == 0
	PORTE |= 1 << PE7; //High == 1, Low == 0

    return 1;
}

//FUNCTION DECLARATION

COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_EVENT(event)
COMP_FUNCS_END(NULL)
