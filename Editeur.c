/*
editeur.c
---------

Par mateo21, pour Le Site du Zér0 (www.siteduzero.com)
Dernnière modification par Guillaume Rouja le 25.09.2014

Rôle : gestion de l'éditeur de niveaux.
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "editeur.h"
#include "fichiers.h"

void editeur(SDL_Surface* ecran)
{
    SDL_Surface *mur = NULL, *caisse = NULL,*caisseOK=NULL, *objectif = NULL, *mario = NULL;
    SDL_Rect position, deplacement;
    SDL_Event event;

    int continuer = 1, clicGaucheEnCours = 0, clicDroitEnCours = 0;
    int objetActuel = MUR, i = 0, j = 0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};

    // Chargement des objets et du niveau
    mur = IMG_Load("mur.jpg");
    caisse = IMG_Load("caisse.jpg");
    caisseOK = IMG_Load("caisse_ok.jpg");
    objectif = IMG_Load("objectif.png");
    mario = IMG_Load("mario_bas.gif");



    if (!chargerNiveau(carte))
        exit(EXIT_FAILURE);

    // Boucle infinie de l'éditeur

    SDL_ShowCursor(SDL_DISABLE);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (objetActuel!=MARIO)
                    {
                    // On met l'objet actuellement choisi (mur, caisse...) à l'endroit du clic
                    carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
                    clicGaucheEnCours = 1; // On active un booléen pour retenir qu'un bouton est enfoncé
                    }
                    if (objetActuel==MARIO)
                    {
                        for(i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
                        {
                            for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
                            {
                                if (carte[i][j]==MARIO)
                                {
                                    carte[i][j]=VIDE; // on ne récupère que le dernier mario affiché
                                }
                            }
                        }
                    carte[event.button.x / TAILLE_BLOC][event.button.y / TAILLE_BLOC] = objetActuel;
                    clicGaucheEnCours = 1;
                    }

                }
                else if (event.button.button == SDL_BUTTON_RIGHT) // Le clic droit sert à effacer
                {
                    carte[event.button.x / TAILLE_BLOC][event.button.y /TAILLE_BLOC] = VIDE;
                    clicDroitEnCours = 1;
                }
                break;
            case SDL_MOUSEBUTTONUP: // On désactive le booléen qui disait qu'un bouton était enfoncé

                if (event.button.button == SDL_BUTTON_LEFT)
                    clicGaucheEnCours = 0;
                else if (event.button.button == SDL_BUTTON_RIGHT)
                    clicDroitEnCours = 0;
                break;

            case SDL_MOUSEMOTION:

                if (clicGaucheEnCours) // Si on déplace la souris et que le bouton gauche de la souris est enfoncé
                {
                    carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = objetActuel;
                }
                else if (clicDroitEnCours) // Pareil pour le bouton droit de la souris
                {
                    carte[event.motion.x / TAILLE_BLOC][event.motion.y / TAILLE_BLOC] = VIDE;
                }
                break;

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_s:
                        sauvegarderNiveau(carte);
                        break;
                    case SDLK_c:
                        chargerNiveau(carte);
                        break;
                    case SDLK_KP1:
                        objetActuel = MUR;
                        break;
                    case SDLK_KP2:
                        objetActuel = CAISSE;
                        break;
                    case SDLK_KP3:
                        objetActuel = CAISSE_OK;
                        break;
                    case SDLK_KP4:
                        objetActuel = OBJECTIF;
                        break;
                    case SDLK_KP5:
                        objetActuel = MARIO;
                        break;
                     case SDLK_1:
                        objetActuel = MUR;
                        break;
                    case SDLK_2:
                        objetActuel = CAISSE;
                        break;
                    case SDLK_3:
                        objetActuel = CAISSE_OK;
                        break;
                    case SDLK_4:
                        objetActuel = OBJECTIF;
                        break;
                    case SDLK_5:
                        objetActuel = MARIO;
                        break;
                }
                break;
        }

        // Effacement de l'écran

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        deplacement.x=event.motion.x; // Le curseur de la souris suivra l'objet actuellement sélectionné.
        deplacement.y=event.motion.y;

        if (objetActuel==MUR)
           SDL_BlitSurface(mur, NULL, ecran, &deplacement);
        if (objetActuel==CAISSE)
           SDL_BlitSurface(caisse, NULL, ecran, &deplacement);
        if (objetActuel==CAISSE_OK)
           SDL_BlitSurface(caisseOK, NULL, ecran, &deplacement);
        if (objetActuel==OBJECTIF)
           SDL_BlitSurface(objectif, NULL, ecran, &deplacement);
        if (objetActuel==MARIO)
            SDL_BlitSurface(mario, NULL, ecran, &deplacement);

        // Placement des objets à l'écran
        for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++)
        {
            for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++)
            {
                position.x = i * TAILLE_BLOC;
                position.y = j * TAILLE_BLOC;

                switch(carte[i][j])
                {
                    case MUR:
                        SDL_BlitSurface(mur, NULL, ecran, &position);
                        break;
                    case CAISSE:
                        SDL_BlitSurface(caisse, NULL, ecran, &position);
                        break;
                    case CAISSE_OK:
                        SDL_BlitSurface(caisseOK, NULL, ecran, &position);
                        break;
                    case OBJECTIF:
                        SDL_BlitSurface(objectif, NULL, ecran, &position);
                      //  SDL_BlitSurface(objectif, NULL, ecran, &deplacement);
                        break;
                    case MARIO:
                        SDL_BlitSurface(mario, NULL, ecran, &position);
                     //   SDL_BlitSurface(mario, NULL, ecran, &deplacement);
                        break;
                }
            }
        }

        // Mise à jour de l'écran
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(mur);
    SDL_FreeSurface(caisse);
    SDL_FreeSurface(caisseOK);
    SDL_FreeSurface(objectif);
    SDL_FreeSurface(mario);
}
