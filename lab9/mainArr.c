#include "treeArr.h"
#include "iterArr.h"
#include "stack.h"

int maxHeight = 10;
int X = 0;

int main(void){
	srand(time(0));
	Tree gt = createNode();
	int r = randomNo();
	gt->child_head = createTree(r,1);
	gt->it->cur = 0;
	gt->it->head = gt->child_head;
	gt->it->size = r;
	printf("bfs:");
	bfs(gt);
	printf("\n\n");
	printf("dfs:");
	dfs(gt);
	return 0;
}
