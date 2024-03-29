#include "son.h"

void InitSon() {
	audio_rate = 22050;			
	audio_format = AUDIO_S16SYS;
	audio_channels = 2;
	audio_buffers = 4096;
	volume = 100;
	Mix_VolumeMusic(volume);

	SonErreur();
	
	sonlaser = Mix_LoadWAV("Pew.wav");
	mort = Mix_LoadWAV("Dav.wav");
	sonexplosion = Mix_LoadWAV("Explosion.wav");
	Mix_PlayMusic(music, -1);
	Mix_AllocateChannels(4);
	Mix_Volume(0, MIX_MAX_VOLUME/2);
	Mix_Volume(1, MIX_MAX_VOLUME);
	music = Mix_LoadWAV("happy.wav");
}

void Play() {
	if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SHOWN){
		Mix_PlayChannel(-1, music, -1);
	}
	if (lx == x + 25) {
		Mix_PlayChannel(-1, sonlaser, 0);
	}
	for (int i = 0; i < nbe; i++) {
		if (CollisionEnnemi(x, y, 50, 50, xe[i], ye[i], taille)
			|| CollisionEnnemi(x, y, 50, 50, xboss, yboss, tailleboss)) {
			Mix_PlayChannel(-1, sonexplosion, 0);
		}
		if (pv[i] <= 0) {
			Mix_PlayChannel(-1, mort, 0);
		}
	}
	

}


void SonErreur() {
	if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT,
	MIX_DEFAULT_CHANNELS, 1024) < 0) {
		printf("Unable to initialize audio: %s\n", Mix_GetError());
	}
}