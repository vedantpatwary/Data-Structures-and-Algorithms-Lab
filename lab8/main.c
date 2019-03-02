#include "tree.h"
#include "header2.h"

int main(void){
	int x;
	struct timeval t1,t2;
	double elapsedTime;
		srand(time(0));
	Tree bt = NULL;
	Tree node = NULL;
/*	int arr[] ={153, 166, 169,164,161,151,167,163,162,160,165,158,165,162,164,150,157,159,165,150,168,159,169,162,150,162,163,165,168,150,155,170,164,152,161,154,153,157,167,163,167,160,150,159,151,162,160,158,150,152}; 
*/
	for(int i=0;i<10000;i++){
		x = random_no();
	//	printf("%d ",x);
	//	x = arr[i];
		node = newNode(x);
		bt = addNode(bt,node);
	}
	printf("\n");
	printf("count:%d \n",count(bt));
	printLevelOrder(bt);
	//inOrder(bt);
	gettimeofday(&t1,NULL);
	for(int i=0;i<5000;i++){
		x = random_no();
	//	x = ((arr[i]%10)*11)%50;
		//printf("%d ",x);
		bt = deleteNode(bt,x);
	}

	printf("after delete:\n");
	//inOrder(bt);
	printf("count:%d \n",count(bt));
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime+= (t2.tv_usec - t1.tv_usec)/1000;
	printLevelOrder(bt);
	printf("%f \n",elapsedTime);
	
	//rotate(bt,bt,bt->right,bt->left);
	//Tree k = inorder(bt,500);
	//int c = count(bt);
	//printf("count:%d \n",c);
	//if(k!=NULL)
	//printf("k:%d \n",k->data);
	Tree *T = (Tree*)malloc(sizeof(Tree));
	int k1 = 155;
	int k2 = 165;
	int count =0;

	T = rangeSearch(bt,k1,k2,&count,T);
	printf("Range search in %d and %d:\n",k1,k2);
	for(int i=0;i<count;i++){
		printf("%d\n",T[i]->data);
	}
	printf("\n");
	return 0;

}
