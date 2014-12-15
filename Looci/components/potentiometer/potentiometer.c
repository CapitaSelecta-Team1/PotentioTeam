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

static uint8_t init(struct state* compState, void* data){
	PRINTF("Initializing Potentiometer Component\r\n");
	return 1;
}

static uint8_t activate(struct state* compState, void* data){
	return 1;
}


COMP_FUNCS_INIT
COMP_FUNC_INIT(init)
COMP_FUNC_ACTIVATE(activate)
COMP_FUNCS_END(NULL)
