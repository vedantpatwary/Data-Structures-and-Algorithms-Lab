#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct list *List;
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
	int bal;
	int height;
};

typedef struct tree *Tree;

Tree rotate(Tree root,Tree x,Tree y,Tree z);
Tree newNode(int data);
int randomNo(void);	
Tree addNode(Tree root,int data);
Tree delNode(Tree root,int data);
Tree find(Tree root,int data);
void bfs(Tree root);
Tree successor(Tree root);
void updateHeight(Tree root);
void updateBalance(Tree root);
int inorder(Tree bt,int k);
void printInOrder(Tree root);
List rangeSearch(Tree bt,int k1,int k2,List l);
