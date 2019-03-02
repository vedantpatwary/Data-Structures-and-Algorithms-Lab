compile:	queue.o main.o tree.o stack.o use.o ll.o
	gcc -g queue.o main.o tree.o stack.o use.o ll.o -o test
run:
	./test

main.o: 	main.c
	gcc -g -c main.c

queue.o:	queue.c
	gcc -g -c queue.c

stack.o:	stack.c
	gcc -g -c stack.c

tree.o:	tree.c 
	gcc -g -c tree.c

use.o:	use.c
	gcc -g -c use.c
	
clean:
	rm -rf *.o

ll.o:	ll.c
	gcc -g -c ll.c
