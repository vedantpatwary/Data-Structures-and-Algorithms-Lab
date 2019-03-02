compileL:	adjLGraph.o mainL.o useL.o Queue.o 
	gcc -g adjLGraph.o mainL.o useL.o Queue.o -o testL

runL:	
	./testL

compileM:	adjMGraph.o mainM.o useM.o Queue.o
	gcc -g adjMGraph.o mainM.o useM.o Queue.o -o testM

runM:	
	./testM

adjLGraph.o:	adjLGraph.c
	gcc -g -c adjLGraph.c

adjMGraph.o:	adjMGraph.c
	gcc -g -c adjMGraph.c

mainL.o:	mainL.c
	gcc -g -c mainL.c

mainM.o:	mainM.c
	gcc -g -c mainM.c

useL.o:	useL.c
	gcc -g -c useL.c

useM.o:	useM.c
	gcc -g -c useM.c

clean:
	rm -rf *.o

Queue.o:	Queue.c
	gcc -g -c Queue.c
