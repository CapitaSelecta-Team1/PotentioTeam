#include <stddef.h>
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

#define LOOCI_COMPONENT_NAME relay_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_NO_INTERFACES();
COMPONENT_RECEPTACLES(ALARM);
LOOCI_COMPONENT("Relay Component", struct state);

static uint8_t activate(struct state* compState, void* data){
	printf("Relay component activated\r\n");
	return 1;
}

static uint8_t event(struct state* compState, core_looci_event_t* event){
	char* payloadAdress = event->payload;
	int payloadValue = (*payloadAdress);
	printf("received alarm event payload adress= %d\r\n",payloadAdress);
	printf("received alarm event payload value= %d\r\n",payloadValue);
	DDRE |= 0 << PE7;
	int currentVal = PORTE >> PE7;
	printf("received alarm event currentVal= %d\r\n",currentVal);
	int doToggle = 0;
	if(currentVal != payloadValue){
		doToggle=1;
	}
	printf("received alarm event doToggle= %d\r\n",doToggle);
	DDRE |= 1 << PE7; //Output == 1 op pin 7 van categorie PE, input == 0
	PORTE ^= doToggle << PE7; //High == 1, Low == 0

    return 1;
}

//FUNCTION DECLARATION

COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_EVENT(event)
COMP_FUNCS_END(NULL)
