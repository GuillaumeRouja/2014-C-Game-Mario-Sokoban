/*
Explications.c
--------------

Créé par Guillaume Rouja
Créé le 20.09.2014
Dernière modification le 20/09/2014

Rôle: Fichier destiné à expliquer le fonctionnement du jeu et de l'éditeur
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void explications(SDL_Surface *ecran)
{
    SDL_Surface *notice = NULL;
    SDL_Rect positionNotice;
    int continuer =1;
    SDL_Event event;

    notice=IMG_Load("mode_d_emploi.jpg");
    positionNotice.x=0;
    positionNotice.y=0;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                }
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(notice,NULL,ecran,&positionNotice);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(notice);

    return EXIT_SUCCESS;
}




