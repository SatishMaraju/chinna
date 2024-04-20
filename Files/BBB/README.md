##DATE:09/02/2024   TOPIC:Beagle Bone Black



Embedded Linux Lab Experiments:

1. Find the IP address of your target board. Find a tool/mechanism to ascertain if your host and target machines are connected.

2. Use the secure copy (scp) tool to copy files from host machine to target machine and vice versa.

Host to target board
km@kernelmasters:$ scp <filename> <Target_user_name>@<Target_IP_addr>:/

Target board to Host
km@KM-BBB:$ scp <filename> <host_user_name>@<Host_IP_addr>:/

3. Cross-Compile a simple C program on the Host machine and try to execute it on the host machine. Note the observations.

km@kernelmasters:~$ arm-linux-gnueabihf-gcc hello.c -o hello-arm
km@kernelmasters:~$ ./hello-arm

4. Cross-Compile a simple C program on the Host machine and transfer it to the Embedded Linux Board (target machine). Execute it on the board.

km@kernelmasters:$ scp hell-arm km@192.168.6.2:/
km@KM-BBB:~$ ./hello-arm

5. Compile a simple C program on the Embedded Linux Board and execute it on the board.

km@KM-BBB:~$ gcc hello.c -o hello
km@KM-BBB:~$ ./hello

RED LED & Switch Interfacing BBB

Experiment 1: Control GPIO pins from sys file system entry @ user space

1. Enter gpio class in sysfs file system,
	$ cd /sys/class/gpio
	2. Enter root login,
	/sys/class/gpio/$ sudo su
	3. Export pin 10,
	/sys/class/gpio/# echo 10 > export
	4. Enter the gpio10 folder,
	/sys/class/gpio/# cd gpio10
	5. Change pin direction to output,
	/sys/class/gpio/gpio10/# echo out > direction
	6. LED ON,
	/sys/class/gpio/gpio10/# echo 1 > value
	7. LED OFF,
	/sys/class/gpio/gpio10/# echo 0 > value
	8. Unexport pin 10,
	/sys/class/gpio/gpio10/# cd ..
	/sys/class/gpio/# echo 10 > unexport

	Exp 2: Lab Assignment

	Write a system program to Blink RED LED(GPIO0_10) every 1 sec delay.

	Exp 3: Lab Assignment - LED's ON

	Write a system program to read UP (GPIO0_26) and DOWN (GPIO0_27) switches,
	Whenever UP switch press RED LED(GPIO0_10) is ON and
	Whenever DOWN switch press RED LED(GPIO0_10) is OFF.

	DOWN Switch Code is 114 and UP Switch code is 115

	Exp 4: Lab Assignment - Blink LED's

	Write a system program to
	whenever UP Switch (GPIO0_26) Press blink GREEN LED(GPIO0_9) otherwise
	always Blink RED LED(GPIO0_10) every 1 sec Delay.

	Hint:
	- Create a two threads one is red_led thread and another one is green_led thread.
	- red_led thread keep on blinking red led every 1 sec delay without any interruption.
	- main thread keep on read UP switch event, whenever UP switch press set global flag (green_led_flag) is TRUE.
	- green_led thread keep on checks global flag, whenever global flag is TRUE blink GREEN LED one iteration and immediately global flag set to FALSE (green_led_flag=0).

	Exp 5: Synchronization

	Implement binary semaphore to synchronize main thread and green thread to avoid green_led_flag.
