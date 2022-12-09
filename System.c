#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <Parser.c>
#include <ParseX.c>

int main()
{
    printf("choisir l'extension à sortir tapez :\n-t pour une fichier text ou \n-x pour un fichier xml\n");
    char* x;
    x = (char*)malloc(3 * sizeof(char));
    scanf("%s",x);
    if(strcmp(x,"-t")==0){
       execute(Parser);
    }else if(strcmp(x,"-x")==0){
        execute(2);
    }else
        printf("y'a pas de extension ");

    return 0;
}