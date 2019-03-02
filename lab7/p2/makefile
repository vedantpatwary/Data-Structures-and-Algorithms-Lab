compile:	imple.o main.o  SeqList.o use.o 
	gcc -g main.o imple.o SeqList.o use.o -o test

main.o:	main.c SeqList.h header.h
	gcc -c -g main.c

imple.o:	imple.c SeqList.h header.h
	gcc -c -g imple.c
SeqList.o:	SeqList.c SeqList.h 
	gcc -c -g SeqList.c
use.o:	use.c SeqList.h header.h
	gcc -c -g use.c
