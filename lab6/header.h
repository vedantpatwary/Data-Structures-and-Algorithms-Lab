#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<stdbool.h>
struct emp{
	char name[11];
	long int empID;
};
typedef struct emp *Employee;
struct stack{
	int low;
	int high;
};
typedef struct stack *Stack;

struct stackp{
	int sz;
	Stack s;
};
typedef struct stackp *StackP;

StackP newStack(int size);
void printArr(Employee e,int size);
Employee createArr(int size);
void readFile(Employee e,FILE *fp);
void QuickSort(Employee e,int low,int high,int size);
StackP push(StackP sp,struct stack s1);
StackP pop(StackP sp);
struct stack top(StackP sp);
bool isEmpty(StackP sp);
void swap(Employee e1,Employee e2);
int pivot(Employee e,int low,int high);
int partition(Employee e,int low,int high,int p);
