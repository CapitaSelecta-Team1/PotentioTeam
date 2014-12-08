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


#define LOOCI_COMPONENT_NAME prototype
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES(

);

COMPONENT_INTERFACES(PROTOTYPE);
COMPONENT_NO_RECEPTACLES();
LOOCI_COMPONENT_INIT("Prototype", struct state, &initVar);

static uint8_t init(struct state* compState, void* data){
	PRINTF("Init\r\n");
	return 1;
}


static uint8_t activate(struct state* compState, void* data){
	PRINTF("Activate\r\n");
	return 1;
}

static uint8_t deactivate(struct state* compState, void* data){
	PRINTF("Deactivate\r\n");
	return 1;
}

static uint8_t sensorCall(struct state* compState, struct sensors_sensor* sensor){
	PRINTF("Sensor Call Received\r\n");
	return 1;
}

static uint8_t eventCall(struct state* compState, core_looci_event_t* event){
	PRINTF("Event Call Received\r\n");
	return 1;
}

//FUNCTION DECLARATION

COMP_FUNCS_INIT
COMP_FUNC_INIT(init)
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_DEACTIVATE(deactivate)
COMP_FUNC_SENSOR(sensorCall)
COMP_FUNC_EVENT(eventCall)
COMP_FUNCS_END(NULL)
