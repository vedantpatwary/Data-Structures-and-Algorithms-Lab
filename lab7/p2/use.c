#include "SeqList.h"
#include "header.h"


Table createTable(int table_sz){
	Table sl = (SeqList)malloc(sizeof(struct seqList)*table_sz);
	SeqList temp;
	for(int i=0;i<table_sz;i++){
		temp = sl+i;
		temp = newList();
	}
	return sl;
}

int insert(Table sl,char **Book,int j,int base_sz,int table_sz,int insertionCost){
	int table_index = hash(Book[j],base_sz,table_sz);
	SeqList temp = sl + table_index;
	if(temp->count == 0){
		Element e =newElement(j);
		insertionCost = insertAtEndCost(temp,e,insertionCost);
		return insertionCost;
	}
	Element e = find(sl+table_index,Book,j);
	if(e == NULL){
		Element ele = newElement(j);
		SeqList temp = sl+table_index;
		insertionCost = insertAtEndCost(sl+table_index,ele,insertionCost);
	}
	else{
		temp->count++;
		e->count++;
	}
	return insertionCost;
}
			
int elementCount(Table sl,int table_sz){
	Table temp;
	int count=0;
	for(int i=0;i<table_sz;i++){
		temp = sl+i;
		count+=temp->count;
	}
	return count;
}

int insertAll(Table sl,char **Book,int base_sz,int table_sz,int no_strings){
	int insertionCost =0;
	for(int i=0;i<no_strings;i++)
		insertionCost = insert(sl,Book,i,base_sz,table_sz,insertionCost);
	return insertionCost;
}
	
void printTable(Table sl,char **Book,int table_sz){
	for(int i=0;i<table_sz;i++){
		printf("Table[%d] : ",i);
		printList(sl+i,Book);
		printf("\n");
	}
}

int lookup(Table sl,char **Book,char *s,int base_sz,int table_sz,int queryingCost){
	int table_index = hash(s,base_sz,table_sz);
	Table t = (sl+table_index);
	Element e = t->head;
	while(e!=NULL){
		queryingCost++;
		if(strcmp(Book[e->index],s)==0){
			return queryingCost;
		}
		e = e->next;
	}
	return queryingCost;
}
	
	
int lookupAll(Table sl,char **Book,char **strings,int no_strings,int base_sz,int table_sz,float m){
	int queryingCost=0;
	for(int i=0;i<no_strings*(m);i++){
		queryingCost = lookup(sl,Book,strings[i],base_sz,table_sz,queryingCost);
	}
	return queryingCost;
}
	
void cleanup(Table sl,char **Book,char **strings,int base_sz,int table_sz,int no_strings,int no_stop){
	int table_index;
	for(int i=0;i<no_stop;i++){
		delete(sl,Book,strings,i,base_sz,table_sz,no_strings);
	}
}

void delete(Table sl,char **Book,char **s,int j,int base_sz,int table_sz,int no_strings){
	int table_index = hash(s[j],base_sz,table_sz);
	Element e = findString(sl+table_index,Book,s,j);
	if(e ==NULL)
		return;
	else{
		deleted(sl,e);
	}
}
