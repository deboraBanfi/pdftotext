#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#define TAILLE_MAX 10000000
 
char * trouver_titre(char fichier){

     char ch=Null;
     ch = (char ) malloc(TAILLE_MAX sizeof(char));

     char * ligne;
     ligne  = (char) malloc(TAILLE_MAX sizeof(char));


      char * lien;
      lien = (char ) malloc(TAILLE_MAX sizeof(char));
      strcat(lien, "resultat/");
      strcat(lien, fichier);

      FILE * file = fopen(lien, "r");

     int i  =0;
     char * resultat;
     resultat = (char) malloc(TAILLE_MAX);
     while(fgets(ligne, TAILLE_MAX, file) != NULL){
         i++;
        if(strstr(ligne, ",")  strstr(ligne, "/")  strstr(ligne, "\n") || i==3){
            break;
        }
        else {
            strcat(resultat, ligne);
            strcat(resultat, " ");
        }
    }
    return resultat;
}
void FindAutor(char* c){

}
void FindAbstract(char* c){
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
	FILE * fdo =fopen("FichierPDF/FichierTXT/Torres.txt","a");
 	fputs(str1, fdo);
 	fclose(fdo);
 //printf("%s",str1);
}

void FindIntro(char* c){
	FILE* f;
	f=fopen(c,"rt");
	char* mot="Introduction";
	char* mot2 ="INTRODUCTION";
	while(fgets(c,100,f)!=NULL){
		char* trouve1 = strstr(c,mot);
		char* trouve2 = strstr(c,mot2);
		if(trouve1!=NULL && trouve2!=NULL){
			while(fgets(c,100,f)!=NULL && strstr(c, "II ")==NULL){
				printf("%s", c);
			}
		}
	}
}
void FindCorp(char* c){
    FILE* f;
    f=fopen(c,"rt");
    while(fgets(c, 100, f)!=NULL && strstr(c, "References")==NULL && strstr(c, "Conclusion")==NULL){
          printf("%s", c);
    }
    fclose(f);
}


int main(int argc, char **argv){
	//FindAbstract(argv[1]);
	FindIntro(argv[1]);

	//FindCorp(argv[1]);
	
}