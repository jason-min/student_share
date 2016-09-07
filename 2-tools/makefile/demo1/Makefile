


test: test.o 
	gcc -o test test.o

test.o: test.S
	gcc -c test.S -o test.o

test.S: test.i
	gcc -S test.i -o test.S

test.i: test.c
	gcc -E test.c -o test.i


clean:
	rm test  *.i *.S *.o


install:
	sudo cp test /usr/bin
