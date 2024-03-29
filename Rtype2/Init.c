#include "Init.h"



void Initialisation() {
	if (InitSDL()) {
		if (InitFenetre()) {
			InitRenderer();
		}
	}
	InitSon();
	InitLaser();
	InitEnnemi();
	InitVaisseau();
	Spawn();

	badge[0] = IMG_Load("F.png");
	badge[1] = IMG_Load("E.png");
	badge[2] = IMG_Load("D.png");
	badge[3] = IMG_Load("C.png");
	badge[4] = IMG_Load("B.png");
	badge[5] = IMG_Load("A.png");
	badge[6] = IMG_Load("S.png");
	scoretmp = 0;
	badgeID = 0;
}

void Mouvement() {
	if (event.type == SDL_KEYDOWN) {
		Keydown();
	}
	else if (event.type == SDL_KEYUP) {
		Keyup();
	}
	for (int i = 0; i < nbe; i++) {
		if (CollisionEnnemi(x, y, 50, 50, xe[i], ye[i], taille) == true) {
			bouger = false;
		}
	}
}

