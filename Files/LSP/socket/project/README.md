##DATE:12/02/2024      TOPIC:PROJECT ON SOCKETS

Topics: Advanced File operations, Socket Programming, Threads and signals.

********************************************************** Version 1.0: ********************************************************************

Write a socket program to implement chat application in between two desktop/laptop 
computers. one system consider as server and another system consider as client.
Hint: Server IP address assign both side programs.

******************************************************** Version 2.0: **********************************************************************

Write a socket program to implement chat application in between two Beagle Bone Black's 
using sockets. one BBB consider as server and another board consider as client.

****************************************************** Version 3.0: **********************************************************************

Write a system program communicate BBB with desktop computer and transfer the data 
mentioned in the below protocol using socket program.
Desktop/Laptop(server) BBB1 (Client) 
Transmit 'R' RED LED ON 
Transmit 'O' RED LED OFF 
Receive 'R' Press UP Switch 
Receive 'O' Press Down Switch 

****************************************************** Version 4.0: *************************************************************************

Write a system program communicate two BBB and transfer the data mentioned in the 
below protocol using socket program.
BBB1 (server) BBB2 (Client) 
Press UP Switch RED LED ON 
Press Down Switch RED LED OFF 
RED LED ON Press UP Switch 
RED LED OFF Press Down Switch 
 


****************************************************** Version 5.0: ***************************************************************************

Write a system program communicate two BBB and transfer the data mentioned in the 
below protocol using socket program.
BBB1 (Server) BBB2 (Client) 
Press UP Switch BLINK RED LED until Down Switch ON 
Press Down Switch RED LED OFF 
BLINK RED LED until Down switch ON Press UP Switch 
RED LED OFF Press Down Switch 

******************************************************** Version 6.0 ******************************************************************************

In previous version, add signals to server and client mentioned in the below steps:
 - In Rx handler thread, Whenever Recevie 'R' then raise a SIGUSR1 signal to blink thread.
 - In Rx handler thread, Whenever Recevie 'O' then raise a SIGUSR2 signal to blink thread.
 
Hint: use pthread_kill() system call raise a signal to threads
