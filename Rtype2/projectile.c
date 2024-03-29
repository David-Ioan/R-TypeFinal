#include "projectile.h"

void InitLaser() {
    lVel = 30;
    lx = x + 25;
    ly = y + 25;
    longueur = 50;
    dgt = 40;
}

void Laser() {
    SDL_Rect laser = { lx, ly, longueur,5 };
    SDL_SetRenderDrawColor(render, 255, 16, 16, 255);
    SDL_RenderFillRect(render, &laser);

    lx += lVel;
    if (lx >= 1400 + 50) {
        lx = x + 25;
        ly = y + 25;
        }

    for (int i = 0; i < nbe; i++) {
        if (CollisionEnnemi(lx, ly, longueur, 20, xe[i], ye[i], taille)) {
            pv[i] -= dgt;
            lx = x + 25;
            ly = y + 25;
        }
    }

    if (CollisionEnnemi(lx, ly, longueur, 20, xboss, yboss, tailleboss)) {
        pvboss -= dgt;
        lx = x + 25;
        ly = y + 25;
    }
}