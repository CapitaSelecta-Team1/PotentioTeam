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
	uint8_t cbid = 0 ;
	looci_cbMan_instantiate_codebase(pir_component_Lc.id,&cbid);
	PRINT_LN("instantiated pirImage as: %u",cbid);
}



