/**
LooCI Copyright (C) 2013 KU Leuven.
All rights reserved.

LooCI is an open-source software development kit for developing and maintaining networked embedded applications;
it is distributed under a dual-use software license model:

1. Non-commercial use:
Non-Profits, Academic Institutions, and Private Individuals can redistribute and/or modify LooCI code under the terms of the GNU General Public License version 3, as published by the Free Software Foundation
(http://www.gnu.org/licenses/gpl.html).

2. Commercial use:
In order to apply LooCI in commercial code, a dedicated software license must be negotiated with KU Leuven Research & Development.

Contact information:
  Administrative Contact: Sam Michiels, sam.michiels@cs.kuleuven.be
  Technical Contact:           Danny Hughes, danny.hughes@cs.kuleuven.be
Address:
  iMinds-DistriNet, KU Leuven
  Celestijnenlaan 200A - PB 2402,
  B-3001 Leuven,
  BELGIUM.
 */
/*
 * event-types.h
 *
 *  Created on: Apr 10, 2013
 *      Author: root
 */

#ifndef EVENT_TYPES_H_
#define EVENT_TYPES_H_

#define ANY_EVENT 0
#define RECONFIGURATION_REQ_RANGE_START 1
#define RECONFIGURATION_REQ_RANGE_STOP 50
#define RECONFIGURATION_REP_RANGE_START 101
#define RECONFIGURATION_REP_RANGE_STOP 150
#define INTROSPECTION_REQ_RANGE_START 51
#define INTROSPECTION_REQ_RANGE_STOP 100
#define INTROSPECTION_REP_RANGE_START 151
#define INTROSPECTION_REP_RANGE_STOP 200

//RECONFIG

//COMPONENT MANAGEMENT
#define INSTALL_CODEBASE_EV 1
#define REMOVE_CODEBASE_EV 2
#define INSTANTIATE_CMP_EV 3
#define DESTROY_CMP_EV 4
#define START_COMPONENT_EV 5
#define STOP_COMPONENT_EV 6

// WIRING COMMANDS
#define WIRE_LOCAL_EV 7
#define WIRE_REM_TO_EV 8
#define WIRE_REM_FROM_EV 9
#define RESET_WIRINGS_EV 10
#define UNWIRE_LCL_EV 11
#define UNWIRE_REM_TO_EV 12
#define UNWIRE_REM_FROM_EV 13

//PROPERTIES
#define SET_PROPERTY 14

// INTROSPECTION

// COMPONENT META INFO
#define GET_ALL_CODEBASE_IDS_EV 51
#define GET_NAME_OF_CB_ID_EV 52
#define GET_CB_ID_BY_NAME_EV 53
#define GET_COMP_IDS_OF_CB_ID 54
#define GET_CB_ID_OF_COMP_ID_EV 55
#define GET_NAME_OF_COMP_ID_EV 56
#define GET_ALL_COMPONENT_IDS_EV 57
#define GET_STATE_EV 58

//properties
#define GET_PROPERTIES 59
#define GET_PROPERTY 60
#define GET_PROPERTY_NAME 61

#define GET_RECEPTACLES_EV 62
#define GET_INTERFACES_EV 63

//COMPONENT RUNTIME INFO
#define GET_LCL_WIRE_EV 64
#define GET_REM_TO_WIRE_EV 65
#define GET_REM_FROM_WIRE_EV 66
#define GET_PLATFORM_TYPE_EV 67

//shortcuts
#define GET_FULL_COMPONENT_INFO 68
#define GET_ALL_INSTANCES_INFO 69

///////////////////////////////////////////////////
//REPLY EVENTS
///////////////////////////////////////////////////

//RECONFIG
#define INSTALL_APPROVE_EV 101
#define REMOVED_EV 102
#define INSTANTIATED_EV 103
#define DESTROYED_EV 104
#define STARTED_EV 105
#define STOPPED_EV 106
#define WIRED_LOCAL_EV 107
#define WIRED_REM_TO_EV 108
#define WIRED_REM_FROM_EV 109
#define WIRES_RESET_EV 110
#define UNWIRED_LCL_EV 111
#define UNWIRED_REM_TO_EV 112
#define UNWIRED_REM_FROM_EV 113
#define PROPERTY_SET_EV 114

//INTROSPECTION
#define ALL_CODEBASE_IDS_EV 151
#define NAME_OF_CB_ID_EV 152
#define CB_ID_BY_NAME_EV 153
#define COMP_IDS_OF_CB_ID 154
#define CB_ID_OF_COMP_ID_EV 155
#define NAME_OF_COMP_ID_EV 156
#define ALL_COMPONENT_IDS_EV 157
#define STATE_EV 158
#define PROPERTIES_EV 159
#define PROPERTY_EV 160
#define PROPERTY_NAME_EV 161
#define RECEPTACLES_EV 162
#define INTERFACES_EV 163
#define LCL_WIRE_EV 164
#define REM_TO_WIRE_EV 165
#define REM_FROM_WIRE_EV 166
#define PLATFORM_TYPE_EV 167
#define FULL_COMPONENT_INFO 168
#define ALL_INSTANCES_INFO 169

// Application events
 #define POTENTIO 265
 #define PIR 266
 #define ALARM 267

// Application events
#define HUMIDITY_READING 256
#define TEMP_READING  257
#define LIGHT_READING  258
#define FILTERED_LIGHT_READING  259
#define FILTERED_TEMP_READING  260
#define FILTERED_HUMIDITY_READING  261
#define AVERAGE_LIGHT_READING  262
#define AVERAGE_TEMP_READING  263
#define AVERAGE_HUMIDITY_READING  264

//reading stuff
#define BUTTON_READING  270
#define SWITCH_READING  271
#define MOTION_READING  272

//operational events
#define DO_OP_EVENT  280
#define ON_OFF_EVENT  281
#define STRING_EVENT  283

// NeighbourDetection events
#define STARTNEIGHBOURDETECTION  301
#define STOPNEIGHBOURDETECTION  302
#define GETNEIGHBOURS  303
#define GET_K_NEIGHBOURS  304
#define NEIGHBOURSADVERT  305


//RPC events
#define RPC_REQUEST 512
#define RPC_REPLY 513
#define RPC_ERROR 514

// Error event, thrown when component does not know what to do with given event.
#define EVENT_ERROR_EVENT_NOT_SUPPORTED 301

#endif /* EVENT_TYPES_H_ */
