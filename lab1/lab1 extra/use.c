#include"header.h"

int use(int N){
	int *arr = (int*)malloc(sizeof(int)*N);
	int i=0;	
	for(i=0;i<N;i++){
		arr[i]=i;
	}
	int sum=0;
	sum+=(f1(arr,N)+f2(arr,N)+f3(arr,N)+f4(arr,N));
	return sum;
}
