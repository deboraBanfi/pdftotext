#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
void FindAbstract(char* c, char* fichier){
	char str1[1000];
 	char str2[400];
 	char* l;
 	char* a;
 	char* f;
 	char ligne[200];
 	int i=0;
	FILE * fd = fopen(c,"r+");
	if(fd==NULL){
 		printf("errrr");
 		exit(0);
 	}
	l=(char*)malloc(400*sizeof(char));
	a=(char*)malloc(400*sizeof(char));
	f=(char*)malloc(400*sizeof(char));
 	while(fgets(ligne,200,fd)){
 		if(i==0){
 			l =strstr(ligne, "Abstract");
 			a =strstr(ligne, "ABSTRACT");
 			f =strstr(ligne, "University of Edinburgh");
 		}
 		if(l!=NULL && a!=NULL && f!=NULL ){
	 		i=1;
	 	}
	 	if(strstr(ligne,"Introduction") && strstr(ligne,"I NTRODUCTION") && strstr(ligne,"INTRODUCTION")){
	 		break;
		}
	 	if(!strstr(ligne, "University of Edinburgh")){
	 		strcat(str1, ligne);
	 	
	 	}
 //if(strstr(ligne,"I.")) break;
	}
	fclose(fd);
	printf("%s",str1);
	FILE * fdo =fopen(fichier,"a");
 	fputs(str1, fdo);
 	fclose(fdo);
}
int main(int argc, char **argv){
	FILE* file;
	file = fopen(argv[1],"a");
	fputs("<article>",file);
	fputs("<Abstract",file);
	FindAbstract(argv[2],argv[1])
	fputs("</Abstract");
	fputs("</article>",file);
	fclose(file);
	
}