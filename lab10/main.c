#include "adjLGraph.h"
#include "Queue.h"

int main(void){
	FILE *fp = fopen("mylocalfile","r");
	if(fp ==NULL){
		printf("could not open file\n");
		return -1;
	}
	

