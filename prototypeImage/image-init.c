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
	PRINT_LN("test app: %u",blink_Lc.id);
	//instantiating component
	uint8_t cbid = 0 ;
	looci_cbMan_instantiate_codebase(temp_sample_Lc.id,&cbid);
	uint8_t success = looci_cbMan_instantiate_codebase(cbid);
	PRINT_LN("instantiated sample as: %u",cbid);

	//do activation
	success = looci_cmpMan_component_start(cbid);
	PRINT_LN("succes = %u",success);



	// do subscription, appended some example code:
	/* WireToAll
	subs_rem_to subCmd;
	subCmd.src_cmp = instantiateCmd.cid;
	subCmd.dst_nod = PEER_ID_ALL;
	subCmd.type = TEMP_READING;
	events_add_remote_subscription_to(&subCmd);
	*/

	/* WireFromPeer
	peer_addr_t myAddr = {0xaa,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01};
	uint8_t peerId = peer_add(&myAddr);
	subs_rem_from subFromCmd;
	subFromCmd.dst_cmp = instantiateCmd.cid;
	subFromCmd.src_cmp = 0 ;// any src comp
	subFromCmd.src_nod = peerId;
	subFromCmd.type = TEMP_READING;
	events_remove_remote_subscription_from(&subFromCmd);
	 */

}



