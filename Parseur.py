#Fait par: MOUNDIR Narjis

import pandas as pd
import os
import PyPDF2
import sys

path = sys.argv[1]
newpath = path+"FichierTXT/"
fichier = sys.argv[2]
f = path+fichier

txt = f.replace('.pdf','.txt')
txtpath = txt.replace(path,newpath) 

ft= open(txtpath ,"w+")
ft.close()

Vpath = f.replace('.pdf','')

myPDFFile = PyPDF2.PdfFileReader(f)
with open(txtpath, 'w+', encoding='utf-8') as pdf_output:   #, encoding="utf-8"
	for page in range (myPDFFile.getNumPages()):
		data = myPDFFile.getPage(page).extractText()
		pdf_output.write(data)            
with open(txtpath, 'r') as myPDFContent:
	myPDFContent.read().replace('\n',' ')
