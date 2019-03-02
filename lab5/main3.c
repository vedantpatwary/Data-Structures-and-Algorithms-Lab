#include "header.h"

int main(void){
	FILE *fp = fopen("1024.txt","r");
	if(fp==NULL){
		printf("cant open file!");
		return 1;
	}
	mergeSortByFiles(fp,1024);
	fp = fopen("10240.txt","r");
	mergeSortByFiles(fp,10240);
	fp = fopen("10240.txt","r");
	mergeSortByFiles(fp,10240);
	//fp = fopen("102400.txt","r");
	//mergeSortByFiles(fp,102400);
	//fp = fopen("1024000.txt","r");
	//mergeSortByFiles(fp,1024000);
	//fp = fopen("10240000.txt","r");
	//mergeSortByFiles(fp,10240000);
	//fp = fopen("102400000.txt","r");
	//mergeSortByFiles(fp,102400000);
}

