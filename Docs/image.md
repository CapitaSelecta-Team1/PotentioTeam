Image
=====

## Image Creation

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
## Image Deployment

 1. Go to `looci2-contiki/build` and open `Makefile.options`
 2. Set your node id at line `15`
 3. Update your channel at line `23`
 4. Specify the image at line `37`
 5. Chance your current directory to `looci2-contiki/build` and run
 6. Symlink the changed event-types.h in the `looci2-contiki/build` to the one in our build folder.

 ```shell
 make clean; make upload
 ```
