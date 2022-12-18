#Fait par :IDRISSOU Fatai
#!/bin/bash

DOSSIER=$1/$2

if [ -d "$DOSSIER" ]; then
    rm -r $DOSSIER 
     mkdir $DOSSIER
else
    mkdir $DOSSIER
   

fi
