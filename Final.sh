
#!/bin/bash

for file in `ls $1`
do
pdftotext -raw $1/$file  #On convertit tous les .pdf en .txt
done
if ("$2" == "-t") 
then
sh creaDossier.sh $1 FichierTXT
for file in `ls $1`
do
nom = $(Python3 NomFichier.py $file)
./Parser FichierPDF/$file $nom
mv $file FichierTXT
done
elif ("$2" == "-x")
then
sh creaDossier.sh $1 FichierXML
for file in `ls $1`
do
nom = $(Python3 NomFichier.py $file)
./ParseX FichierPDF/$file $nom
mv $file FichierXML
done
fi 
