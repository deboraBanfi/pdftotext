#Fait par: CORNEN Titouan 
# import library
from pathlib import Path
import os.path
import sys

chemin=sys.argv[1]
fichier=sys.argv[2]
#fontion qui return le 1 fichier.pdf d'un path ( dossier) et donne son nom sans l'extention
def checks_firt_pdf(path,files):
    
    if files.endswith(".pdf"):
    	file_path = os.path.join(path, files)
    	nouveau_nom = '.'.join(files.split('.')[:-1])
    return nouveau_nom


premier =checks_firt_pdf(chemin, fichier)

#Fait par: FREHOU Soufiane

pdffileobj=open(chemin+"FichierTXT/",'rb')
#le nom de fichier.pdf
basename = os.path.basename(filepath)
pdfreader=PyPDF2.PdfFileReader(pdffileobj)
x=pdfreader.numPages
pageobj=pdfreader.getPage(x+1)
text=pageobj.extractText()
#remplacer le nom de fichier1.pdf par fichier1.txt
basename = txt.replace(".pdf", ".txt")
file1=open(chemin+"FichierTXT/"+premier+basename,"a")
file1.writelines(text)


