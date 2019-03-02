#include "header.h"

int main(void){
	int x=5;
	FILE *out = fopen("Out.txt","w");
	//fprintf(out,"100000:");
	//FILE *fp = fopen("100000","r");
	//measureTS(fp,out,&x);
	fprintf(out,"10000: ");
	FILE *fp = fopen("10000","r");
	measureTS(fp,out,&x);
	fp = fopen("1000","r");
	fprintf(out,"1000:  ");
	measureTS(fp,out,&x);
	fprintf(out,"100:   ");
	fp = fopen("100","r");
	measureTS(fp,out,&x);
	fprintf(out,"10:    ");
	fp = fopen("10","r");
	measureTS(fp,out,&x);
	fclose(out);
}

