
import os.path
import sys
import re


fichier=sys.argv[1]
 
m = re.search('[^.]*',fichier)
print (m.group(0))




