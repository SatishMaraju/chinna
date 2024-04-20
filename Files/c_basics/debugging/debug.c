/*** 1. gdb-sample.c: class room example program, attached this mail.***/



(gdb) l
1	/*1. gdb-sample.c: class room example program, attached this mail.*/
2	
3	
4	 int Change_Value = 0;
5	
6	  int Sum_it (int, int);
7	  void error_with_code (void);
8	
9	 int main (void)
10	 {
(gdb) l
11	    int Arg_1 = 20, Arg_2 = 40;
12	    int i;
13	
14	
15	     for (i = 0; i < 10; i++) {
16	        if (Arg_1 > Arg_2)
17	             Arg_2 = Sum_it (Arg_1, Arg_2);
18	        else
19	            Arg_1 = Sum_it (Arg_1, Arg_2);
20	     }
(gdb) l
21	
22	     error_with_code ();
23	
24	 }   
25	
26	 int Sum_it (int a, int b)
27	
28	 {
29	     return a+b;
30	
(gdb) l
31	 } 
32	
33	 void error_with_code(void)
34	 {
35	    int divide_value;
36	    int result;
37	
38	    divide_value = Change_Value;
39	    result = 10 / divide_value;
40	    return ;
(gdb) l
41	
42	 } 
43	
(gdb) b 11
Breakpoint 1 at 0x602: file 1_sample.c, line 11.
(gdb) b error_with_code 
Breakpoint 2 at 0x675: file 1_sample.c, line 38.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000602 in main at 1_sample.c:11
2       breakpoint     keep y   0x0000000000000675 in error_with_code at 1_sample.c:38
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/1_sample-gdb 

Breakpoint 1, main () at 1_sample.c:11
11	    int Arg_1 = 20, Arg_2 = 40;
(gdb) s
15	     for (i = 0; i < 10; i++) {
(gdb) p Arg_1
$1 = 20

(gdb) p Arg_2
$2 = 40
(gdb) s
16	        if (Arg_1 > Arg_2)
(gdb) s
19	            Arg_1 = Sum_it (Arg_1, Arg_2);
(gdb) s
Sum_it (a=20, b=40) at 1_sample.c:29
29	     return a+b;
(gdb) p Arg_1
No symbol "Arg_1" in current context.
(gdb) S
Undefined command: "S".  Try "help".
(gdb) s
31	 } 
(gdb) s
main () at 1_sample.c:15
15	     for (i = 0; i < 10; i++) {
(gdb) p Arg_1
$3 = 60
(gdb) s
16	        if (Arg_1 > Arg_2)
(gdb) s
17	             Arg_2 = Sum_it (Arg_1, Arg_2);
(gdb) n
15	     for (i = 0; i < 10; i++) {
(gdb) p Arg_1
$4 = 60
(gdb) p Arg_2
$5 = 100
(gdb) s
16	        if (Arg_1 > Arg_2)
(gdb) c
Continuing.

Breakpoint 2, error_with_code () at 1_sample.c:38
38	    divide_value = Change_Value;
(gdb) p Change_value
No symbol "Change_value" in current context.
(gdb) s
39	    result = 10 / divide_value;
(gdb) p Change_value
No symbol "Change_value" in current context.
(gdb) p divide_value
$6 = 0
(gdb) s

Program received signal SIGFPE, Arithmetic exception.
0x0000555555554684 in error_with_code () at 1_sample.c:39
39	    result = 10 / divide_value;
(gdb) p divide_value = 5
$7 = 5
(gdb) s

Program terminated with signal SIGFPE, Arithmetic exception.
The program no longer exists.
gdb) watch Arg_1
Hardware watchpoint 3: Arg_1
(gdb) watch Arg_2
Hardware watchpoint 4: Arg_2
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000555555554602 in main at 1_sample.c:11
	breakpoint already hit 1 time
2       breakpoint     keep y   0x0000555555554675 in error_with_code at 1_sample.c:38
3       hw watchpoint  keep y                      Arg_1
4       hw watchpoint  keep y                      Arg_2
(gdb) s

Hardware watchpoint 3: Arg_1

Old value = 32767
New value = 20
0x0000555555554609 in main () at 1_sample.c:11
11	    int Arg_1 = 20, Arg_2 = 40;
(gdb) s

Hardware watchpoint 4: Arg_2

Old value = 0
New value = 40
main () at 1_sample.c:15
15	     for (i = 0; i < 10; i++) {
(gdb) s
16	        if (Arg_1 > Arg_2)
(gdb) s
19	            Arg_1 = Sum_it (Arg_1, Arg_2);
(gdb) n

Hardware watchpoint 3: Arg_1

Old value = 20
New value = 60
main () at 1_sample.c:15
15	     for (i = 0; i < 10; i++) {
(gdb) q
A debugging session is active.

	Inferior 1 [process 7123] will be killed.

Quit anyway? (y or n) y

 /* % grading with % as float. */






****2 problem ***



(gdb) l
1	/*Find the % of marks for 6 subjects (read 6 subject marks and calculate percentage), for a student, and print the grade of the student as per below division , using if else statement and typecasting operator to get perfect floating point percentage.
2	          80 - 100        : Honours
3	          60 - 79         : First Division
4	          50 - 59         : Second Division
5	          40 - 49         : Third Division
6	          0 - 39          : fail
7	       author:p.tharun
8	       date  :29/08/2023  */ 
9	
10	#include<stdio.h>
(gdb) l
11	int main()
12	  {
13	
14		int t,h,e,m,s,ss;
15	        float perc;
16	        printf("enter the t,h,e,m,s,ss marks :\n");
17	        scanf("%d%d%d%d%d%d",&t,&h,&e,&m,&s,&ss);       
18		perc=(t+h+e+m+s+ss)/6.0;
19	       
20	        if(perc<=80.0 && perc<=100.0)
(gdb) l
21	         {
22		   printf("honours\n");
23	         }
24	  
25	      else  if(perc>=60.0 && perc<80.0)
26	         {
27		   printf("first division\n");
28	         }
29	    
30	       else if(perc>=50.0 && perc<60.0)
(gdb) l
31	         {
32		   printf("second division\n");
33	         }
34	     
35	       else if(perc>40.0 && perc<50.0)
36	         {
37		   printf("third division\n");
38	         }
39	    
40	        else
(gdb) l
41	         {
42		   printf("fail\n");
43	         }
44	   }
(gdb) l
Line number 45 out of range; 2_percentage.c has 44 lines.
(gdb) b 18
Breakpoint 1 at 0x778: file 2_percentage.c, line 18.
(gdb) b 35
Breakpoint 2 at 0x82e: file 2_percentage.c, line 35.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000778 in main at 2_percentage.c:18
2       breakpoint     keep y   0x000000000000082e in main at 2_percentage.c:35
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/2_percentage-gdb 
enter the t,h,e,m,s,ss marks :
78 67 76 78 76 77

Breakpoint 1, main () at 2_percentage.c:18
18		perc=(t+h+e+m+s+ss)/6.0;
(gdb) s
20	        if(perc<=80.0 && perc<=100.0)
(gdb) p perc
$1 = 75.3333359
(gdb) s
22		   printf("honours\n");
(gdb) s
_IO_puts (str=0x555555554934 "honours") at ioputs.c:33
33	ioputs.c: No such file or directory.
(gdb) c
Continuing.
honours
[Inferior 1 (process 7402) exited normally]
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/2_percentage-gdb 
enter the t,h,e,m,s,ss marks :
80 90 98 97 96 89

Breakpoint 1, main () at 2_percentage.c:18
18		perc=(t+h+e+m+s+ss)/6.0;
(gdb) p perc
$2 = 4.59163468e-41
(gdb) c
Continuing.

Breakpoint 2, main () at 2_percentage.c:35
35	       else if(perc>40.0 && perc<50.0)
(gdb) s
42		   printf("fail\n");
(gdb) s
_IO_puts (str=0x55555555496a "fail") at ioputs.c:33
33	ioputs.c: No such file or directory.
(gdb) c
Continuing.
fail
[Inferior 1 (process 7410) exited normally]
(gdb) q





*** 3 problem ***



/*** Find the biggest of n numbers, without using arrays.***/


(gdb) l
1	#include<stdio.h>
2	int main()
3	 {
4	   int n,a,b;
5	   printf("enter the n value:");
6	   scanf("%d",&n);
7	   printf("enter the 1:");
8	   scanf("%d",&a);
9	  for(int i=2;i<=n;i++)
10	    {
(gdb) l
11	       printf("enter the %d:",i);
12	       scanf("%d",&b);
13	         if(a<b)
14	           a=b;
15	    }
16	      printf("largest number is %d\n",a);
17	 }
18	           
19	  
(gdb) l
Line number 20 out of range; 3_large-n.c has 19 lines.
(gdb) b 9
Breakpoint 1 at 0x783: file 3_large-n.c, line 9.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000783 in main at 3_large-n.c:9
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/3_large-n-gdb 
enter the n value:6
enter the 1:78

Breakpoint 1, main () at 3_large-n.c:9
9	  for(int i=2;i<=n;i++)
(gdb) s
11	       printf("enter the %d:",i);
(gdb) n
12	       scanf("%d",&b);
(gdb) n
enter the 2:87 
13	         if(a<b)
(gdb) p a
$1 = 78
(gdb) p b
$2 = 87
(gdb) s
14	           a=b;
(gdb) s
9	  for(int i=2;i<=n;i++)
(gdb) p b
$3 = 87
(gdb) p a
$4 = 87
(gdb) s
11	       printf("enter the %d:",i);
(gdb) n
12	       scanf("%d",&b);
(gdb) n
enter the 3:60
13	         if(a<b)
(gdb) s
9	  for(int i=2;i<=n;i++)
(gdb) p a
$5 = 87
(gdb) p b
$6 = 60
(gdb) c
Continuing.
enter the 4:76
enter the 5:77
enter the 6:87
largest number is 87
[Inferior 1 (process 7549) exited normally]
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/3_large-n-gdb 
enter the n value:6
enter the 1:87

Breakpoint 1, main () at 3_large-n.c:9
9	  for(int i=2;i<=n;i++)
(gdb) watch a 
Hardware watchpoint 2: a
(gdb) watch b
Hardware watchpoint 3: b
(gdb) s
11	       printf("enter the %d:",i);
(gdb) n
12	       scanf("%d",&b);
(gdb) n
enter the 2:89

Hardware watchpoint 3: b

Old value = -8208
New value = 89
0x00007ffff7a519a4 in _IO_vfscanf_internal (s=<optimized out>, format=<optimized out>, argptr=argptr@entry=0x7fffffffde10, errp=errp@entry=0x0)
    at vfscanf.c:1898
1898	vfscanf.c: No such file or directory.
(gdb) s
1902	in vfscanf.c
(gdb) n
384	in vfscanf.c
(gdb) c
Continuing.

Hardware watchpoint 2: a

Old value = 87
New value = 89
main () at 3_large-n.c:9
9	  for(int i=2;i<=n;i++)
(gdb) s
11	       printf("enter the %d:",i);
(gdb) n
12	       scanf("%d",&b);
(gdb) n
enter the 3:78

Hardware watchpoint 3: b

Old value = 89
New value = 78
0x00007ffff7a519a4 in _IO_vfscanf_internal (s=<optimized out>, format=<optimized out>, argptr=argptr@entry=0x7fffffffde10, errp=errp@entry=0x0)
    at vfscanf.c:1898
1898	vfscanf.c: No such file or directory.
(gdb) c
Continuing.
enter the 4:89

Hardware watchpoint 3: b

Old value = 78
New value = 89
0x00007ffff7a519a4 in _IO_vfscanf_internal (s=<optimized out>, format=<optimized out>, argptr=argptr@entry=0x7fffffffde10, errp=errp@entry=0x0)
    at vfscanf.c:1898
1898	in vfscanf.c
(gdb) p a
No symbol "a" in current context.
(gdb) c
Continuing.
enter the 5:88

Hardware watchpoint 3: b

Old value = 89
New value = 88
0x00007ffff7a519a4 in _IO_vfscanf_internal (s=<optimized out>, format=<optimized out>, argptr=argptr@entry=0x7fffffffde10, errp=errp@entry=0x0)
    at vfscanf.c:1898
1898	in vfscanf.c
(gdb) 98
Undefined command: "98".  Try "help".
(gdb) c
Continuing.
enter the 6:98

Hardware watchpoint 3: b

Old value = 88
New value = 98
0x00007ffff7a519a4 in _IO_vfscanf_internal (s=<optimized out>, format=<optimized out>, argptr=argptr@entry=0x7fffffffde10, errp=errp@entry=0x0)
    at vfscanf.c:1898
1898	in vfscanf.c
(gdb) s
1902	in vfscanf.c
(gdb) c
Continuing.

Hardware watchpoint 2: a

Old value = 89
New value = 98
main () at 3_large-n.c:9
9	  for(int i=2;i<=n;i++)
(gdb) c
Continuing.
largest number is 98
(gdb) q




*** 4 problem ***



/*** Access variable value with pointer***/


(gdb) l
1	
2	
3	#include<stdio.h>
4	int main()
5	 {
6	    int a=10;
7	    int *p;
8	    //p=&a;
9	  
10	   printf("%d\n",*p);
(gdb) l
11	 }
(gdb) l
Line number 12 out of range; 4_pointer.c has 11 lines.
(gdb) b main
Breakpoint 1 at 0x652: file 4_pointer.c, line 6.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000652 in main at 4_pointer.c:6
(gdb) watch main
Cannot watch constant value `main'.
(gdb) watch a
No symbol "a" in current context.
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/4_pointer.gdb 

Breakpoint 1, main () at 4_pointer.c:6
6	    int a=10;
(gdb) watch a
Hardware watchpoint 2: a
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000555555554652 in main at 4_pointer.c:6
	breakpoint already hit 1 time
2       hw watchpoint  keep y                      a
(gdb) s

Hardware watchpoint 2: a

Old value = 32767
New value = 10
main () at 4_pointer.c:10
10	   printf("%d\n",*p);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
0x000055555555465d in main () at 4_pointer.c:10
10	   printf("%d\n",*p);
(gdb) p &a
$1 = (int *) 0x7fffffffdf04
(gdb) p p=0x7fffffffdf04
$2 = (int *) 0x7fffffffdf04
(gdb) s

Program terminated with signal SIGSEGV, Segmentation fault.
The program no longer exists.
(gdb) p *P
No symbol "P" in current context.
(gdb) c
The program is not being run.
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/4_pointer.gdb 

Breakpoint 1, main () at 4_pointer.c:6
6	    int a=10;
(gdb) p &a
$3 = (int *) 0x7fffffffdf04
(gdb) s
10	   printf("%d\n",*p);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
0x000055555555465d in main () at 4_pointer.c:10
10	   printf("%d\n",*p);
(gdb) p p=0x7fffffffdf04
$4 = (int *) 0x7fffffffdf04
(gdb) p *p
$5 = 10

Quit anyway? (y or n) y




*** 5 problem ***



*** call by value ****** call by value ****** call by value ****** call by value ****** call by value ****** call by value ****** call by value ****** call by value ***


(gdb) l
1	/*Write a program to swap two numbers using Call by Value and Call by Reference.*/
2	
3	#include<stdio.h>
4	void swap1(int ,int );
5	int main()
6	  {
7	    int a,b;
8	    printf("enter the a and b value:");
9	    scanf("%d%d",&a,&b);
10	    swap1(a,b);
(gdb) l
11	    printf("after call by value a:%d and b:%d \n",a,b);
12	 }
13	
14	void swap1(int p ,int q )
15	  {
16	    int t;
17	     t=p;
18	     q=p;
19	     p=t;
20	  }
(gdb) l
31	
(gdb) l
Line number 32 out of range; 5_call_by_value.c has 31 lines.
(gdb) p 8
$1 = 8
(gdb) p swap1 
$2 = {void (int, int)} 0x7a1 <swap1>
(gdb) i b
No breakpoints or watchpoints.
(gdb) b 8
Breakpoint 1 at 0x731: file 5_call_by_value.c, line 8.
(gdb) b swap1 
Breakpoint 2 at 0x7ab: file 5_call_by_value.c, line 17.
(gdb) i b'
Args must be numbers or '$' variables.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000731 in main at 5_call_by_value.c:8
2       breakpoint     keep y   0x00000000000007ab in swap1 at 5_call_by_value.c:17
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/5_call_by_value.gdb 

Breakpoint 1, main () at 5_call_by_value.c:8
8	    printf("enter the a and b value:");
(gdb) n
9	    scanf("%d%d",&a,&b);
(gdb) n
enter the a and b value:12 21
10	    swap1(a,b);
(gdb) s

Breakpoint 2, swap1 (p=12, q=21) at 5_call_by_value.c:17
17	     t=p;
(gdb) s
18	     q=p;
(gdb) s
19	     p=t;
(gdb) s
20	  }
(gdb) p p
$3 = 12
(gdb) p q
$4 = 12
(gdb) s
main () at 5_call_by_value.c:11
11	    printf("after call by value a:%d and b:%d \n",a,b);
(gdb) n
after call by value a:12 and b:21 
12	 }
(gdb) s
__libc_start_main (main=0x55555555471a <main>, argc=1, argv=0x7fffffffdff8, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, 
    stack_end=0x7fffffffdfe8) at ../csu/libc-start.c:344
344	../csu/libc-start.c: No such file or directory.
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/5_call_by_value.gdb 

Breakpoint 1, main () at 5_call_by_value.c:8
8	    printf("enter the a and b value:");
(gdb) n
9	    scanf("%d%d",&a,&b);
(gdb) n
enter the a and b value:12 32
10	    swap1(a,b);
(gdb) s

Breakpoint 2, swap1 (p=12, q=32) at 5_call_by_value.c:17
17	     t=p;
(gdb) s
18	     q=p;
(gdb) p p=q
$5 = 32
(gdb) s
19	     p=t;
(gdb) p q=t
$6 = 12
(gdb) s
20	  }
(gdb) p p
$7 = 12
(gdb) p q
$8 = 12
(gdb) s
main () at 5_call_by_value.c:11
11	    printf("after call by value a:%d and b:%d \n",a,b);
(gdb) n
after call by value a:12 and b:32 
12	 }
(gdb) q
A debugging session is active.

	Inferior 1 [process 7748] will be killed.

Quit anyway? (y or n) y




*** 6 problem ***




*** call by reference  ***


(gdb) l
1	/*Write a program to swap two numbers using Call by Value and Call by Reference.*/
2	
3	#include<stdio.h>
4	void swap2(int *,int *);
5	int main()
6	  {
7	    int a,b;
8	    printf("enter the a and b value:");
9	    scanf("%d%d",&a,&b);
10	    swap2(&a,&b);
(gdb) l
11	     printf("after call by reference a:%d and b:%d \n",a,b);
12	 }
13	
14	void swap2(int *p ,int *q )
15	  {
16	    int t;
17	     t=*p;
18	     *p=*q;
19	      *q=t;
20	  }
(gdb) l
Line number 30 out of range; 6_call_by_reference.c has 29 lines.
(gdb) b main 
Breakpoint 1 at 0x722: file 6_call_by_reference.c, line 6.
(gdb) b swap2 
Breakpoint 2 at 0x7b1: file 6_call_by_reference.c, line 17.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000722 in main at 6_call_by_reference.c:6
2       breakpoint     keep y   0x00000000000007b1 in swap2 at 6_call_by_reference.c:17
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/6_call_by_reference.gdb 

Breakpoint 1, main () at 6_call_by_reference.c:6
6	  {
(gdb) s
8	    printf("enter the a and b value:");
(gdb) n
9	    scanf("%d%d",&a,&b);
(gdb) n
enter the a and b value:76 32
10	    swap2(&a,&b);
(gdb) s

Breakpoint 2, swap2 (p=0x7fffffffdef0, q=0x7fffffffdef4) at 6_call_by_reference.c:17
17	     t=*p;
(gdb) s
18	     *p=*q;
(gdb) s
19	      *q=t;
(gdb) p *p
$1 = 32
(gdb) p *q
$2 = 32
(gdb) s
20	  }
(gdb) p *q
$3 = 76
(gdb) s
main () at 6_call_by_reference.c:11
11	     printf("after call by reference a:%d and b:%d \n",a,b);
(gdb) n
after call by reference a:32 and b:76 
12	 }
(gdb) y
Undefined command: "y".  Try "help".
(gdb) q
A debugging session is active.

	Inferior 1 [process 7815] will be killed.

Quit anyway? (y or n) y


*** 7 problem ***



*** super market ***

(gdb) l
1	/* WAP - for the 4 departments of a supermarket : Sales, Purchase, Stock and SuperMarket in four different source code files.
2	    Stock : Maintains a variable for available stock.
3	    Sales : Has one function: Sell – It will reduce the stock by the number of items sold. Before selling, check if enough stock is available.
4	    Purchase : Has one function : Purchase – will increase the stock by the number of items purchased.Set a max value for stock, before purchasing check if the stock room has enough space for new items or not.
5	
6	      SuperMarket : Display menu with choices : 1 ) check AvailableStock 2 ) Purchase new items 3) Sell items … this should be continuous as long as the user wants to continue. Program should stop when the user wants to quit.*/
7	
8	#include"all.h"
9	
10	 int x=100;
(gdb) l
11	int main()
12	 {
13	   int a,i=1;
14	   while(i)
15	     {
16	       printf("Enter 1.stock \n 2.sales \n 3.purchase \n 4.quit \n");
17	       scanf("%d",&a);
18	      
19	     switch(a)
20	       {
(gdb) l
21	         case 1: stock();
22	                  break;
23	         case 2: sales();
24	                 break;
25	  	 case 3: purchase();
26			 break;
27		 case 4: i=0;
28			 break;
29	         default: printf("invalid\n");
30	       }
(gdb) l
31	   }
32	 }
(gdb) l sales
1	
2	#include"all.h"
3	extern int x;
4	
5	 void sales()
6	  {
7	    int y;
8	    printf("ente the y value");
9	    scanf("%d",&y);
10	   
(gdb) l
11	   if(x>y)
12	    {
13	      x=x-y;
14	    }
15	    else
16	     {
17	       printf("we don't have that much stock-%d\n",y);
18	     }
19	 }
(gdb) l
Line number 20 out of range; sales.c has 19 lines.
(gdb) l purchase
1	
2	#include"all.h" 
3	extern int x;
4	
5	 void purchase()
6	  {
7	    int z;
8	    printf("enter the z value");
9	    scanf("%d",&z);
10	  
(gdb) l
11	   if(x+z<=100)
12	     {
13	       x=x+z;
14	     }
15	   
16	  else
17	    {
18	     printf("we don't need that much of packets-%d  need only-%d\n",z,100-x);
19	    }
20	 }
(gdb) l
Line number 21 out of range; purchase.c has 20 lines.
(gdb) l stock
2	#include"all.h"
3	
4	extern int x;
5	
6	void stock()
7	 {
8	   if(x<25)
9	     {
10	      printf("WARNING: we have less stock-%d\n",x);
11	     }
(gdb) l
12	    else
13	     {
14	      printf("stock - %d\n",x);
15	     }
16	 }
17	
(gdb) l
Line number 18 out of range; stock.c has 17 lines.
(gdb) b supermarket 14
Function "supermarket 14" not defined.
Make breakpoint pending on future shared library load? (y or [n]) n
(gdb) b main 14
Function "main 14" not defined.
Make breakpoint pending on future shared library load? (y or [n]) y
Breakpoint 1 (main 14) pending.
(gdb) b sales
Breakpoint 2 at 0x80f: file sales.c, line 6.
(gdb) b purchase
Breakpoint 3 at 0x772: file purchase.c, line 6.
(gdb) b 6
Breakpoint 4 at 0x89a: file stock.c, line 6.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   <PENDING>          main 14
2       breakpoint     keep y   0x000000000000080f in sales at sales.c:6
3       breakpoint     keep y   0x0000000000000772 in purchase at purchase.c:6
4       breakpoint     keep y   0x000000000000089a in stock at stock.c:6
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/7_supermarket/7_supermarket.gdb 
Enter 1.stock 
 2.sales 
 3.purchase 
 4.quit 
1

Breakpoint 4, stock () at stock.c:8
8	   if(x<25)
(gdb) s
14	      printf("stock - %d\n",x);
(gdb) n
stock - 100
16	 }
(gdb) s
main () at supermarket.c:22
22	                  break;
(gdb) s
14	   while(i)
(gdb) s
16	       printf("Enter 1.stock \n 2.sales \n 3.purchase \n 4.quit \n");
(gdb) n
Enter 1.stock 
 2.sales 
 3.purchase 
 4.quit 
17	       scanf("%d",&a);
(gdb) n
3
19	     switch(a)
(gdb) s
25	  	 case 3: purchase();
(gdb) s

Breakpoint 3, purchase () at purchase.c:6
6	  {
(gdb) s
8	    printf("enter the z value");
(gdb) n
9	    scanf("%d",&z);
(gdb) 40
Undefined command: "40".  Try "help".
(gdb) n
enter the z value40
11	   if(x+z<=100)
(gdb) s
18	     printf("we don't need that much of packets-%d  need only-%d\n",z,100-x);
(gdb) s
__printf (format=0x555555554a40 "we don't need that much of packets-%d  need only-%d\n") at printf.c:28
28	printf.c: No such file or directory.
(gdb) n
32	in printf.c
(gdb) f
#0  __printf (format=0x555555554a40 "we don't need that much of packets-%d  need only-%d\n") at printf.c:32
32	in printf.c
(gdb) n
33	in printf.c
(gdb) c
Continuing.
we don't need that much of packets-40  need only-0
Enter 1.stock 
 2.sales 
 3.purchase 
 4.quit 
2

Breakpoint 2, sales () at sales.c:6
6	  {
(gdb) s
8	    printf("ente the y value");
(gdb) n
9	    scanf("%d",&y);
(gdb) n
ente the y value56
11	   if(x>y)
(gdb) s
13	      x=x-y;
(gdb) s
19	 }
(gdb) p x
$1 = 44
(gdb) s
main () at supermarket.c:24
24	                 break;
(gdb) s
14	   while(i)
(gdb) s
16	       printf("Enter 1.stock \n 2.sales \n 3.purchase \n 4.quit \n");
(gdb) n
Enter 1.stock 
 2.sales 
 3.purchase 
 4.quit 
17	       scanf("%d",&a);
(gdb) 4
Undefined command: "4".  Try "help".
(gdb) n
4
19	     switch(a)
(gdb) s
27		 case 4: i=0;
(gdb) s
28			 break;
(gdb) s
14	   while(i)
(gdb) q
A debugging session is active.

	Inferior 1 [process 7957] will be killed.

Quit anyway? (y or n) y


*** 8 problem ***



 *** strstr ***


(gdb) l
1	
2	#include<stdio.h>
3	#include<string.h>
4	int main()
5	 {
6	   char str1[20],str2[20],p;
7	   scanf("%[^\n]s",str1);
8	   scanf(" %[^\n]s",str2);
9	  
10	   p=strstr(str1,str2);
(gdb) l
11	  printf("%s\n",p);
12	 }
(gdb) b main
Breakpoint 1 at 0x772: file 8_strstr.c, line 5.
(gdb) i b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000000772 in main at 8_strstr.c:5
(gdb) r
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/strstr.dbg 

Breakpoint 1, main () at 8_strstr.c:5
5	 {
(gdb) s
7	   scanf("%[^\n]s",str1);
(gdb) n
tarun
8	   scanf(" %[^\n]s",str2);
(gdb) n
ar
10	   p=strstr(str1,str2);
(gdb) s
__strstr_sse2 (haystack=0x7fffffffdeb0 "tarun", needle=0x7fffffffded0 "ar") at ../string/strstr.c:77
77	../string/strstr.c: No such file or directory.
(gdb) n
82	in ../string/strstr.c
(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
__strlen_sse2 () at ../sysdeps/x86_64/multiarch/../strlen.S:120
120	../sysdeps/x86_64/multiarch/../strlen.S: No such file or directory.
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/strstr.dbg 

Breakpoint 1, main () at 8_strstr.c:5
5	 {
(gdb) s
7	   scanf("%[^\n]s",str1);
(gdb) n
tarun
8	   scanf(" %[^\n]s",str2);
(gdb) n
ar
10	   p=strstr(str1,str2);
(gdb) n
11	  printf("%s\n",p);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
__strlen_sse2 () at ../sysdeps/x86_64/multiarch/../strlen.S:120
120	../sysdeps/x86_64/multiarch/../strlen.S: No such file or directory.
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/km/KM_GITLAB/km52aesd39/gdb_compiler/strstr.dbg 

Breakpoint 1, main () at 8_strstr.c:5
5	 {
(gdb) s
7	   scanf("%[^\n]s",str1);
(gdb) p p=*p
Cannot access memory at address 0x0
(gdb) q
A debugging session is active.

	Inferior 1 [process 8181] will be killed.

Quit anyway? (y or n) y

 ##date:26-10-2023                topic:debugging on high level language

  Debug the below programs using gdb and output of debugging copy and paste in text file and upload into gitlab server.

  Control statements:
  1. gdb-sample.c: class room example program, attached this mail.
  2. % grading with % as float.
  3. Find the biggest of n numbers, without using arrays.

   Pointers:
   4. Access variable value with pointer
   5. call by value
   6. call by reference

   Storage Classes/Functions:
   7. Super Market

   Strings:
   8. strstr() - sub string finding
