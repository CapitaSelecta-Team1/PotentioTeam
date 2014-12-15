PotentioTeam
============

## Connections

| Peripheral  | Vcc   | Gnd     | In      |
|-------------|-------|---------|---------|
| Button 1    | Green | Purple  | Blue    |
| Button 2    | Black | Brown   | Red     |
| Pot         | White | Yellow  | Green   |

## Node Image

### Creation

 1. Go to `looci2-contiki/cmp_image`
 2. Run `lcco createImg	newImageName`
 3. Edit `makefile.image` and replace `blink` with the appropriate component name(s). Set the component directory name and add the source files.
 4. Edit `Image-conf.h` and include the appropriate h-files.
 5. Edit `image-init.c` and update the init to the code below.

```c
uint8_t	cbid = 0;
looci_cbMan_instan8ate_codebase(temp_sample_Lc.id,&cbid);
PRINT_LN("instantiated as: %u",cbid);
```
### Deployment

 1. Go to `looci2-contiki/build` and open `Makefile.options`
 2. Set your node id at line `15`
 3. Update your channel at line `23`
 4. Specify the image at line `37`
 5. Chance your current directory to `looci2-con8ki/build` and run

 ```shell
 make clean; make upload
 ```
