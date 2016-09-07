

OBJ = test.o a.o

test: $(OBJ)
	gcc -o $@ $^

%.o:%.c
	gcc -c -o  $@ $<

.PHONY: clean

clean:
	rm *.o test
