#include "tree.h"

Tree rotate(Tree bt,Tree x,Tree y,Tree z){
	Tree a,b,c,T0,T1,T2,T3;
	if(z->left==y)
	{
		T3=z->right;
		if(y->left==x)
		{
			a=x;b=y;c=z;
			T0=x->left;T1=x->right;
			T2=y->right;
		}
		else
		{
			a=y;b=x;c=z;
			T0=y->left;
			T1=x->left;T2=x->right;
		}
	}
	else
	{
		T0=z->left;
		if(y->left==x)
		{
			a=z;b=x;c=y;
			T1=x->left;T2=x->right;
			T3=y->right;
		}
		else
		{
			a=z;b=y;c=x;
			T1=y->left;
			T2=x->left;T3=x->right;
		}
	}
	b->left=a;
        b->right=c;
        a->left=T0;
        a->right=T1;
        c->left=T2;
        c->right=T3;
	a->height_balance=height(T1)-height(T0);
	c->height_balance=height(T3)-height(T2);
	b->height_balance=height(c)-height(a);
	return b;

}
//****************************BUG*********************************************** 
// a<=b<=c 
	//*Tree *T = (Tree*)malloc(sizeof(Tree)*4);
	/*Tree T0 = NULL;
	Tree T1 = NULL;
	Tree T2 = NULL;
	Tree T3 = NULL;
	assign(x,y,z,&a,&b,&c,&T0,&T1,&T2,&T3);
	b->left =a;
	b->right =c;
	a->left =T0;
	a->right =T1;;
	c->left =T2;
	c->right =T3;
	a->height_balance = height(a->right) - height(a->left);
	b->height_balance = height(b->right) - height(b->left);
	c->height_balance = height(c->right) - height(c->left);
	return b;
}
void assign(Tree x,Tree y,Tree z,Tree *a,Tree *b,Tree *c,Tree *T0,Tree *T1,Tree *T2,Tree *T3){
*/
/*	if(x->data>=y->data && y->data >=z->data){	// x>=y>=z
		*a =z;
		*b =y;
		*c =x;
		*T0 = z->left;
		*T1 = y->left;
		*T2 = x->left;
		*T3 = x->right;
	}
	else if(x->data>=y->data && z->data>x->data){	//z>=x>=y
		*a =y;
		*b =x;
		*c =z;
		*T0 = y->left;
		*T1 = x->left;
		*T2 = x->right;
		*T3 = z->right;
	}
	else if(z->data>y->data && y->data>x->data){	//z>=y>=x
		*a =x;
		*b =y;
		*c =z;
		*T0 = x->left;
		*T1 = x->right;
		*T2 = y->right;
		*T3 = z->right;
	}
	else{						//y>=x>=z
		*a = z;
		*b =x;
		*c =y;
		*T0 = z->left;
		*T1 = x->left;
		*T2 = x->right;
		*T3 = y->right;
	}*/
	
//}
	
//************************BUG*****************************************
Tree inorder(Tree bt,int k){
	if(bt==NULL)
		return NULL;
	if(k==count(bt->left)+1)
		return bt;
	else if(k<count(bt->left)+1)
		return inorder(bt->left,k);		
	else
		return inorder(bt->right,k-count(bt->left)-1);

}

int count(Tree root){
	if(root == NULL)	
		return 0;
	int lCount = count(root->left);
	int rCount = count(root->right);
	
	return lCount+rCount+1;
}


Tree* rangeSearch(Tree bt,int k1,int k2,int *count,Tree *T){
	if(bt ==NULL)
		return T;
	if(bt->data>k2)
		T = rangeSearch(bt->left,k1,k2,count,T);
	else if(bt->data<k1)
		T = rangeSearch(bt->right,k1,k2,count,T);
	else{
		T = rangeSearch(bt->left,k1,bt->data,count,T);
		T = (Tree*)realloc(T,++(*count)*sizeof(Tree));
		T[*count-1] = bt;
		T = rangeSearch(bt->right,bt->data,k2,count,T);
	}
	return T;
}
