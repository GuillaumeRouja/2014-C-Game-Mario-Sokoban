/*
fichiers.c
----------

Par mateo21, pour Le Site du Z�r0 (www.siteduzero.com)
Modifi� par Guillaume Rouja le 25.09.2014 (int�gration des caisses OK)

R�le : fonctions de lecture / �criture de fichiers de niveau.
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "fichiers.h"

int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR])
{
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0;

    fichier = fopen("niveaux.lvl", "r");
    if (fichier == NULL)
        return 0;

    fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1, fichier);

    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j])
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

int chargerNiveauxHistoire(int niveau[][NB_BLOCS_HAUTEUR],int numeroNiveau)
{
    FILE* fichier = NULL;
    char lignesFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};
    int i = 0, j = 0, k = 0;

    fichier = fopen("niveauxhistoire.lvl", "r");
    if (fichier == NULL)
    return 0;


    for (k=0; k<numeroNiveau;k++) // On va faire une boucle afin de lire les 10 niveaux

    {
    char *positionEntree = NULL;
    positionEntree = strchr(lignesFichier, '\n'); // On recherche le "\n"
    if (positionEntree != NULL) // Si on a trouv� le retour � la ligne
    *positionEntree = '\0'; // On remplace ce caract�re par \0
    fgets(lignesFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 2, fichier); // J'ajoute un caract�re dans ma s�lection des caract�res de la ligne pour aller chercher le \n au bout � remplacer par un \0
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

int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR])
{
    FILE* fichier = NULL;
    int i = 0, j = 0;

    fichier = fopen("niveaux.lvl", "w");
    if (fichier == NULL)
        return 0;

    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
    {
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
        {
            {fprintf(fichier, "%d", niveau[j][i]);}
        }
    }

    fclose(fichier);
    return 1;
}
