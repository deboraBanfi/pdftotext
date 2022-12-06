// titou
#include <stdio.h>
#include <string.h>
#include <dirent.h>

// Déclaration de la fonction à lancer lorsqu'un fichier .pdf est détecté
void parse_pdf(char *filename);

int main(int argc, char *argv[]) {
  // Vérifiez les arguments passés au programme
  if (argc != 2) {
    printf("Utilisation : %s <chemin_dossier>\n", argv[0]);
    return 1;
  }

  // Ouvrez le dossier spécifié en argument
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Impossible d'ouvrir le dossier %s\n", argv[1]);
    return 1;
  }

  // Parcourez les fichiers du dossier
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Récupérez le nom du fichier et son extension
    char *filename = entry->d_name;
    char *ext = strrchr(filename, '.');

    // Si le fichier a l'extension .pdf, lancez la fonction "parse_pdf"
    if (ext != NULL && strcmp(ext, ".pdf") == 0) {
      parse_pdf(filename);
    }
  }

  // Fermez le dossier
  closedir(dir);

  return 0;
}

// Définition de la fonction "parse_pdf"
void parse_pdf(char *filename) {
  printf("Fichier .pdf détecté : %s\n", filename);
  // Insérez ici le code pour parser le fichier PDF
}