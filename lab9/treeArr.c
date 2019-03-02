#include "iterArr.h"
#include "treeArr.h"
#include "stack.h"
#include "Queue.h"
extern int X;
Tree createTree(int no_of_children,int height){
	if(height==maxHeight)
		return NULL;
	Iterator tempIt = createIterator();
	Tree tempT = createList(no_of_children);
	tempIt->head = tempT;
	tempIt->size = no_of_children;
	tempIt->cur =0;
	Tree temp2;
	while(hasMoreElements(tempIt)){
		temp2 = getNextElement(tempIt);
		int r = randomNo();
		temp2->child_head = createTree(r,height+1);
		temp2->it->head = temp2->child_head;
		if(height+1 != maxHeight){
			temp2->it->size = r;
			temp2->it->cur =0;
		}
		else{
			temp2->it->size = 0;
			temp2->it->cur =-1;
		}
	}
	free(tempIt);
	return tempT;
}

bool isEmptyTree(Tree t){
	if(t==NULL)
		return true;
	return false;
}

int getRootVal(Tree t){
	if(t != NULL)
		return t->val;
	return 0;
}

Iterator getChildren(Tree t){
	if(t ==NULL)
		return NULL;
	return t->it;
}

int randomNo(void){// no of children
	int rand_no = rand()%(10-0+1)+0;
	return 2;
}

int randNo(void){ //value of tree node
	int rand_no = rand() % (500-0+1)+0;
	return ++X;
}

Tree createList(int r){ // returns pointer to an array of trees structure
	if(r==0)
		return NULL;
	Tree arr = (Tree)malloc(sizeof(struct tree)*r);
	for(int i=0;i<r;i++){
		arr[i].val = randNo();
		arr[i].child_head =NULL;
		arr[i].it = createIterator();
		arr[i].no_child =0;
	}
	return arr;
	
}

Tree createNode(void){// returns a tree pointer
	Tree node = (Tree)malloc(sizeof(struct tree));
	node->val = randNo();
	node->child_head =NULL;
	node->it = createIterator();
	node->no_child =0;
	return node;
}
	
Iterator createIterator(void){
	Iterator it = (Iterator)malloc(sizeof(struct iterator));
	it->cur =-1;
	it->head =NULL;
	it->size =0;
	return it;
}

void dfs(Tree root){	
		printf("%d ",root->val);
	Stack s = createStack();
	s = push(s,root->it);
	Iterator temp;
	Tree tempT;
	//int count =0;
	int flag = 0;
	while(!isEmptyS(s)){
		temp = top(s);

		if(hasMoreElements(temp)){
			tempT = getNextElement(temp);//selectNextNode(temp);
			printf("%d ",tempT->val);//visitNode
			s = push(s,tempT->it);//addMoreNodes(s,tempT->it)
		}
		else{
			temp->cur = 0;
			s = pop(s);
		}
		//printf("\n");
	}
	//	printf("count= %d",count);
	
}
		
void bfs(Tree root){
	printf("%d ",root->val);
	Queue q = createQueue();
	q = enque(q,root->it);
	Iterator temp = NULL;
	Tree tempT;
	while(!isEmptyQ(q)){
		temp = front(q);
		while(hasMoreElements(temp)){
			tempT = getNextElement(temp);//selectNextNode(Iterator temp);
			printf("%d ",tempT->val);//visitNode(Tree *n);
			if(tempT->it !=NULL)
				q = enque(q,tempT->it);//addMoreNodes(q,tempT->it)
		}
		temp->cur = 0;
		q = deque(q);
	}
	return ;
}
