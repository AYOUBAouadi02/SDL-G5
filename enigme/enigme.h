#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//les variables booléene
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

typedef struct{
	SDL_Surface *background;
	SDL_Surface *question;
	SDL_Surface *reponses[4];
	SDL_Surface *button;
	SDL_Surface *button_s;//animation

	int pos_selected;
	SDL_Rect pos_question;//position
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2;
	SDL_Rect pos_reponse3;
	int num_question;

	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;
	int vrai_reponse;
	int positionVraiReponse;
	Mix_Chunk *sound;//animation sonore

	


///////////animation 
	SDL_Rect pos_timer;//pos timer al ecran
	SDL_Surface *timer[12];
	int num_animation;
	int time_over;
}enigme;

void generer_enigme(enigme *e);
void afficher_enigme(enigme *e,SDL_Surface *ecran);
void verify_enigme(enigme *e,SDL_Surface*ecran);
void animer(enigme *e);

#endif
