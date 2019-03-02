#include "header.h"

int main(void){
	//char s[] = "abcdefsdhbshbs";
	//int x = hash(s,31,101);
	//printf("%d \n",x);
	//char *s[] = {"abjsncdfgh","abjncdefhg","jsndhfbdsdjfnsd","sjfnfdsk"};
	//int x = collisionCount(s,22698,5000081,5000);
	//printf("%d \n",x);
	FILE *fp = fopen("aliceinwonderland.txt","r");
	int no_strings=0;
	char **s = parser(fp,&no_strings);
	for(int i=0;i<no_strings;i++){
		printf("%s\n",s[i]);
	}
	printf("No of words:%d\n",no_strings);
	selectBest(s,22698);
}
