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
        
    if(strstr(ligne, "DISCUSSION") || strstr(ligne, "Discussion")|| strstr(ligne , "Discussions") || strstr(ligne, "D ISCUSSION") || strstr(ligne,"7. Discussion"))
	{
                
        i= ftell(file);
    }


    if(strstr(ligne,"CONCLUSION") || strstr(ligne, "Conclusion") || strstr(ligne, "References") || strstr(ligne, "Conclusions") || strstr(ligne, "C CONCLUSION") || strstr(ligne, "R EFERENCES"))
    {
        j= ftell(file);

        n=j-i;
        break;
    }
                
            
}
fseek(file ,0, SEEK_SET);
fseek(file, i, SEEK_SET);

while(fgets(ligne, 1000, file) && i!=0){
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