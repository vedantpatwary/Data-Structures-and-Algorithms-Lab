#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

extern int maxHeight;
typedef struct iterator *Iterator;

typedef struct tree *Tree;
struct tree{
	int val;
	Iterator it;
	Tree child_head;
	int no_child;
};	

typedef Tree Element;

Tree createTree(int no_of_children,int height);
bool isEmptyTree(Tree t);
int getRootVal(Tree t);
Iterator getChildren(Tree t);
int randomNo(void);
int randNo(void);
Tree createNode(void);
Tree createList(int r);
Iterator createIterator(void);
void dfs(Tree root);
void bfs(Tree root);


