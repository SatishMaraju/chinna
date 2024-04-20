static:st_calc

st_calc:main.o libcal.a 
	gcc -static main.o libcal.a -o st_calc
main.o:main.c
	gcc -c main.c
libcal.a:add.o sub.o
	ar -rcs libcal.a add.o sub.c 
add.o:add.c
	gcc -c add.c
sub.o:sub.c
	gcc -c sub.c

dynamic:dy_calc

dy_calc:main.o libcal.so 
	gcc main.o libcal.so -o dy_calc
main.o:main.c
	gcc -c main.c
libcal.so:div.o mul.o
	gcc -shared -o libcal.so mul.o div.o
div.o:div.c
	gcc -c -fpic div.c
mul.o:mul.c
	gcc -c -fpic mul.c
	

