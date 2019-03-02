compileLL:	mainLL.o treeLL.o iterLL.o stack.o Queue.o
	gcc -g mainLL.o treeLL.o iterLL.o stack.o Queue.o -o test1 

runLL: 
	./test1

compileArr:	mainArr.o iterArr.o treeArr.o stack.o Queue.o
	gcc -g mainArr.o iterArr.o treeArr.o stack.o Queue.o -o test2 

runArr:
	./test2

mainLL.o:	mainLL.c iterLL.h treeLL.h
	gcc -g -c mainLL.c

mainArr.o:	mainArr.c iterLL.h treeLL.h
	gcc -g -c mainArr.c

iterLL.o:	iterLL.c iterLL.h treeLL.h
	gcc -g -c iterLL.c

treeLL.o:	treeLL.c iterLL.h treeLL.h
	gcc -g -c treeLL.c

iterArr.o:	iterArr.c iterArr.h treeArr.h
	gcc -g -c iterArr.c

treeArr.o:	treeArr.c iterArr.h treeArr.h
	gcc -g -c treeArr.c

stack.o:	stack.c stack.h iterLL.h
	gcc -g -c stack.c

Queue.o:	Queue.c Queue.h iterLL.h
	gcc -g -c Queue.c

clean:	
	rm -rf *.o
