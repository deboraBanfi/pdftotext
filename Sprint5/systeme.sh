#!bin/bash
gcc -Wall -o titre.o -c titre.c
gcc -o titre titre.o

gcc -Wall -o intro.o -c intro.c
gcc -o intro intro.o

gcc -Wall -o abstract.o -c abstract.c
gcc -o abstract abstract.o

gcc -Wall -o corps.o -c corps.c
gcc -o corps corps.o

gcc -Wall -o ref.o -c ref.c
gcc -o ref ref.o

gcc -Wall -o discussion.o -c discussion.c
gcc -o discussion discussion.o

gcc -Wall -o conclu.o -c conclu.c
gcc -o conclu conclu.o


rename  's/ /_/g' $1*.txt

if [ "$2" = "-t" ]; then
	sh creaDossier.sh TEST_PDF_G1 FichierTXT
	for file in `ls $1`
	do
		touch TEST_PDF_G1/FichierTXT/$file
		echo "Titre: " >> TEST_PDF_G1/FichierTXT/$file
		./titre $1 $file 0

		echo "Abstract: " >> TEST_PDF_G1/FichierTXT/$file
		./abstract $1 $file 0

		echo "Intro: " >> TEST_PDF_G1/FichierTXT/$file
		./intro $1 $file 0

		echo "Corps: " >> TEST_PDF_G1/FichierTXT/$file
		./corps $1 $file 0

		echo "References: " >> TEST_PDF_G1/FichierTXT/$file
		./ref $1 $file 0

		echo "Discussion: " >> TEST_PDF_G1/FichierTXT/$file
		./discussion $1 $file 0

		echo "Conclusion: " >> TEST_PDF_G1/FichierTXT/$file
		./conclu $1 $file 0
	done
else 
	if [ "$2" = "-x" ]; then
		sh creaDossier.sh TEST_PDF_G1 FichierXML
		for file in `ls $1`
		do
			touch TEST_PDF_G1/FichierXML/$file
			echo "<article>" >> TEST_PDF_G1/FichierXML/$file

			echo "<preambule>" >> TEST_PDF_G1/FichierXML/$file
			rename -n 's/.txt/.pdf/g' $file | cut -f2 -d"," | cut -f1 -d")" >> TEST_PDF_G1/FichierXML/$file
			echo "</preambule>" >> TEST_PDF_G1/FichierXML/$file

			echo "<title>" >> TEST_PDF_G1/FichierXML/$file
			./titre $1 $file 1
			echo "</title>" >> TEST_PDF_G1/FichierXML/$file

			echo "<abstract>" >> TEST_PDF_G1/FichierXML/$file
			./abstract $1 $file 1
			echo "</abstract>" >> TEST_PDF_G1/FichierXML/$file

			echo "<intro>" >> TEST_PDF_G1/FichierXML/$file
			./intro $1 $file 1
			echo "</intro>" >> TEST_PDF_G1/FichierXML/$file

			echo "<corps>" >> TEST_PDF_G1/FichierXML/$file
			./corps $1 $file 1
			echo "<</corps>" >> TEST_PDF_G1/FichierXML/$file

			echo "<conclusion>" >> TEST_PDF_G1/FichierXML/$file
			./conclu $1 $file 1
			echo "</conclusion>" >> TEST_PDF_G1/FichierXML/$file

			echo "<discussion>" >> TEST_PDF_G1/FichierXML/$file
			./discussion $1 $file 1
			echo "</discussion>" >> TEST_PDF_G1/FichierXML/$file

			echo "<Bibliographie>" >> TEST_PDF_G1/FichierXML/$file
			./ref $1 $file 1
			echo "</Bibliographie>" >> TEST_PDF_G1/FichierXML/$file

			echo "</article>" >> TEST_PDF_G1/FichierXML/$file
			rename  's/.txt/.xml/g' TEST_PDF_G1/FichierXML/$file
		done
	fi
fi