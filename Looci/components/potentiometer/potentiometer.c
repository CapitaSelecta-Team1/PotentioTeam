#include "contiki.h"
#include "looci.h"
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

struct state{

};

#define LOOCI_COMPONENT_NAME potentiometer_component
#define LOOCI_NR_PROPERTIES 0
LOOCI_PROPERTIES();
COMPONENT_INTERFACES(POTENTIO);
COMPONENT_RECEPTACLES(BUTTON_READING);
LOOCI_COMPONENT("Potentiometer Component", struct state);

static uint8_t activate(struct state* compState, void* data){
	printf("Potentiometer component activated\r\n");
	return 1;
}

static uint8_t event(struct state* compState, core_looci_event_t* event){

	// Read from ADC
    int potValue = readADC(0);

    // Set 0 as default result chiper.
    int resultChiper = 0;

    if(potValue >= LOW_1 && potValue < LOW_2){
        resultChiper = 1;
    } else if (potValue >= LOW_2 && potValue < LOW_3){
        resultChiper = 2;
    } else if (potValue >= LOW_3 && potValue < LOW_4){
        resultChiper = 3;
    } else if (potValue >= LOW_4){
        resultChiper = 4;
    }

    // Print the value, for now
    printf("Potentiometer value = %d\n", potValue);
    printf("Result Chiper = %d\n", resultChiper);

    // Publish value
	PUBLISH_EVENT(POTENTIO, resultChiper, sizeof(int));

    return LC_SUCCESS;
}

COMP_FUNCS_INIT
COMP_FUNC_ACTIVATE(activate)
COMP_FUNC_EVENT(event)
COMP_FUNCS_END(NULL)
