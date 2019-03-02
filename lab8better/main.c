#include "tree.h"
#include "ll.h"

int main(void){
	srand(time(0));
	Tree bt = NULL;
	for(int i=0;i<1000;i++){
		int rand_no = randomNo();
		printf("%d\n",rand_no);
		bt = addNode(bt,rand_no);
	}
	bfs(bt);
	bt = delNode(bt,157);
	printf("after delete:\n");
	bfs(bt);
	printf("Inorder:");
	printInOrder(bt);
	int x = inorder(bt,8);

	printf("\n%d\n",x);
	int count =0;
	List l  =NULL;
	int k1=155;int k2 =160;
	l = rangeSearch(bt,k1,k2,l);
	printf("range search:");
	printL(l);

	
}
	
