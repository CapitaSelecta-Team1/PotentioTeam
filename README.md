PotentioTeam
============

## Components

 - **Button Component**: triggers and event when the button connected to external interrupt vector 0 is pressed.
 - **Potentiometer Component**: triggers an event containing the current potentiometer value when the button component is triggered.
 - **Relay Component**: enables digital pin 7 when the relay event is triggered.

## Images

 - **potImage**: image containing the potentiometer and button component.
 - **relayImage**: image containing the relay component.

### Image Creation

A custom image can be created as follows:

 1. Go to `looci2-contiki/cmp_image`
 2. Run `lcco createImg	newImageName`
 3. Edit `makefile.image` and replace `blink` with the appropriate component name(s). Set the component directory name and add the source files.
 4. Edit `Image-conf.h` and include the appropriate h-files.
 5. Edit `image-init.c` and update the init to the code below with the appropriate component name.

```c
uint8_t	cbid = 0;
looci_cbMan_instan8ate_codebase(component_name_Lc.id,&cbid);
PRINT_LN("instantiated as: %u",cbid);
```
### Image Deployment

 1. Go to `looci2-contiki/build` and open `Makefile.options`
 2. Set your node id at line `15`
 3. Update your channel at line `23`
 4. Specify the image at line `37`
 5. Chance your current directory to `looci2-contiki/build` and run

 ```shell
 make clean; make upload
 ```

## Connections

 - Button is connected to interrupt vector 0
 - The potentiometer is connected on ADC 0
 - The relay is connected to digital pin 7

### Wiring

| Peripheral  | Vcc   | Gnd     | In      |
|-------------|-------|---------|---------|
| Button 1    | Green | Purple  | Blue    |
| Button 2    | Black | Brown   | Red     |
| Pot         | White | Yellow  | Green   |


