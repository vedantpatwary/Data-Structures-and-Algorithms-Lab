#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
struct student{
	char name[11];
	float cgpa;
};

typedef struct student *Student;

struct details
{
	unsigned long long int card_no;
	char bank_code[6];
	char date[8];
	char fname[6];
	char lname[6];
};

typedef struct details* Details;
Student readFile(FILE *fp,Student arr);
void readnMake(FILE *fp,int k,int size);
void printArr(Student arr,int size);
Student allocArray(int size);
void merge(Student arr1,int sz1,Student arr2,int sz2,Student arr);
void mergeSort(Student arr,int size,int *p,unsigned int *max);
void mergeSortByFiles(FILE *fp,int size);
void mergeFiles(char f1[],char f2[]);
void doEvery(FILE *fp,int size);
