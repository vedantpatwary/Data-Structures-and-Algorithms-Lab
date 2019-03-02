compile:	imple.o main.o 
	gcc -g main.o imple.o -o test

main.o:	main.c
	gcc -c -g main.c

imple.o:	imple.c
	gcc -c -g imple.c
