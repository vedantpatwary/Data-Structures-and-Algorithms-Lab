#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/time.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
	int height_balance;
};

typedef struct tree *Tree;

int random_no(void);
Tree addNode(Tree bt,Tree node);
Tree parent(Tree bt,Tree node);
void delNode(Tree bt,Tree node,int data);
Tree find(Tree bt,int data);
Tree createTree(void);
Tree newNode(int data);
void inOrder(Tree bt);
void swapData(Tree t1,Tree t2);
Tree deleteNode(Tree root,int data);
Tree rotate(Tree bt,Tree x,Tree y,Tree z);
void assign(Tree x,Tree y,Tree z,Tree *a,Tree *b,Tree *c,Tree *T0,Tree *T1,Tree *T2,Tree *T3);
int max(int x,int y);
int height(Tree bt);
int count(Tree bt);
Tree inorder(Tree bt,int K);
Tree* rangeSearch(Tree bt,int k1,int k2,int *count,Tree *T);
