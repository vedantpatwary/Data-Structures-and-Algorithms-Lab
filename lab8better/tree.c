#include "tree.h"
#include "queue.h"
#include "stack.h"
#include "ll.h"

Tree newNode(int data){
	Tree t = (Tree)malloc(sizeof(struct tree));
	t->data = data;
	t->left =NULL;
	t->right =NULL;
	t->bal =0;
	t->height =1;
	return t;
}

int randomNo(void){
	int rand_no = rand()%(170-150+1)+150;
	return rand_no;
}	

Tree addNode(Tree root,int data){
	Tree newN = newNode(data);
	if(root ==NULL)
		return newN;
	Stack s = createStack();
	s = push(s,NULL);//used when root is the point of imbalance
	Tree temp = root;
	s = push(s,temp);
	while(1){
		if(data>=temp->data){
			if(temp->right!=NULL){
				temp = temp->right;
				s = push(s,temp);
			}
			else{
				temp->right = newN;
				break;
			}
		}
		else {
			if(temp->left !=NULL){
				temp = temp->left;
				s = push(s,temp);
			}
			else{
				temp->left = newN;
				break;
			}
		}
	}				//till now top of stack has parent of inserted node
	Tree x,y,z;
	temp =top(s);
	s = pop(s);
	Tree prevTop =temp;
	while(temp!=NULL){
		prevTop = temp;//prevTop is the node of imbalance
		temp = top(s);//temp is parent
		s = pop(s);
		
		updateHeight(prevTop);
		updateBalance(prevTop);
		
		
		if(prevTop->bal >1 || prevTop->bal<-1){
			z = prevTop;

			if(z->bal>1)
				y = z->right;
			else
				y = z->left;
		
			if(y->bal>=0)
				x = y->right;
			else
				x = y->left;
			
			if(temp ==NULL){//if root is imbalance
				root = rotate(root,x,y,z);
				return root;
			}

			if(prevTop == temp->right)
				temp->right = rotate(root,x,y,z);	

			else
				temp->left = rotate(root,x,y,z);

				
		}
		
	}

	return root;

}

void updateHeight(Tree root){
	if(root ==NULL)
		return;
	int h1 =0;
	int h2 =0;
	if(root->right !=NULL){
		h1 = root->right->height;
	}
	if(root->left !=NULL){
		h2 = root->left->height;
	}

	if(h1>=h2)
		root->height = h1+1;
	else
		root->height = h2+1;
}

void updateBalance(Tree root){
	if(root ==NULL)
		return ;
	int h1 =0;
	int h2 =0;
	if(root->right !=NULL){
		h1 = root->right->height;
	}
	if(root->left !=NULL){
		h2 = root->left->height;
	}

		root->bal = h1-h2;
}

Tree find(Tree root,int data){
	while(root->data != data){
		if(data>root->data)
			root = root->right;
		else if(data<root->data)
			root = root->left;
		else
			return root;
	}
	return NULL;
}

	
void bfs(Tree root){
	Queue q = createQueue();
	q = enque(q,root);
	Tree temp;
	while(!isEmptyQ(q)){
		temp = front(q);
		q = deque(q);
		printf("%d bal:%d\n ",temp->data,temp->bal);
		if(temp->left !=NULL)
			q = enque(q,temp->left);
		if(temp->right !=NULL)
			q = enque(q,temp->right);
	}
}
	
	

Tree delNode(Tree root,int data){
	Stack s = createStack();
	Tree temp =root;
	while(temp!= NULL ){
		if(temp->data>data){
			s = push(s,temp);
			temp = temp->left;
		}
		else if(temp->data <data){
			s = push(s,temp);
			temp = temp->right;
		}
		else{// if temp is the node to be deleted
			Tree parent = top(s);//if parent is NULL,root is to be deleted 

			if(temp->left ==NULL && temp->right ==NULL){//if leaf node
				if(parent !=NULL){			
					if(temp->data<parent->data)
						parent->left = NULL;

					else
						parent ->right =NULL;
				free(temp);
				return root;
				}
				free(temp);
				return NULL;

			}
			
			else if(temp->left ==NULL){//if only right child
				if(parent !=NULL){			
					if(temp->data<parent->data)
						parent->left = temp->right;

					else
						parent ->right =temp->right;
				free(temp);
				return root;
				}
				free(temp);
				return temp->right;
			}

			else if(temp->right ==NULL){//if only left child
				if(parent !=NULL){			
					if(temp->data<parent->data)
						parent->left = temp->left;

					else
						parent ->right = temp->left;
				free(temp);
				return root;
				}
				free(temp);
				return temp->left;
			}	
			else{//if both child present
				Tree temp2 = successor(temp);
				temp->data = temp2->data;
				s = push(s,temp);
				temp->right = delNode(temp->right,temp->data);
				break;// to get out of iteration
			}
		}
	}// now top of stack has parent of deleted point
	if(temp ==NULL){// element not found
		return root;
	}
	Tree x,y,z;
        temp =top(s);
        s = pop(s);
        Tree prevTop =temp;
        while(temp!=NULL){
                prevTop = temp;//prevTop is the node of imbalance
                temp = top(s);//temp is parent
                s = pop(s);

                updateHeight(prevTop);
                updateBalance(prevTop);


                if(prevTop->bal >1 || prevTop->bal<-1){
                        z = prevTop;

                        if(z->bal>1)
                                y = z->right;
                        else
                                y = z->left;

                        if(y->bal>=0)
                                x = y->right;
                        else
                                x = y->left;

                        if(temp ==NULL){//if root is imbalance
                                root = rotate(root,x,y,z);
                                return root;
                        }

                        if(prevTop == temp->right)
                                temp->right = rotate(root,x,y,z);

                        else
                                temp->left = rotate(root,x,y,z);

                 
                }
         
        }

	return root;
}

Tree successor(Tree root){
	Tree temp = root->right;
	while(temp->left !=NULL)
		temp = temp->left;
	
	return temp;
}


int inorder(Tree bt,int k){
	Stack s  = createStack();
	Tree temp = bt;
	while(temp!=NULL){
		s = push(s,temp);
		temp = temp->left;
	}
	while(!isEmptyS(s)){
		temp = top(s);
		s = pop(s);
		k--;
		if(k==0)
			return temp->data;
		if(temp->right !=NULL){
			temp = temp->right;
			while(temp !=NULL){
				s= push(s,temp);
				temp = temp->left;
			}
		}
	}
}
	
void printInOrder(Tree root){
	if(root ==NULL)
		return;
	printInOrder(root->left);
	printf("%d ",root->data);
	printInOrder(root->right);
}
	

List rangeSearch(Tree bt,int k1,int k2,List l){
	if(bt==NULL)
		return l;
	
	if(bt->data>k2)
		l = rangeSearch(bt->left,k1,k2,l);
	if(bt->data<k1)
		l = rangeSearch(bt->right,k1,k2,l);

	if(bt->data>=k1 && bt->data <=k2){
		l = rangeSearch(bt->left,k1,bt->data,l);
		l = addL(l,bt->data);
		l = rangeSearch(bt->right,bt->data,k2,l);
	}
	return l;
}

