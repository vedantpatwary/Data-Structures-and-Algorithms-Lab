#include<stdio.h>

int bits;
void k(int n);
void d(void);
void h(void);
void p(void);
void g(void);
int main(void){
	p();
	return 0;
}

void p(void){
	int pilani;
	printf("pilani:%u\n",&pilani);
	g();
}

void g(void){
	int goa;
	printf("goa:%u\n",&goa);
	h();
}

void h(void){
	int hyd;
	printf("hyd;%u\n",&hyd);
	d();
}

void d(void){
	int dub;
	printf("dub;%u\n",&dub);
	k(1);
}

void k(int n){
	if(n==20) return;
	printf("n:%u\n",&n);
	k(++n);
}	

