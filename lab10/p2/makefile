compile:	main.o	adjLGraph.o Queue.o webread.o useL.o
	gcc -g main.o adjLGraph.o Queue.o webread.o useL.o -lcurl -o test
run:	
	./test

main.o:	main.c
	gcc -g -c main.c

adjLGraph.o:	adjLGraph.c
	gcc -g -c adjLGraph.c

Queue.o:	Queue.c
	gcc -g -c Queue.c

webread.o:	webread.c
	gcc -g -c -lcurl webread.c 

useL.o:	useL.c
	gcc -g -c useL.c

clean:
	rm -rf *.o
