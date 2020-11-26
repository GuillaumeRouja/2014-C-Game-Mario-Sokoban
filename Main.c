/*
Main.c

créé par Guillaume Rouja
créé le 30/08/2014
Dernière modification le 05/09/2014

Rôle: menu du jeu, permet de choisir entre le jeu lui-même et l'éditeur
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"
#include "Texte.h"


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *menu = NULL;
    SDL_Rect positionMenu;
    SDL_Event event;

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("caisse.jpg"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Mario Sokoban", NULL);

    menu = IMG_Load("Textes/menu.jpg");
    positionMenu.x = 0;
    positionMenu.y = 0;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // Veut arrêter le jeu
                        continuer = 0;
                        break;
                    case SDLK_KP1:// Demande à jouer (entrainement)
                        choixmenu = 1;
                        jouer(ecran);
                        break;
                    case SDLK_KP2: // Demande à jouer (mode histoire)
                        choixmenu = 0;
                        histoire (ecran);
                        break;
                    case SDLK_KP3: // Demande l'éditeur de niveaux
                        editeur(ecran);
                        break;
                    case SDLK_KP4:
                        explications(ecran); // demande des explications sur le jeu
                        break;
                    case SDLK_1:// Demande à jouer (entrainement)
                        choixmenu = 1;
                        jouer(ecran);
                        break;
                    case SDLK_2: // Demande à jouer (mode histoire)
                        choixmenu = 0;
                        histoire (ecran);
                        break;
                    case SDLK_3: // Demande l'éditeur de niveaux
                        editeur(ecran);
                        break;
                    case SDLK_4:
                        explications(ecran); // demande des explications sur le jeu
                        break;
                }
                break;
        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(menu);
    SDL_Quit();

    return EXIT_SUCCESS;
}

