#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
struct student{
	char name[11];
	float cgpa;
};

typedef struct student *Student;

void readnMake(FILE *fp,int k);
void mergeSort(FILE *fp,int size);
void mergeFiles(FILE *fp1,FILE *fp2);
