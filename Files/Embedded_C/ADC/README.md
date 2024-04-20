##DATE : 16/11/23         TOPIC:ADC

ADC Lab Experiments:

Read Potentiometer
1) Write an Embedded C program to initialize ADC Scan mode.
Using regular channel software trigger samples ADC channel 11 (potentiometer) and
stores the result to a global variable that can be accessed with the ST-Link Debugger.
a) polling method and b) interrupt method

Read multiple channels
2) Write an Embedded C program to initialize ADC Scan mode.
Using regular channel software trigger samples ADC channel 10 (Temperature sensor) and 11 (potentiometer) and
stores the result to a global variables that can be accessed with the ST-Link Debugger.
using interrupt method.

Hint: To read multiple channels, no. of channels mentioned in length field in ADX SQR1 register.
In this example to read two channels(10,11) so length is 2.
1st channel(10) load in to SQR3 in SQ1 bit fields and
2nd channel(11) load in to SQR3 in SQ2 bit fields.

ADC Watchdog
3) Write an Embedded C program to initialize ADC Scan mode.
load lower threshold value 1000 in to ADC LTR and higher threshold value 2000 in to ADC HTR.
Enable ADC watchdog timer interrupt.

Test case: Assign a breakpoint inside ADC ISR, Adjust potentiometer knob, whenever to reach beyond threshold values program stop in ISR.
