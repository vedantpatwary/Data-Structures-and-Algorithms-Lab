#include "tree.h"

Tree  createTree(void){
	Tree bt = (Tree)malloc(sizeof(struct tree));
	bt->right =NULL;
	bt->left =NULL;
	bt->height_balance =0;
	return bt;
}
Tree newNode(int data){
	Tree newNode = (Tree)malloc(sizeof(struct tree));
	newNode->data = data;
	newNode->left =NULL;
	newNode->right =NULL;
	newNode->height_balance=0;
	return newNode;
}

Tree addNode(Tree bt,Tree node){
	if(bt ==NULL)
		return node;
	
	if(node->data>=bt->data)
		bt->right = addNode(bt->right,node);

	else 
		bt->left = addNode(bt->left,node);
	
	bt->height_balance = height(bt->right) - height(bt->left);
	if(bt->height_balance<-1 || bt->height_balance>1){
		Tree x,y,z;
		z = bt;
		if(node->data>=bt->data)
			y = z->right;
		else
			y = z->left;
		if(node->data>=y->data)
			x = y->right;
		else
			x = y->left;
		bt = rotate(bt,x,y,z);
	}
		
	return bt;
}

Tree find(Tree bt,int data){
	if(bt ==NULL)
		return NULL;
	
	if(bt->data == data)
		return bt;
	
	if(bt->data<=data)
		return find(bt->right,data);

	else 
		return find(bt->left,data);
}

void inOrder(Tree bt){
	if(bt ==NULL)
		return;

	inOrder(bt->left);
	printf("%d bal = %d\n",bt->data,bt->height_balance);
	inOrder(bt->right);
}

Tree successor(Tree node){
	if(node->right !=NULL){
		Tree temp = node->right;
		while(temp->left !=NULL){
			temp = temp->left;
		}
		return temp;
	}
	return NULL;
}
//*********************GREATER TIME COMPLEXITY**********************************
/*
void delNode(Tree bt,Tree node,int data){
	Tree temp;
	Tree par;
	Tree temp2;
	temp = find(node,data);
	if(temp!=NULL){
		temp2 = successor(temp);
		if(temp2!=NULL){
			swapData(temp,temp2);
			delNode(bt,temp2,data);
		}
		else{
				par = parent(bt,temp);
			if(temp->left !=NULL){
				if(par->left == temp)
					par->left = temp->left;
				else
					par->right = temp->left;
			}
			else{
				par->left =NULL;
				par->right =NULL;
			}	
			free(temp);
		}
	}
}
*/


//*********************GREATER TIME COMPLEXITY**********************************

Tree parent(Tree bt,Tree node){
	if(bt ==NULL)
		return NULL;
	if(bt->left == node || bt->right == node)
		return bt;

	if(bt->data>node->data){
		return parent(bt->left,node);
	}

	else {
		return parent(bt->right,node);
	}
}
Tree deleteNode(Tree root, int data)
{
    if (root == NULL) return root;
 
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    else
    {
        if (root->left == NULL)
       {
          	Tree temp = root->right;
           	free(root);
       		return temp;
	  }
         if (root->right == NULL)
        {
            Tree temp = root->left;
            free(root);
            return temp;
        }
 
        Tree temp = successor(root);
 
        root->data = temp->data;
 
        root->right = deleteNode(root->right, temp->data);
    }
	root->height_balance = height(root->right) - height(root->left);
	if(root->height_balance>1 || root->height_balance<-1){
		Tree x,y,z;
		z = root;
		if(height(root->right)>=height(root->left))
			y = root->right;
		else
			y = root->left;
		if(height(y->right)>=height(y->left))
			x = y->right;
		else
			x = y->left;
		root = rotate(root,x,y,z);
	}
	
    return root;
}
/*
Tree deleteNode(Tree root,int data){
	Tree temp = NULL;
	Tree prev = NULL;
	Tree cur = root;
	while(cur !=NULL && cur->data !=data){
		prev = cur;
		if(data>cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}
	if(cur ==NULL) // element not found
		return root;
	else{
		if(cur->left ==NULL && cur->right ==NULL){// if leaf node,free and return 
			if(cur != root){
				if(cur==prev->left)
					prev->left =NULL;
				else
					prev->right =NULL;
				free(cur);
				return root;
			} // else if prev= NULL or cur =root
			free(cur);
			return NULL;
		}

		else if(cur->right ==NULL){
			if(cur != root){
				if(cur==prev->left)
					prev->left = cur->left;
				else
					prev->right =cur->left;
				free(cur);
				return root;
			}// else if prev =NULL
			free(cur);
			return cur->left;
		}
		else if(cur->left ==NULL){
			if(cur != root){
				if(cur==prev->left)
					prev->left = cur->right;
				else
					prev->right =cur->right;
				free(cur);
				return root;
			}// else if prev =NULL
			free(cur);
			return cur->right;
		}

		else{// both left and right exist
			temp = successor(cur); // successor will exist
				cur->data = temp->data;
				cur->right = deleteNode(cur->right,temp->data);
			
		}
	}
	return root;
}
*/
				
