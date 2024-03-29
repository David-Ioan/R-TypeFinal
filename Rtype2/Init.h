#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#include "ennemi.h"
#include "vaisseau.h"



int score;
int scoretmp;
int badgeID;
SDL_Surface* badge[7];
SDL_Texture* texturebadge;

SDL_Event event;
bool bouger;
