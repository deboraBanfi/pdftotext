#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>

void  FindTitle(char* fichier){
	int TAILLE_MAX=10000;
 	char * ligne;
    ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
    char sortie[10000];
    FILE * file = fopen(fichier, "rt");
     
    int i  =0;
    while(fgets(ligne, 10000, file)){
        i++;
        if(strstr(ligne, ",") || strstr(ligne, "/") || strstr(ligne, "\\") || i==3){
            break;
        }     
        else {
            strcat(sortie, ligne);
            strcat(sortie, " ");
        }
    }
   	fclose(file);
   	FILE * fdo =fopen("fichiertest.txt","a");
 	fputs(sortie, fdo);
 	fclose(fdo);

}
void FindIntro(char* fichier){
	int TAILLE_MAX=10000;
 char * ligne;
     ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
      char sortie[100000];
      FILE * file = fopen(fichier, "r+");
      long  int j =0;
     long int i  =0;
     long int n ;
while(fgets(ligne, 1000, file)){
        
    if(strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION")|| strstr(ligne , "I NTRODUCTION"))
	{
                
        i= ftell(file);
    }


    if(strstr(ligne, "II.") || strstr(ligne, "2. ") || strstr(ligne, "Related work"))
    {
        j= ftell(file);

        n=j-i;
        break;
    }
                
            
}
fseek(file ,0, SEEK_SET);
fseek(file, i, SEEK_SET);

while(fgets(ligne, 1000, file)){
    n=n-1;
    strcat(sortie, ligne);
               
        
    if(ftell(file)==j){
        break;
    }

}
fclose(file);
FILE * fdo =fopen("fc.txt","a");
fputs(sortie, fdo);
fclose(fdo);
}

void FindAbstract(char* fichier){
 char str1[1000];
 char* l;
 char* a;
 char* c;
 char ligne[200];
 int i=0;
FILE * fd = fopen(fichier,"r+");
if(fd==NULL){
 printf("errrr");
 exit(0);}
l=(char*)malloc(400*sizeof(char));
a=(char*)malloc(400*sizeof(char));
c=(char*)malloc(400*sizeof(char));
 while(fgets(ligne,200,fd)){
 if(i==0){
 l =strstr(ligne, "Abstract");
 a =strstr(ligne, "ABSTRACT");
 c =strstr(ligne, "University of Edinburgh");
 }
 if(l!=NULL || a!=NULL || c!=NULL ){
 i=1;
 if(strstr(ligne,"Introduction") || strstr(ligne,"I NTRODUCTION") || strstr(ligne,"INTRODUCTION")){
 break;
 }
 if(!strstr(ligne, "University of Edinburgh"))
 strcat(str1, ligne);
 }
 //if(strstr(ligne,"I.")) break;

}
fclose(fd);
FILE * fdo =fopen("fcompression.txt","a");
 fputs(str1, fdo);
 fclose(fdo);
}

void FindConclusion(char* fichier){
	int TAILLE_MAX=10000;
 char * ligne;
     ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
      char sortie[100000];
      FILE * file = fopen(fichier, "r+");
      long  int j =0;
     long int i  =0;
     long int n ;
while(fgets(ligne, 1000, file)){
        
    if(strstr(ligne, "Conclusion") || strstr(ligne, "Discussion and Future Work")|| strstr(ligne , "VI. C ONCLUSIONS AND F UTURE W ORK"))
 	{
                
        i= ftell(file);
    }


    if(strstr(ligne, "Acknowledgments") || strstr(ligne, "V. D ISCUSSION") || strstr(ligne, "References  "))
    {
        j= ftell(file);
        n=j-i;
        break;
    }
                
            
           
}
fseek(file ,0, SEEK_SET);
fseek(file, i, SEEK_SET);

while(fgets(ligne, 1000, file)){
    n=n-1;
    strcat(sortie, ligne);
               
        
    if(ftell(file)==j){
        break;
    }

}

	
fclose(file);
FILE * fdo =fopen("test.txt","a");
fputs(sortie, fdo);
fclose(fdo);
   
}

void FindRef(char* fichier){
	int TAILLE_MAX=10000;
    char * ligne;
    ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
    char sortie[100000];
    FILE * file = fopen(fichier, "r+");
    long int i  =0;
    long int n ;
    long  int j =0;
	while(fgets(ligne, 10000, file)){
	        
	    if(strstr(ligne, "REFERENCES") || strstr(ligne, "References  "))
		{
	                
	        i= ftell(file);
	    }           
	            
	}
	j= ftell(file);
    n=j-i;
	fseek(file ,0, SEEK_SET);
	fseek(file, i, SEEK_SET);

	while(fgets(ligne, 10000, file)){
	    n=n-1;
	    strcat(sortie, ligne);
	    if(ftell(file)==j){
        	break;
    	}

	}
	fclose(file);
	FILE * fdo =fopen("fc2.txt","a");
	fputs(sortie, fdo);
	fclose(fdo);
}


int main(int argc, char **argv){
 struct dirent *lecture;
  DIR *rep;
  rep = opendir(argv[1]);
  while ((lecture = readdir(rep))) {
      FILE* file;
    file = fopen(nom du fichier où on va ecrire,"a");

    fputs("Titre: ",file);
    FindTitle(lecture->d_name);
   

    fputs("Autor: ",file);
  

    fputs("Abstract: ",file);
    FindAbstract(lecture->d_name);
   

    fputs("Introduction: ",file);
    FindIntro(lecture->d_name);
    

    fputs("Corp: ",file);
    

    fputs("Conclusion: ",file);
    FindConclusion(lecture->d_name);

    fputs("Discussion: ",file);
    

    fputs("Biblio: ",file);
    FindRef(lecture->d_name);
  
    fclose(file);
  }
  closedir(rep);
  return 0;
}