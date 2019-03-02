compile1:	tree.o imple.o main.o use.o level.o
	gcc -g tree.o main.o imple.o use.o level.o -o test1

compile2:	tree1.o imple.o main.o use.o stack.o level.o
	gcc -g tree1.o main.o imple.o use.o level.o stack.o -o test2

run1:	tree.o imple.o main.o use.o
	./test1

run2:	tree1.o imple.o main.o use.o
	./test2

tree.o:	tree.c
	gcc -g -c tree.c

tree1.o:	tree1.c
	gcc -g -c tree1.c

imple.o:	imple.c
	gcc -g -c imple.c

main.o:	main.c
	gcc -g -c main.c

use.o:	use.c
	gcc -g -c use.c

stack.o:	stack.c stack.h tree.h
	gcc -g -c stack.c
level.o:	level.c header2.h tree.h
	gcc -g -c level.c
clean:
	rm -rf *.o
