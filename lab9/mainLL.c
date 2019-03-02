#include "treeLL.h"
#include "iterLL.h"

int maxHeight = 10;
int X = 0;

int main(void){
	srand(time(0));
	Tree gt = createNode();
	int r = randomNo();
	gt->child_head = createTree(r,1);
	gt->it->cur = gt->child_head;
	gt->it->head = gt->child_head;
	printf("bfs:");
	bfs(gt);
	printf("\n\n");
	printf("dfs:");
	dfs(gt);
	return 0;
}
