#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

void readD(char *st,char s);

int main(void){
	char str[2000] = "/home/vedu/study";
	readD(str,DT_DIR);
}

void readD(char *st,char s){
	if(s == DT_REG){
		printf("%s \n",st);
		return;
	}
	char str[2000];
	char buffer[2000];
	strcpy(str,st);
	strcpy(buffer,st);
	DIR *dir = opendir(str);
	if(dir ==NULL)
		return;
	struct dirent dir_new;
	struct dirent * d2 = &dir_new;
	int x = readdir_r(dir,&dir_new,&d2);
	while(d2!=NULL){
	/*	if(dir_new.d_name[0] == '.'){		// to ignore hidden files
			x = readdir_r(dir,&dir_new,&d2);
			continue;
		}
*/
		if(dir_new.d_type == DT_BLK){
			x = readdir_r(dir,&dir_new,&d2);
			continue;
		}
	
		if(x!=0 || strcmp(dir_new.d_name,"..") ==0 || strcmp(dir_new.d_name,".")==0){
			x = readdir_r(dir,&dir_new,&d2);
			continue;
		}
		char s = dir_new.d_type;
	
		printf("\n");
		strcat(buffer,"/");
		strcat(buffer,dir_new.d_name);
		readD(buffer,s);
		strcpy(buffer,str);
		x = readdir_r(dir,&dir_new,&d2);
	}
	closedir(dir);
}
	
