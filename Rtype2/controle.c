#include "controle.h"

void Velocite() {
    x += xVel;
    y += yVel;
}

void Keydown() {
    switch (event.key.keysym.sym) {
        case SDLK_z:
            yVel = -speed / 2;
            break;

        case SDLK_s:
            yVel = speed / 2;
            break;

        case SDLK_q:
            xVel = -speed / 2; break;

        case SDLK_d:
            xVel = speed / 2;
            break;

        default: 
            break;
    }
}

void Keyup() {
        //ajustement de la vitesse
     switch (event.key.keysym.sym){
        case SDLK_z:
            yVel = 0;
            printf("%i", score);
            break;

        case SDLK_s:
            yVel = 0;
            break;

        case SDLK_q:
            xVel = 0;
            break;

        case SDLK_d:
            xVel = 0;
            break;

        default:
            break;
     }
}