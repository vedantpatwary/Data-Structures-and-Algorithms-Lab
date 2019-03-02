#include "header.h"

Credit createArr(void){
	Credit c = (Credit)malloc(100*sizeof(struct credit));
	return c;
}

CreditP storeDetails(CreditP cp,FILE *fp){
	Credit cre = cp->c;
	if(fp == NULL){
		printf("unable to open file");
		return 0;
	}

	int i=cp->Pcount;
	while(fscanf(fp,"%lld,%[A-Z],%[0-9/],%[a-z],%[a-z]",&cre[i].card_no,cre[i].bank_co,cre[i].exp,cre[i].fname,cre[i].lname) ==5){
		i++;
		cp->Pcount++;
		if(cp->Pcount == cp->Tcount){
			cp->c = (Credit)realloc((Credit)cre,sizeof(struct credit)*(cp->Tcount)*2);
			cp->Tcount*=2;
			cre = cp->c;
		}
	}
	return cp;
}
 
void printDetails(CreditP cp){
	Credit cre = cp->c; 
	if(cre ==NULL)
		return;
	for(int i=0;i<cp->Pcount ;i++){
		printf("Credit %d:",i);
		printf("card no %lld\n",cre[i].card_no);
		printf("bankco %s\n",cre[i].bank_co);
		printf("exp:%s\n",cre[i].exp);
		printf("fname:%s\n",cre[i].fname);
		printf("lname:%s\n",cre[i].lname);
	}
}

