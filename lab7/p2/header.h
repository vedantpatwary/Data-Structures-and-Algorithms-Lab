#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//extern int insertionCost;
//extern int queryingCost;

int hash(char *s,int base_sz,int table_sz);
int collisionCount(char *s[],int no_strings,int base_sz,int table_sz);
bool isValid(char *s);
char** parser(FILE *fp,int *no_strings);
void selectBest(char *s[],int no_strings);
int insertAll(Table sl,char **book,int base_sz,int table_sz,int no_strings);
int insert(Table sl,char **book,int j,int base_sz,int table_sz,int insertionCost);
Table createTable(int table_sz);
int elementCount(Table sl,int table_sz);
void printTable(Table sl,char **Book,int table_sz);
int lookup(Table sl,char **Book,char *s,int base_sz,int table_sz,int queryingCost);
int lookupAll(Table sl,char **Book,char **strings,int no_strings,int base_sz,int table_sz,float m);

char **readFile(FILE *fp,int *no_stop);
int lookupAll(Table sl,char **Book,char **strings,int no_strings,int base_sz,int table_sz,float m);
void cleanup(Table sl,char **Book,char **strings,int base_sz,int table_sz,int no_strings,int no_stop);
void delete(Table sl,char **Book,char **s,int j,int base_sz,int table_sz,int no_strings);

