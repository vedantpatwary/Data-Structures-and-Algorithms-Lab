#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int hash(char *s,int base_sz,int table_sz);
int collisionCount(char *s[],int no_strings,int base_sz,int table_sz);
bool isValid(char *s);
char** parser(FILE *fp,int *no_strings);
void selectBest(char *s[],int no_strings);
