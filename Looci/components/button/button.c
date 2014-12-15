#include "contiki.h"
#include "looci.h"
#include "process.h"
#include "event-types.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif


struct state{
};

const static struct state initVar PROGMEM = {};


#define LOOCI_COMPONENT_NAME button_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES(BUTTON_PRESSED);
COMPONENT_NO_RECEPTACLES();
LOOCI_COMPONENT_INIT("Button Component", struct state, &initVar);

static uint8_t init(struct state* compState, void* data){
	PRINTF("Initializing Button Component\r\n");
	return 1;
}

static uint8_t activate(struct state* compState, void* data){

	//Enable all external interrupts
    EIMSK = 0xff;

    //Enable listening to all interrupts (on rising edge)
    EICRA = 0x03;

	return 1;
}

ISR(INT0_vect)
{
    PRINTF("Button pressed\r\n");
    PUBLISH_EVENT(BUTTON_PRESSED, true, 13);
}

//FUNCTION DECLARATION

COMP_FUNCS_INIT
COMP_FUNC_INIT(init)
COMP_FUNC_ACTIVATE(activate)
COMP_FUNCS_END(NULL)
