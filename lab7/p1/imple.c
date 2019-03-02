#include "header.h"

int hash(char *s,int base_sz,int table_sz){
	int sum = 0;
	for(int i=0;i<strlen(s);i++){
		sum+=s[i];
	}
	return (sum%base_sz)%table_sz;
}

int collisionCount(char *s[],int no_strings,int base_sz,int table_sz){
	int arr[table_sz];
	int count=0;
	for(int i=0;i<table_sz;i++)
		arr[i] =0;
	for(int i=0;i<no_strings;i++)
		arr[hash(s[i],base_sz,table_sz)]++;
	for(int i=0;i<table_sz;i++){
		if(arr[i] >1){
			count+=arr[i]-1;
		}
	}
	return count;
}
	
char** parser(FILE *fp,int *no_strings){
	if(fp ==NULL){
		printf("FILE COULD NOT OPEN\n");
		return NULL;
	}
	char buffer[100];
	char **s = (char **)malloc(100*sizeof(char*));
	int sz=100;
	int i=0;
	while(fscanf(fp,"%s",buffer)==1){
		if(isValid(buffer) == true){
			if(i==sz){
				s=(char**)realloc(s,sz*2*sizeof(char*));
				sz*=2;
			}
			//printf("%s\n",buffer);
			s[i] = (char*)malloc(strlen(buffer)+1);
			strcpy(s[i],buffer);
			i++;
			
		}
	}
	*no_strings =i;
	return s;	
}

bool isValid(char *s){
	for(int i=0;i<strlen(s);i++){
		if(isalpha(s[i])==0)
			return false;
	}
	return true;
}

void selectBest(char *s[],int no_strings){
	int table_sz = 5000;
	int count[18] ;
	count[0] = collisionCount(s,no_strings,5407,5000);
	count[1] = collisionCount(s,no_strings,6563,5000);
	count[2] = collisionCount(s,no_strings,8059,5000);
	count[3] = collisionCount(s,no_strings,5000087,5000);
	count[4] = collisionCount(s,no_strings,5003101,5000);
	count[5] = collisionCount(s,no_strings,5003231,5000);

	printf("%d:",table_sz);
	for(int i=0;i<6;i++)
		printf("%d\n",count[i]);
	printf("\n");
	table_sz = 50000;
	count[6] = collisionCount(s,no_strings,50051,table_sz);
	count[7] = collisionCount(s,no_strings,75389,table_sz);
	count[8] = collisionCount(s,no_strings,95027,table_sz);
	count[9] = collisionCount(s,no_strings,50000063,table_sz);
	count[10] = collisionCount(s,no_strings,51000113,table_sz);
	count[11] = collisionCount(s,no_strings,6000057,table_sz);
	printf("%d:",table_sz);
	for(int i=6;i<12;i++)
		printf("%d\n",count[i]);

	printf("\n");
	table_sz = 500000;
	count[12] = collisionCount(s,no_strings,500057,table_sz);
	count[13] = collisionCount(s,no_strings,750083,table_sz);
	count[14] = collisionCount(s,no_strings,950039,table_sz);
	count[15] = collisionCount(s,no_strings,10000081,table_sz);
	count[16] = collisionCount(s,no_strings,1500047,table_sz);
	count[17] = collisionCount(s,no_strings,2000081,table_sz);
	printf("%d:",table_sz);
	for(int i=12;i<18;i++)
		printf("%d\n",count[i]);
}
