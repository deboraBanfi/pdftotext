Fonctionnement du Système final:

-Avoir installé au préalable:
	>pip install pandas
	>pip install pathlib
	>pip install PyPDF2
	
Afin de faciliter l'execution du système, le seul fichier à executer est SystemeFinal.sh.
Ce script va aller dans le répertoire indiqué en argument, 
qui contient les fichiers PDF, lors de l'execution du script (ex: sh SystemeFinal.sh /home/user/Bureau/ )
puis il va créer un dossier FichierTXT dans ce répertoire.
Une fois le répertoire créer, grâce a une boucle for nous allons parcourir le répertoire qui contient tous les fichiers PDF pour créer les 
fichiers .txt correspondants (avec le même nom et dans le répertoire FichierTXT)
une fois les fichiers .txt créé, le parseur va aller lire les fichiers PDF pour les retrenscrire dans les fichiers .txt
