#include "header.h"
void readnMake(FILE *fp,int k,int size){
 	int i=0;
	int j=1;
	Student arr = (Student)malloc(sizeof(struct student)*k);
	if(fp==NULL){
		return;
	}
	char filename[10];
	FILE *out = fopen("1","w");
	while(fscanf(fp,"%[a-z],%f\n",arr[i].name,&arr[i].cgpa) == 2){
		i++;
		if(i==k){
			mergeSort(arr,k);
			for(int z=0;z<k;z++){
				fprintf(out,"%s,%f\n",arr[z].name,arr[z].cgpa);
			}	
			fclose(out);
			j++;
			if(j<=size/k){
			sprintf(filename,"%d",j);
			out = fopen(filename,"w");
			}
			i=0;
		}
	}
	for(int z=0;z<i;z++){
		fprintf(out,"%s,%f\n",arr[z].name,arr[z].cgpa);
	}	

}

void mergeFiles(char f1[],char f2[]){
	char Out[50];
	FILE *fp1 = fopen(f1,"r");
	FILE *fp2 = fopen(f2,"r");
	if(fp1==NULL || fp2 ==NULL){
		printf("Couldnot open!\n");
		return;
	}	
	sprintf(Out,"%s,%s",f1,f2);
	FILE *out = fopen(Out,"w");
	struct student st1 ;
	struct student st2 ;
	int flag1 = fscanf(fp1,"%[a-z],%f\n",st1.name,&st1.cgpa);
	int flag2 = fscanf(fp2,"%[a-z],%f\n",st2.name,&st2.cgpa);

	while(flag1 ==2 && flag2 ==2){
		if(st1.cgpa<=st2.cgpa){
			fprintf(out,"%s,%f\n",st1.name,st1.cgpa);
			flag1 = fscanf(fp1,"%[a-z],%f\n",st1.name,&st1.cgpa);
		}
		else{
			fprintf(out,"%s,%f\n",st2.name,st2.cgpa);
			flag2 = fscanf(fp2,"%[a-z],%f\n",st2.name,&st2.cgpa);
		}
	}

	while(flag1==2){
			fprintf(out,"%s,%f\n",st1.name,st1.cgpa);
			flag1 = fscanf(fp1,"%[a-z],%f\n",st1.name,&st1.cgpa);
	}
	while(flag2==2){
			fprintf(out,"%s,%f\n",st2.name,st2.cgpa);
			flag2 = fscanf(fp2,"%[a-z],%f\n",st2.name,&st2.cgpa);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(out);
}

void mergeSortByFiles(FILE *fp,int size){
	int k=1024;
	char Out[20];
	readnMake(fp,k,size);	
	char f1[10];	
	char f3[10];	
	char f2[10];	
	int no_files = size/k;
	int i=0;
	struct timeval t1,t2;
	double elapsedTime;
	gettimeofday(&t1,NULL);
	while(no_files !=1){
		for(i=1;i<no_files;i+=2){
	 		sprintf(f1,"%d",i);
			sprintf(f2,"%d",i+1);
			mergeFiles(f1,f2);
			remove(f1);
			remove(f2);
			sprintf(Out,"%s,%s",f1,f2);
			sprintf(f3,"%d",(i+1)/2);
			rename(Out,f3);
		}
		if(no_files%2 !=0){
			sprintf(f1,"%d",i);
			sprintf(f2,"%d",(i+1)/2);
			rename(f1,f2);
		}	
		no_files = (no_files+1)/2;
	}
			sprintf(Out,"Ouput%d.txt",size);
			sprintf(f1,"%d",1);
			rename(f1,Out);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec-t1.tv_sec)*1000;
	elapsedTime+= (t2.tv_usec - t1.tv_usec)/1000;
	printf("%d:",size);
	printf("elapsedtime:%lf\n",elapsedTime);
}

