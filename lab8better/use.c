#include "tree.h"

Tree rotate(Tree root,Tree x,Tree y,Tree z){
	Tree a,b,c,T0,T1,T2,T3;
	if(y==z->right){
		T0 = z->left;
		if(x==y->right){
			a = z;b=y;c=x;
			T1 = y->left;T2 = x->left;T3 = x->right;
		}
		else{
			a =z;b=x;c=y;
			T1 = x->left;T2 =x->right;T3 = y->right;
		}
	}
	else{
		T3 = z->right;
		if(x==y->left){
			a =x;b =y;c =z;
			T0 = x->left;T1 = x->right;T2 = y->right;
		}
		else{
			a = y;b=x;c=z;
			T0 = y->left;T1 = x->left;T2 = x->right;
		}
	}
			
	b->left =a;b->right = c;
	a->left =T0;a->right =T1;c->left = T2;c->right = T3;
	updateHeight(a);updateHeight(c);updateHeight(b);
	updateBalance(a);updateBalance(c);updateBalance(b);
	return b;
}
