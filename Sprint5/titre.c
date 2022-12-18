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
    char a[10000]="";
    strcat(a,argv[1]);//argv[1]=dossier dans lequelle il y a les fichiers .txt
    strcat(a,argv[2]);// argv[2]= le fichier .txt
    ligne  = (char*) malloc(TAILLE_MAX * sizeof(char));
    char sortie[10000];
    FILE * file = fopen(a, "rt");
     
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
    return 0;
}