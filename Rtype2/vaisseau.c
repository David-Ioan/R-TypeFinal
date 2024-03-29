#include "vaisseau.h"
x = 5;
y = 250;

void InitVaisseau() {
    image = IMG_Load("1.png");
    texture = SDL_CreateTextureFromSurface(render, image);
}

void Vaisseau() {
    SDL_Rect dstrect = { x, y, 50, 50 };
    SDL_RenderCopy(render, texture, NULL, &dstrect);
    for (int i = 0; i < nbe; i++) {
        if (CollisionEnnemi(x, y, 50, 50, xe[i], ye[i], taille)
            || CollisionEnnemi(x, y, 50, 50, xboss, yboss, tailleboss)) {
            lx = 0;
            ly = 0;
            longueur = 0;
            x = 0;
            y = 0;
            SDL_FreeSurface(image);
            SDL_DestroyTexture(texture);
            Mix_FreeMusic(sonlaser);
            SDL_RenderCopy(render, textureex, NULL, &dstrect);
        }
    }
    Velocite();
    MurVaisseau();
    Laser();
}