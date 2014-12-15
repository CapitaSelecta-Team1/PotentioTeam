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
    int p;
	PROCESS_BEGIN();

    printf("Hello, world!\n");

	while(1)
  	{
  		//PROCESS_WAIT_EVENT();
        p = readADC(0);
        printf("Hello ADC, p=%d!\n", p);
        //Wait for 1000 clock cycles
        clock_wait(1000);
  	}

	PROCESS_END();
}
