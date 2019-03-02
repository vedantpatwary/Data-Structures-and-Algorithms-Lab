#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

struct list{
	int x;
	int y;
	struct list *next;
};

typedef struct list *List;

struct bucket{
	List next;
};

typedef struct bucket *Bucket;
