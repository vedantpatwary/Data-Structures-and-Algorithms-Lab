compileE:	mainE.o GraphE.o
	gcc -g mainE.o GraphE.o -o testE

runE:
	./testE

compileA:	mainA.o GraphA.o
	gcc -g mainA.o GraphA.o -o testA

runA:
	./testA

mainA.o:	mainA.c
	gcc -c mainA.c

GraphA.o:	GraphA.c
	gcc -c GraphA.c

mainE.o:	mainE.c
	gcc -c mainE.c

GraphE.o:	GraphE.c
	gcc -c GraphE.c
