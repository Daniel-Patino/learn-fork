# -*- MakeFile -*-

all: Assign_6 clean run

Assign_6: Assign_6.o
	gcc main.o -o prog
	
Assign_6.o: main.o
	gcc -c main.c
	
run:
	./prog
	
clean:
	rm -f *.o