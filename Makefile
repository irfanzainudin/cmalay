all: prereq main gld

prereq:
	echo "compiling prereqs..."
	gcc -c utama.c

# more concise way without generating .o files: gcc utama.c -o cmalay
main:
	gcc utama.o -o cmalay
	gcc اوتام.c -o cjawi
	gcc utamo.c -o cklate
	gcc utama.s

gld:
	gcc bfs.c -o bfs

clean:
	rm *.o a.out bfs cmalay cjawi cklate