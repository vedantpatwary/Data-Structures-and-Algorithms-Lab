/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* 
 * Simple HTTP GET that stores the web file in a local file
 
 Compile: gcc webread.c -lcurl -o mydownloader
 Execute: ./mydownloader
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjLGraph.h"
//#include <unistd.h>

//#include <curl/curl.h>
/*
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}
*/

int main(void)
{
	int m =211;
	Graph g = createGraph(m);
	char *s = "http://172.24.16.12/wiki/index.html";

	Vertex v1 = createVertex(s,"initial");
	//curl(s);
	//readFile(g,s,"initial");
	BFS(g,v1);
	//free(v1);

	printf("\n\n\n Graph Vertices:\n");
	print(g);
	return 0;
}

void readFile(Graph g,char *url,char *name){
	FILE *fp = fopen("mylocalfile","r");
	if(fp ==NULL)
		return;
	char buffer1[2000];
	char buffer2[2000];
	char buffer3[2000];
	int len = 0;
	Vertex v1 = createVertex(url,name);
	Vertex v2;
	int c =0;
	int arr[211] ={0};
	while(fscanf(fp,"%s",buffer1)==1){
		len = strlen(buffer1);
		if(buffer1[len-2] =='<' && buffer1[len-1]=='a'){
			fscanf(fp," %[^\"]",buffer2);
			if(strcmp(buffer2,"href=")==0){
				fscanf(fp,"\"%[^\"]",buffer1);// buffer1 is url
				strcpy(buffer3,"http://172.24.16.12/wiki/");//buffer3 is temporary
				strcat(buffer3,buffer1);
				strcpy(buffer1,buffer3);
				len = strlen(buffer3);
	//			printf("yes\n");
				if(!(buffer1[len-4]=='h' && buffer1[len-3] =='t' && buffer1[len-2]=='m' && buffer1[len-1] =='l'))//make sure html file
					continue;

				
				int x = fscanf(fp,"\">%[^<]",buffer2);//buffer2 is name
				if(x==1){
					c++;
					printf("%s",buffer1);
					printf(": %s ",buffer2);
					x = hash(buffer1);
					printf("%d\n",x);
					arr[x]++;
					if(g->numV<200){
						Vertex v1 = createVertex(url,name);
						v2 = createVertex(buffer1,buffer2);
						g = addEdge(g,v1,v2);
	//					break;
						free(v2);
						free(v1);
					}
					else
						break;
		//			printf("hash:%d\n",x);
				}
			}
		}
	}
	free(v1);
	//printf("%d ",c);
	fclose(fp);
//	system("rm mylocalfile");
	//print(g);
	//collisionCount(arr);
}

int hash(char *s){
	int m = 211;
	int a = 19;// gave the best for now
	int x = strlen(s);
	int y = 0;
	int sum = (int)s[0];
	int i=1;
	while(i!=x){
		sum = (sum*a+(int)s[i])%m;
		i++;
	}
	return sum;
}
		
void collisionCount(int *arr){
	int c1=0;
	int c2=0;
	int c3=0;
	int c4=0;
	for(int i=0;i<211;i++){
		if(arr[i] ==1)
			c1++;
		if(arr[i] ==2)
			c2++;
		if(arr[i] ==3)
			c3++;
		if(arr[i] ==4)
			c4++;
	}
	printf("%d %d %d %d",c1,c2,c3,c4);
}
