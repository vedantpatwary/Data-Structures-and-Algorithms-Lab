#include "SeqList.h"
#include "header.h"
	//int insertionCost =0;
	//int queryingCost =0;

int main(void){
	//char s[] = "abcdefsdhbshbs";
	//int x = hash(s,31,101);
	//printf("%d \n",x);
	//char *s[] = {"abjsncdfgh","abjncdefhg","jsndhfbdsdjfnsd","sjfnfdsk"};
	//int x = collisionCount(s,22698,5000081,5000);
	//printf("%d \n",x);
	FILE *fp = fopen("aliceinwonderland.txt","r");
	int no_strings=0;
	char **Book = parser(fp,&no_strings);
	fclose(fp);
	for(int i=0;i<no_strings;i++){
		printf("%s\n",Book[i]);
	}
	printf("No of words:%d\n",no_strings);
	selectBest(Book,22698);
	int table_sz =5000;
	int base_sz = 10000;;
	Table sl = (Table)createTable(table_sz);
	int insertionCost = insertAll(sl,Book,base_sz,table_sz,no_strings);
	printTable(sl,Book,table_sz);
	printf("ElementCount:%d\n",elementCount(sl,table_sz));
	float m = 0.5;
	int queryingCost;
	int no_stop =0;


	fp = fopen("stopwords.txt","r");
	char **strings = readFile(fp,&no_stop);
	for(int i=0;i<no_stop;i++){
		printf("%s\n",strings[i]);
	}
	fclose(fp);


	for(float m =0.05;m<=1;m+=0.05){
		queryingCost = lookupAll(sl,Book,Book,no_strings,base_sz,table_sz,m);
		printf("m = %f\ninsertionCost = %d\t",m,insertionCost);
		printf("QueryingCost = %d\n\n",queryingCost);
	}
	cleanup(sl,Book,strings,base_sz,table_sz,no_strings,no_stop);

	printf("after cleanup\n");
	for(float m =0.1;m<=1;m+=0.1){
		queryingCost = lookupAll(sl,Book,Book,no_strings,base_sz,table_sz,m);
		printf("m = %f\ninsertionCost = %d\t",m,insertionCost);
		printf("QueryingCost = %d\n\n",queryingCost);

	}

	//printTable(sl,Book,table_sz);
	printf("%d",no_stop);
}
