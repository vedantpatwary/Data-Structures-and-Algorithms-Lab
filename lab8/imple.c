#include "tree.h"

int random_no(void){
	//srand(time(0));
	int randno = rand() % (170-150+1)+150;
	return randno;
}

void swapData(Tree t1,Tree t2){
	int temp = t1->data;
	t1->data = t2->data;
	t2->data = temp;
}

int height(Tree bt){
	if(bt ==NULL)
		return 0;
	int lHeight = height(bt->left);
	int rHeight = height(bt->right);
	if(lHeight>rHeight)
		return lHeight+1;
	else
		return rHeight+1;
}

int max(int x,int y){
	if(x>y)
		return x;
	return y;
}

	


