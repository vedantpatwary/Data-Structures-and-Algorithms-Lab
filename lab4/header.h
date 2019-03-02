#include<stdio.h>
#include<stdlib.h>

struct credit{
	long long card_no;
	char bank_co[6];
	char fname[6];
	char lname[6];
	char exp[8];
};

typedef struct credit *Credit;

struct CreditP{
	Credit c;
	int Tcount;
	int Pcount;
};
typedef struct CreditP *CreditP;

Credit createArr(void);
CreditP storeDetails(CreditP cre,FILE *fp);
void printDetails(CreditP cre);
void insertInOrder(Credit c,int n,struct credit nc);
void insertSort(Credit c,int n,FILE *out,int *p);
void measureTS(FILE *fp,FILE *out,int *p);
