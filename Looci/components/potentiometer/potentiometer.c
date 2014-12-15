#include "contiki.h"
#include "looci.h"
#include "process.h"
#include "event-types.h"
#include "adc.h"

#ifdef LOOCI_COMPONENT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif

#define LOW_1 0
#define LOW_2 267
#define LOW_3 577
#define LOW_4 841

struct state{};

#define LOOCI_COMPONENT_NAME potentiometer_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_NO_INTERFACES();
COMPONENT_RECEPTACLES(BUTTON_READING);
LOOCI_COMPONENT("Potentiometer Component", struct state);

static uint8_t activate(struct state* compState, void* data){
	return 1;
}

static uint8_t event(struct state* compState, core_looci_event_t* event){

	// Read from ADC
    int potValue = readADC(0);

    // Print the value, for now
    PRINTF("Potentiometer value = %d\n", potValue);
    return 1;
}

COMP_FUNCS_INIT
COMP_FUNC_INIT(init)
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_EVENT(event)
COMP_FUNCS_END(NULL)
