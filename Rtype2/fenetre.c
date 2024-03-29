#include "fenetre.h"

bool InitSDL() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("Erreur SDL INIT failed\n");
		return false;
	}
	return true;
}

bool InitFenetre() {
	fenetre = SDL_CreateWindow("R-Type",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1400, 900, SDL_WINDOW_SHOWN);
	if (fenetre == NULL) {
		printf("Erreur creation de la fenetre SDL");
		SDL_Quit();
		return false;
	}
	return true;
}

bool InitRenderer() {
	render = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	fond = IMG_Load("3.jpeg");
	texturefond = SDL_CreateTextureFromSurface(render, fond);
	if (render == NULL) {
		printf("Erreur creation rendu SDL\n");
		SDL_DestroyWindow(fenetre);
		SDL_Quit();
		return false;
	}
	return true;
}

void Render() {
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255); //WHITE SQUARRE
	SDL_RenderClear(render);
	SDL_RenderCopy(render, texturefond, NULL, NULL);
}

void Destroy() {
	Mix_FreeMusic(music);
	Mix_FreeMusic(sonlaser);
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(textureex);
	SDL_DestroyTexture(texture2);
	SDL_DestroyTexture(texturefond);
	SDL_DestroyTexture(texturebadge);
	SDL_FreeSurface(image);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(badge);
	SDL_FreeSurface(fond);
	SDL_FreeSurface(explosion);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(fenetre);
	Mix_CloseAudio();
	SDL_Quit();
}