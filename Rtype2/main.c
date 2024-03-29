#include "main.h"

int main() {
	Initialisation();
	bouger = true;

	while (1) {
		
		Render();
		InitScore();
		AfficheScore();
		Play();
		Vaisseau();

		Niveaux();
		
		SDL_PollEvent(&event);
		if (bouger == true) {
			Mouvement();
		}
		SDL_RenderPresent(render);
		SDL_Delay(10);
	}

	Destroy();

	return 0;

}