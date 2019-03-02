compRecMS:	main.o	readFile.o	mergeSortRec.o	merge.o
	gcc -g main.o readFile.o mergeSortRec.o merge.o -o test1

compIterMS:	main.o	readFile.o	mergeSortIter.o	merge.o
	gcc -g main.o readFile.o mergeSortIter.o merge.o -o test2

ex3:	main3.o	read3.o	mergeSortRec.o	merge.o
	gcc -g main3.o read3.o mergeSortRec.o merge.o -o test3

merge.o:	merge.c
	gcc -c -g merge.c

readFile.o:	readFile.c
	gcc -c -g readFile.c

mergeSortRec.o:	mergeSortRec.c
	gcc -c -g mergeSortRec.c

mergeSortIter.o:	mergeSortIter.c
	gcc -c -g mergeSortIter.c

main.o:	main.c
	gcc -c -g main.c

runIterMS:	
	./test2

runRecMS:	
	./test1

read3.o:	read3.c
	gcc -c -g read3.c

main3.o:	main3.c
	gcc -c -g main3.c

clean:
	rm -rf *.o test3
