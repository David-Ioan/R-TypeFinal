#include "score.h"

void InitScore() {
	TTF_Init();
	
	TTF_Font* MC = TTF_OpenFont("Minecraft.ttf", 200);
	SDL_Color White = { 255, 255, 255 };
	surfaceMessage_score = TTF_RenderText_Solid(MC, "Badge : ", White);
	//convert
	Message_score = SDL_CreateTextureFromSurface(render, surfaceMessage_score);
}

void AfficheScore() {
	SDL_Rect scorerect = { 255, 850, 50, 50 };
	SDL_Rect message_score = { 20, 850, 200, 50 };
	SDL_RenderCopy(render, Message_score, NULL, &message_score);
	if (score >= 10) {
		texturebadge = SDL_CreateTextureFromSurface(render, badge[badgeID]);
		SDL_RenderCopy(render, texturebadge, NULL, &scorerect);
		if (score >= scoretmp + 10) {
			scoretmp = score;
			if (scoretmp > 10) {
				SDL_FreeSurface(badge[badgeID]);
				badgeID++;
			}
		}
	}
}