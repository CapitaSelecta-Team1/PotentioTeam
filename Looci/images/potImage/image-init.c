 /*
 * composition-init.c
 *
 *  Created on: Nov 12, 2013
 *      Author: user
 */


#include "looci.h"
#include "component_type.h"
#include "codebaseManager.h"
#include "componentManager.h"
#include "eventBus_private.h"
#include "event-types.h"
#include "peers.h"

#include "project-conf.h"
#include "image-conf.h"

#ifdef LOOCI_IMAGE_INIT_DEBUG
#include "debug.h"
#else
#include "nodebug.h"
#endif

//define here the codebase structs that are needed for initialisation
// is typically COMP_NAME + _Lc

void doImageInit(){
	//instantiating component
	uint8_t button_cbid = 0;
	uint8_t potentiometer_cbid = 1;
	looci_cbMan_instantiate_codebase(button_component_Lc.id,&button_cbid);
	looci_cbMan_instantiate_codebase(potentiometer_component_Lc.id,&potentiometer_cbid);
	PRINT_LN("instantiated button as: %u",button_cbid);
	PRINT_LN("instantiated potentiometer as: %u",potentiometer_cbid);
}



