#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <string.h>


/*AAAAA*/
int main()
{       
	//  gcc *.h *.c -lm -lSDL -lSDL_image  -lSDL_ttf -lSDL_mixer -o prog -g
	////////////////////////animation
	SDL_Surface * ecran=NULL;
	ecran = SDL_SetVideoMode(1129,900, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//lancement de fenétre
	int continuer=1;
	SDL_Event event;//déclarer un événement
	enigme e;
	
	
	SDL_Surface * background=NULL;
	background= IMG_Load("2.jpg");
	generer_enigme(&e);
	int i=0;
	SDL_Surface *bouton1;
	SDL_Surface *bouton2;
	SDL_Surface *bouton3;
	bouton1= IMG_Load("img/button.png");//boutton avant animation
	bouton2= IMG_Load("img/button.png");//boutton avant animation
	bouton3= IMG_Load("img/button.png");//boutton avant animation*/
	while(continuer==1){
	i++;
	SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
	SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
	SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
	SDL_BlitSurface(background, NULL, ecran, NULL);//back plein écran
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);//affichage de la surface question
	SDL_BlitSurface(e.timer[e.num_animation],NULL,ecran,&e.pos_timer);
	//SDL_Flip(ecran);
	///////////////animer
	if(i%15==0)
   	animer(&e);
	SDL_BlitSurface(bouton1, NULL, ecran, &e.pos_reponse1);
	SDL_BlitSurface(bouton2, NULL, ecran, &e.pos_reponse2);
	SDL_BlitSurface(bouton3, NULL, ecran, &e.pos_reponse3);
	afficher_enigme(&e,ecran);

		if(e.time_over==1)
		{
		e.pos_selected=-1;
		verify_enigme(&e,ecran);
                generer_enigme(&e);
		e.time_over=0;
		e.num_animation=0;		
		}
		
		SDL_BlitSurface(e.timer[e.num_animation],NULL,ecran,&e.pos_timer);


		SDL_PollEvent(&event);//d5alna fl les énénements
			switch (event.type)
			{
				case SDL_KEYDOWN://ki tenzel 3la touche de clavier
				{
                                        if(event.key.keysym.sym==SDLK_ESCAPE)
					{
						continuer=0;
                                                break;
						
                                        }

					
					
				}
				break;
				
				case SDL_MOUSEBUTTONDOWN://ki tenzel b souris
				{
					if((event.motion.x>495 && event.motion.x<695)&&(event.motion.y>443 && event.motion.y<491))//intervalle sur les x et les y boutton1
					{	
						e.pos_selected=1;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							Mix_PlayChannel(2,e.sound,0);
							verify_enigme(&e,ecran);
							e.num_animation=0;
                                                        generer_enigme(&e);
						
						} 
					}
					else if((event.motion.x>296 && event.motion.x<497)&&(event.motion.y>570 && event.motion.y<620))//intervalle sur les x et les y boutton2
					{
						e.pos_selected=2;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							Mix_PlayChannel(2,e.sound,0);
							verify_enigme(&e,ecran);
							e.num_animation=0;
                                                        generer_enigme(&e);
							
						} 
					}
					else if((event.motion.x>685 && event.motion.x<884)&&(event.motion.y>570 && event.motion.y<620))//intervalle sur les x et les y boutton3
					{
						e.pos_selected=3;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							Mix_PlayChannel(2,e.sound,0);
							verify_enigme(&e,ecran);
							e.num_animation=0;
                                                        generer_enigme(&e);
							
						} 
					}
				}

				break;
		case SDL_MOUSEMOTION:
        {



	printf("x:%d y:%d\n",event.motion.x,event.motion.y);///nhb n affichi les coordonnees win l souris mawjouda  bh naaref blayes les boutons
       
	if((event.motion.x>495 && event.motion.x<695)&&(event.motion.y>443 && event.motion.y<491))//intervalle sur les x et les y boutton1
	{

	bouton1= IMG_Load("img/button_s.png");
	bouton2= IMG_Load("img/button.png");
	bouton3= IMG_Load("img/button.png");	
	
	}

	else if((event.motion.x>296 && event.motion.x<497)&&(event.motion.y>570 && event.motion.y<620))//intervalle sur les x et les y boutton2
	{
	bouton1= IMG_Load("img/button.png");	
	bouton2= IMG_Load("img/button_s.png");		
	bouton3= IMG_Load("img/button.png");
	
	
	}
	else if((event.motion.x>685 && event.motion.x<884)&&(event.motion.y>570 && event.motion.y<620))//intervalle sur les x et les y boutton3
	{

	bouton1= IMG_Load("img/button.png");
	bouton2= IMG_Load("img/button.png");	
	bouton3= IMG_Load("img/button_s.png");	
	} 

	else{
	
	bouton1= IMG_Load("img/button.png");	
	bouton2= IMG_Load("img/button.png");		
	bouton3= IMG_Load("img/button.png");
	SDL_Flip(ecran);


	}
	}break;
	}//switch	
	SDL_BlitSurface(bouton1, NULL, ecran, &e.pos_reponse1);
	SDL_BlitSurface(bouton2, NULL, ecran, &e.pos_reponse2);
	SDL_BlitSurface(bouton3, NULL, ecran, &e.pos_reponse3);
	SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
	SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
	SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
}//while1
}
