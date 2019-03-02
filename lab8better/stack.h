#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree *Tree;
struct stack{
        Tree arr[1000];
        int index;
        int capacity;
};

typedef struct stack *Stack;

Stack createStack(void);
Stack push(Stack s,Tree t);
Stack pop(Stack s);
Tree top(Stack s);
bool isEmptyS(Stack s);
