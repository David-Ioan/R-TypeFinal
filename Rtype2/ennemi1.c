#include "ennemi.h"

void InitEnnemi() {
    imgID = 0;
    image2[0] = IMG_Load("3.gif");
    image2[1] = IMG_Load("2.gif");
    texture2 = SDL_CreateTextureFromSurface(render, image2[imgID]);
    explosion = IMG_Load("bomb.png");
    textureex = SDL_CreateTextureFromSurface(render, explosion);
    nbe = 20;
    for (int i = 0; i < nbe; i++) {
        ve[i] = 1 + rand() % 5;
        pv[i] = 100;
    }
    taille = 75;
    tailleboss = 200;
    xboss = 1400;
    yboss = 350;
    pvboss = 10000;
    vboss = 1;
}

void Spawn() {
    srand(time(NULL));
    for (int i = 0; i < nbe; i++) {
        ye[i] = rand() % 775;
        xe[i] = rand() % 1400 + 500;
    }
}

void Ennemi() {
    SDL_Rect ennemi[100];
    for (int i = 0; i < nbe; i++) {
        SDL_SetRenderDrawColor(render, 0, 0, 255, 0);
        ennemi[i].x = xe[i];
        ennemi[i].y = ye[i];
        ennemi[i].w = taille;
        ennemi[i].h = taille;
        SDL_RenderFillRect(render, &ennemi[i]);
        SDL_RenderCopy(render, texture2, NULL, &ennemi[i]);
        if (pv[i] <= 0) {
            SDL_RenderCopy(render, textureex, NULL, &ennemi[i]);
            xe[i] = 1400;
            ye[i] = rand() % 775;
            score++;
            pv[i] = 100 + score * 10;
            if (score >= 10) {
                imgID = 1;
                texture2 = SDL_CreateTextureFromSurface(render, image2[imgID]);
            }
        }
        xe[i] -= ve[i];
    }
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    EnnemiMur();
}

void Boss() {
    SDL_SetRenderDrawColor(render, 0, 0, 255, 0);
    SDL_Rect boss = { xboss, yboss, tailleboss, tailleboss };
    SDL_RenderDrawRect(render, &boss);
    SDL_RenderCopy(render, texture2, NULL, &boss);
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    EnnemiMur();
    xboss -= vboss;
}

void Niveaux() {
    if (score < 70) {
        Ennemi();
    }
    if (score >= 70) {
        srand(time(NULL));
        for (int i = 0; i < nbe; i++) {
            ye[i] = rand() % 900;
            xe[i] = 1400;
            ve[i] = 0;
            pv[i] = 0;
        }
        Boss();
    }
}