Setup Guide
===========

## Linking

The following files in this repository require linking. The folders in the Looci folder should be linked to the root of `looci-contiki` in order to work properly.

## Building Image

Use the script `loociUpload.sh` to deploy an image with the given components to the sensor node.

## Node Setup

Use the following command in OSGI to setup the nodes. Replace XY with the appropriate node ID.

```
doScript configPotentioXY
```
