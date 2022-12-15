#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	int TAILLE_MAX=10000;
    char * ligne;
    ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
    char sortie[100000];
    char a[10000]="";
    strcat(a,argv[1]);//argv[1]=dossier dans lequelle il y a les fichiers .txt
    strcat(a,argv[2]);// argv[2]= le fichier .txt
    FILE * file = fopen(a, "r+");
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