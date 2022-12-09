#Fait par :BANFI Débora
#!/bin/bash

echo $1
sh creaDossier.sh $1 #fatai
for file in `ls $1`
do
python3 NomFichier.py $1 $file #Titouan
python3 Parseur.py $1 $file #narjis
done
