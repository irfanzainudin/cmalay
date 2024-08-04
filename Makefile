all: prereq main

prereq:
	echo "compiling prereqs..."
	gcc -c utama.c

# more concise way without generating .o files: gcc utama.c -o cmalay
main:
	gcc utama.o -o cmalay
	gcc اوتام.c -o cjawi
	gcc utamo.c -o cklate

clean:
	rm *.o cmalay cjawi cklate a.out