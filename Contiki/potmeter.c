#include "contiki.h"
#include <stdio.h>
#include "adc.h"
#define LOW_1 0
#define LOW_2 267
#define LOW_3 577 
#define LOW_4 841 

PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);

PROCESS_THREAD(hello_world_process, ev, data)
{
	PROCESS_BEGIN();

    printf("Hello, world!\n");

    //Enable all external interupts 
    // INT0 used for the button
    EIMSK = 0xff;
    //Enable listening to all interupts (on rising edge)
    EICRA = 0x03;

	while(1)
  	{
  		PROCESS_WAIT_EVENT();
  	}

	PROCESS_END();
}

ISR(INT0_vect)
{
    int p = readADC(0);
    printf("Hello ADC=%d\n",p);
}
