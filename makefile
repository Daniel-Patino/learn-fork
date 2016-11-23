all: Assign_6 clean exe

Assign_6: Assign_6.o
	gcc Assign_6.o -o prog1
	
Assign_6.o: Assign_6.c
	gcc -c Assign_6.c 
	
exe:
	./prog1 0 1 2 3

clean:
	rm -f *.o