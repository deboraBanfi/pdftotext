#Fait par :IDRISSOU Fatai
#!/bin/bash

DOSSIER=$1/FichierTXT

if [ -d "$DOSSIER" ]; then
    rm -r $DOSSIER 
     mkdir $DOSSIER
else
    mkdir $DOSSIER
   

fi
