#include "collision.h"

void MurVaisseau() {
    //Si le point se rapproche trop des limites(gauche ou droite) de l'ecran
    if ((x < 0) || (x + 50 > 1400)){
        //On revient
        x -= xVel;
    }

    //Si le point se rapproche trop des limites(haute ou basse) de l'ecran
    if ((y < 0) || (y + 50 >= 850)){
        //On revient
        y -= yVel;
    }
}

bool CollisionEnnemi(posx, posy, l, h, objx, objy, tail) {
        if (posx + l >= objx && posx <= objx + tail 
            && posy+h >= objy && posy <= objy + tail){
            return true;
        }
    return false;
}

void EnnemiMur() {
    for (int i = 0; i < nbe; i++) {
        if (xe[i] <= 0) {
            xe[i] = 1400;
        }
    }
}