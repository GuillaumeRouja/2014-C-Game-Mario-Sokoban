/*
Chargementhistoire.c
---------------------

Par Guillaume Rouja
Créé le 07.10.2014
Modifié le 07.10.2014

Rôle: Contient la fonction de chargement des niveaux du mode histoire
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>

#include "constantes.h"
#include "Chargementhistoire.h"

int chargerNiveauxHistoire(int niveau[][NB_BLOCS_HAUTEUR],int numeroNiveau)
{
    FILE* fichier = NULL;
    char lignesFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0, k = 0;

    fichier = fopen("NiveauxHistoire/niveaux.lvl", "r");
    if (fichier == NULL)
    return 0;


    for (k=0; k<numeroNiveau;k++) // On va faire une boucle afin de lire les 10 niveaux

    {
    char *positionEntree = NULL;
    positionEntree = strchr(lignesFichier, '\n'); // On recherche le "\n"
    if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
    *positionEntree = '\0'; // On remplace ce caractère par \0
    fgets(lignesFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 2, fichier); // J'ajoute un caractère dans ma sélection des caractères de la ligne pour aller chercher le \n au bout à remplacer par un \0
    }

    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            switch (lignesFichier[(i * NB_BLOCS_LARGEUR) + j])
            {
                case '0':
                    niveau[j][i] = 0;
                    break;
                case '1':
                    niveau[j][i] = 1;
                    break;
                case '2':
                    niveau[j][i] = 2;
                    break;
                case '3':
                    niveau[j][i] = 3;
                    break;
                case '4':
                    niveau[j][i] = 4;
                    break;
                case '5':
                    niveau[j][i] = 5;
                    break;
            }
        }
    }

    fclose(fichier);
    return 1;
}


