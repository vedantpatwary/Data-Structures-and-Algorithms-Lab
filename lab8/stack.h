#include<stdbool.h>
#ifndef NODE
struct node{
	Tree bt;
	struct node *next;
};
#endif
typedef struct node *Node;

struct stack{
	Node head;
	Node tail;
	int count;
};

typedef struct stack *Stack;

Stack createStack(void);
Stack push(Stack s,Tree bt);
Stack pop(Stack s);
Tree top(Stack s);
bool isEmptyS(Stack s);
	
