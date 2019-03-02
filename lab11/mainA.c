#include "GraphA.h"

int main(void){
	FILE *fp = fopen("graph0.txt","r");
	if(fp ==NULL){
		printf("Could not open file");
		return 1;
	}
	
	Graph g = createGraph(fp);
	printGraph(g);
}	
	
