# core-v-mcu2-eclipse
Eclipse project that uses the FreeRTOS kernel and runs on core-v-mcu2
## Installation
Eclipse relies on a larger ecosystem of tools.  This project uses a particualr set of tools in a particualr set of locations.  These instructions do not cover loading the other tools, or adapting the preferences to point to different tools or different locations.  These instructions assume that you are familar enough with Eclispe to make any required changes.
### Step 1: 
Download and install Eclipse for Embedded and not Host based eclipse.  
~~~
https://projects.eclipse.org/projects/iot.embed-cdt/downloads
~~~

### Step 2:
Install OpenOCD.  Recommend getting it from this location:
~~~
https://sourceforge.net/projects/openocd/files/openocd/
~~~
I used 0.11.0-rc2.
Installation is accomplished by:
~~~
./configure && make
sudo make install
~~~


### Step 3: run Eclipse, import projects directly from git (import launch in step 4)
~~~
eclipse
~~~
NOTE: importing the uart_test does not imprt the information to launch the debugger, so after importing uart_test, be sure to either import the launch configuration or create you own.
- create and launch a new workspace then select import existing projects

![step1](./docs/images/ImportFromGit-1.png)
- select clone URL

![step2](./docs/images/ImportFromGit-2-CloneURL.png)
- paste repo name

![step3](./docs/images/ImportFromGit-3-URL.png)

- specify folder to put files in (default is git/reponame)

![step4](./docs/images/ImportFromGit-4-LocalDest.png)

- select the branch to use

![step5](./docs/images/ImportFromGit-5-Branch.png)

- select the import wizard (default works fine)

![step6](./docs/images/ImportFromGit-6-ImportWizard.png)

- tell it to actually import form the repo

![step7](./docs/images/ImportFromGit-7-Import.png)

- this is what it looks like when the import has finished

![step9](./docs/images/ImportFromGit-8-ImportDone.png)

# Step 4: Import launch configuration
This step pulls in the launch configurations which are configured to use hs2 and OpenOCD.
If you hardware setup is different, you can either ignore this step and create your own, or use this step and modify to fit your configuration.

- select import launch configurations

![step4.1](./docs/images/ImportLaunch-1.png)

- specify the directory where the files were imported (default is git/reponame)

![step4.2](./docs/images/ImportLaunch-2-Directory.png)

- select which launch configurations to import

![step4.3](./docs/images/ImportLaunch-3-Configs.png)

- under debug>Debug configurations ... choose GDB OpenOCD>config a click Debug

![step4.1](./docs/images/ImportLaunch-4-Debug.png)

This should compile, link and load the application and stop at main waiting for you to start debugging.


## Emulation hardware
The intent is to support more than one emulation platform.
Currently only one board is supported:

* Nexys A7 100T

![Nexys Setup](./docs/images/nexys-setup.png)

## Emulation bitsream
Bistreams compatible with the Nexys A7 100T can be found at:
http://quickai.quicklogic.com/
![bitstream](./docs/images/bit-stream-url.png)

TODO: need to find a way to manage bitstream and software versions.

## Peripheral support
The type and number of peripherals supported are defined by 'pulp_soc_defines.sv'.
The information is made available to software applications as a series of #define values in the 'SOC options' section of 'target/core-v-mcu/include/core-v-mcu-config.h'.
An example configuration is:
~~~
// SOC options
#define N_IO                 48         // Total available IO
#define N_SYSIO              3
#define N_GPIO               32
#define N_UART               2          // Number of uarts
#define N_QSPIM              1          // Number of QuadSPI masters
#define N_I2CM               2          // Number of I2C masters
#define N_I2SC               0
#define N_CSI2               0
#define N_HYPER              0
#define N_SDIO               0
#define N_CAM                1
#define N_JTAG               0
#define N_MRAM               0
#define N_FILTER             1
#define N_FPGA               1
#define N_EXT_PER            0
#define N_EFPGA_TCDM_PORTS   4
#define N_FPGAIO             43
#define N_EFPGA_EVENTS       16
~~~

## uart_test example
This example writes messages to both UART0 and UART1.  UART0 is the built-in UART that is accessed via the micro-usb port on the Nexys board.  UART1 is connected to PMOD connected JB.  You can either plug in a PmodUSBUART Peripheral Module to the top row of JB, or wire any USB to serial adaptor to JB[2] and JB[3].
The messages from UART0 say 'Blinky[0]' followed by iteration number, and those from UART1 say 'Blinky[1]' followed by interation number plus 10.  An example of the output is:
![uart_test outut](./docs/images/dual-uart-screen.jpg)
