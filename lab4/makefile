compile:	readRecords.o insertionSort.o measureTS.o main.o header.h
	gcc -g main.o readRecords.o insertionSort.o measureTS.o -o test

run:
	./test

readRecords.o:	readRecords.c
	gcc -g -c  readRecords.c 

measureTS.o:	measureTS.c
	gcc -g -c measureTS.c 

insertionSort.o:	insertionSort.c
	gcc -g -c insertionSort.c 

main.o:	main.c
	gcc -g -c main.c 

clean:
	rm -rf *.o test
