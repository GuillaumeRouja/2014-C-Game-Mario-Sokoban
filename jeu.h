/*
jeu.h
-----

Par mateo21, pour Le Site du Z�r0 (www.siteduzero.com)

R�le : prototypes des fonctions du jeu.
*/

#ifndef DEF_JEU
#define DEF_JEU


//int choixmode = 1; // variable d�clar�e ici pour pouvoir la r�cup�rer dans le fichier jeu.c

    void jouer(SDL_Surface* ecran);
    void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction);
    void deplacerCaisse(int *premiereCase, int *secondeCase);


#endif
