all: prereq main

prereq:
	echo "compiling prereqs..."
	gcc -c utama.c

# more concise way without generating .o files: gcc utama.c -o cmalay
main:
	gcc utama.o -o cmalay

clean:
	rm *.o cmalay