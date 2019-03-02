#include "tree.h"
#include "header2.h"
/*int height(Tree bt){
	if(bt ==NULL)
		return 0;
	else{
		int lheight = height(bt->left);
		int rheight = height(bt->right);

		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}
*/

void printLevelOrder(Tree bt){
	int h = height(bt);
	for(int i=1;i<=h;i++){
		printLevel(bt,i);
		printf("\n");
	}
}

void printLevel(Tree bt,int level){	
	if(bt ==NULL)
		return;
	if(level ==1){
		printf("%d ",bt->data);
	}
	else{
		printLevel(bt->left,level-1);
		printLevel(bt->right,level-1);
	}
}
	
