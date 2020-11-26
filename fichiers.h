/*
fichiers.h
----------

Par mateo21, pour Le Site du Zér0 (www.siteduzero.com)

Dernière modification le 10/10/2014 par Guillaume Rouja

Rôle : prototypes des fonctions de lecture / écriture de fichiers de niveau.
*/

#ifndef DEF_FICHIERS
#define DEF_FICHIERS

    int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR]);
    int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR]);
    int chargerNiveauxHistoire(int niveau[][NB_BLOCS_HAUTEUR], int numeroNiveau);
    int lire(char *chaine, int longueur);

#endif
