#include "header.h"
int f1(int arr[],int N){
	int sum=0;
	int i=0;
	while(i<N){
		sum+=arr[i];
		i++;
	}
	return sum;
}

int f2(int arr[],int N){
	int sum=0;
	int i=0;
	while(i<N){
		sum+=arr[i];
		i+=2;
	}
	return sum;
}

int f3(int arr[],int N){
	int sum=0;
	int i=0;
	while(i<N){
		sum+=(arr[i]*arr[i]);
		i+=1;
	}
	return sum;
}

int f4(int arr[],int N){
	int sum=0;
	int i=1;
	while(i<N){
		sum+=(arr[i]*arr[i]);
		i+=2;
	}
	return sum;
}
