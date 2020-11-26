/*
Texte.c
--------------

Créé par Guillaume Rouja
Créé le 20.09.2014
Dernière modification le 10/10/2014

Rôle: Gérer les écrans de texte survenant au cours du jeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void explications(SDL_Surface *ecran)
{
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    int continuer =1;
    SDL_Event event;

    texte=IMG_Load("Textes/regle.jpg");
    positionTexte.x=0;
    positionTexte.y=0;

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
        SDL_BlitSurface(texte,NULL,ecran,&positionTexte);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(texte);

    return EXIT_SUCCESS;
}

void histoire(SDL_Surface *ecran)
{
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    int continuer =1;
    SDL_Event event;

    texte=IMG_Load("Textes/intro_histoire.jpg");
    positionTexte.x=0;
    positionTexte.y=0;

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
                    case SDLK_SPACE:
                        jouer(ecran);
                        break;
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                }
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(texte,NULL,ecran,&positionTexte);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(texte);

    return EXIT_SUCCESS;
}

 void bravojeu(SDL_Surface *ecran)
{
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    int continuer =1;
    SDL_Event event;

    texte=IMG_Load("Textes/bravo.jpg");
    positionTexte.x=0;
    positionTexte.y=0;

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
        SDL_BlitSurface(texte,NULL,ecran,&positionTexte);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(texte);

    return EXIT_SUCCESS;
}

void bravohistoire(SDL_Surface *ecran)
{
    SDL_Surface *texte = NULL;
    SDL_Rect positionTexte;
    int continuer =1;
    SDL_Event event;

    texte=IMG_Load("Textes/finhistoire.jpg");
    positionTexte.x=0;
    positionTexte.y=0;

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
        SDL_BlitSurface(texte,NULL,ecran,&positionTexte);
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(texte);

    return EXIT_SUCCESS;
}
