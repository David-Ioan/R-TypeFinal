#pragma once
#include "fenetre.h"

// fenetre
bool InitSDL();
bool InitFenetre();
bool InitRenderer();
void Render();
void Destroy();

// vaisseau
void InitVaisseau();
void Vaisseau();

// controle
void Keydown();
void Keyup();
void Velocite();

// collision
int posx;
int posy;
int l;
int h;
int objx;
int objy;
int tail;
void MurVaisseau();
bool CollisionEnnemi(posx, posy, l, h, objx, objy, tail);
void EnnemiMur();

// ennemi
void Spawn();
void Ennemi();
void Boss();
void Niveaux();
void Evolution();

// projectile
void InitLaser();
void Laser();

// condition
void Initialisation();
void Mouvement();
void InitEnnemi();

// score
void InitScore();
void AfficheScore();

// son
void InitSon();
void Play();
void SonErreur();