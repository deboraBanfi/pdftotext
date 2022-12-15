#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>


int main(int argc, char** argv){
	   int TAILLE_MAX=10000;
    char * ligne;
    char a[100]="";
      strcat(a,argv[1]);
      strcat(a,argv[2]);
     ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
      char sortie[100000];
      FILE * file = fopen(a, "r+");
      long  int j =0;
     long int i  =0;
     long int n ;
while(fgets(ligne, 1000, file)){
        
    if(strstr(ligne, "Introduction") || strstr(ligne, "INTRODUCTION")|| strstr(ligne , "I NTRODUCTION"))
	{
                
        i= ftell(file);
    }


    if(strstr(ligne,"II. R") || strstr(ligne, "2. Integer") || strstr(ligne, "Related Work") || strstr(ligne, "RELATED WORKS") || strstr(ligne, "Earlier Model") || strstr(ligne,"Application Examples") || strstr(ligne,"2 Applying")  || strstr(ligne,"Related work"))
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
char b[100]="";
int arg = atoi(argv[3]);
if(arg == 0){
  strcat(b,"TEST_PDF_G1/FichierTXT/");
}
else if(arg == 1){
  strcat(b,"TEST_PDF_G1/FichierXML/");
}
strcat(b,argv[2]);
FILE * fdo =fopen(b,"a");
fputs(sortie, fdo);
fclose(fdo);
}