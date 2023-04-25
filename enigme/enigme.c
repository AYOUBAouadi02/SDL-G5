#include "enigme.h"

void generer_enigme(enigme *e){
	e->pos_selected=0;//initialement aucune réponse selectionné
	e->background= IMG_Load("img/background.png");//image de back
	e->button= IMG_Load("img/button.png");//boutton avant animation
	e->button_s= IMG_Load("img/button_s.png");//boutton aprés animation
	///////////////animation 
	e->pos_timer.x=772;
	e->pos_timer.y=50;
	e->num_animation=0;
	e->time_over=0;
	e->timer[0]=IMG_Load("timer0.png");
	e->timer[1]=IMG_Load("timer1.png");
	e->timer[2]=IMG_Load("timer2.png");
	e->timer[3]=IMG_Load("timer3.png");
	e->timer[4]=IMG_Load("timer4.png");
	e->timer[5]=IMG_Load("timer5.png");
	e->timer[6]=IMG_Load("timer6.png");
	e->timer[7]=IMG_Load("timer7.png");
	e->timer[8]=IMG_Load("timer8.png");
	e->timer[9]=IMG_Load("timer9.png");
	e->timer[10]=IMG_Load("timer10.png");
	e->timer[11]=IMG_Load("timer11.png");

	TTF_Init();
	TTF_Font *police = NULL,*police1=NULL;//déclaration

	SDL_Color couleur = {0,0,0};//noir

	police = TTF_OpenFont("arial.ttf", 30);//police des questions avec taille 30
	police1 = TTF_OpenFont("arial.ttf", 20);//police des réponses avec taille 20
	SDL_Surface *texte;

	char questionn[300];//chaine de caractére qui stocke les questions

	srand(time(NULL));//yet3ada mn question l question aléatoirement(ye5tar barsha marrat)
	e->num_question=rand()%4;//random question à chaque fois

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}///random question à chaque fois et parcours de num=0

	FILE *fquestion=NULL;
	fquestion=fopen("questions.txt","r+");
	if(fquestion!=NULL){
		int test=1;
		while (fgets(questionn, 300, fquestion) &&(test!=e->num_question)){
			test++;//si c'est pas la question aleatoire
		}
		
		fclose(fquestion);//mettre les questions lus de fquestion dans la chaine de caractére
	}//il cherche le numéro aléatoire et réccupére la question dans une chaine de caractére

	char reponse[50];

	int min,max;
    switch(e->num_question)
    {
    	case 1://q1
    	{
    		min=0;
    		max=2;//0,1,2
    		break;
    	}
    	case 2://q2
    	{
    		min=3;
    		max=5;//3,4,5
    		break;
    	}
    	case 3://q3
    	{
    		min=6;
    		max=8;//6,7,8
    		break;
    	}
    }

	FILE *freponse=NULL;
	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){
		int test=0;
		while (fgets((reponse),50, freponse) &&(test<max)){	//parcour
			//il réccupére les deux réponses fausses
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(police1, reponse, couleur);//t7otlk texte 3la surface bl police wl couleur li t7eb 3leha
			}
			test++;
		}	
		fclose(freponse);//récupération des deux réponses de freponse(les fausses réponses)
	}

	FILE *fvraireponse=NULL;
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		int test=1;
		while (fgets((reponse), 50, fvraireponse)){
			
			if(test==e->num_question){
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(police1, reponse, couleur);
			}//tektblk texte fi surface
			test++;
		}
		fclose(freponse);
	}//récupérer la bonne réponse et la mettre à cette surface

	srand(time(NULL));
	e->positionVraiReponse=rand()%3;

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%3;
	}//mettre la bonne réponse à une position aléatoire (entier)
	printf("%d\n",e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(police, questionn, couleur);

	e->pos_question.x=370;//position de la question 
	e->pos_question.y=300;

	e->pos_reponse1.x=475;//position rep1
	e->pos_reponse1.y=422;

	e->pos_reponse2.x=277;//position rep2
	e->pos_reponse2.y=548;

	e->pos_reponse3.x=666;//position rep3
	e->pos_reponse3.y=548;

	e->pos_reponse1txt.x=475+50;//position texte rep1 avec intervalle (50 taille de la chaine)
	e->pos_reponse1txt.y=422+30;

	e->pos_reponse2txt.x=277+50;//position texte rep2
	e->pos_reponse2txt.y=548+30;

	e->pos_reponse3txt.x=666+50;//position texte rep3
	e->pos_reponse3txt.y=548+30;


	Mix_AllocateChannels(20);//son
	SDL_WM_SetCaption("Enigme",NULL);//titre de la fenétre
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){

	}
	e->sound=Mix_LoadWAV("clic.wav");
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficher_enigme(enigme *e,SDL_Surface *ecran){
          switch(e->positionVraiReponse){
		case 1:{
	SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
	SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
	SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
	SDL_Flip(ecran);
                        break;
                         }
                     case 2:{

	SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
	SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);
	SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
	SDL_Flip(ecran);
                    break;
                         }
                      case 3:{

	SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
	SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
	SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);
	SDL_Flip(ecran);
                          break;
                         }
           	
}
}

void verify_enigme(enigme *e,SDL_Surface *ecran)
{       
	SDL_Rect pos={160,330};//x,y
	if(e->positionVraiReponse==e->pos_selected)//si la rép choisie est la bonne rép
	{
		//printf("You win\n");
		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);//affichage d'image de win
	}

//////time over
	else if (e->pos_selected==-1)
	{       
                
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);//affichage de you lost 
		
	}
	else 
	{       
                
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);//affichage de lost
		//printf("You lost\n");
	}
	SDL_Delay(200);//attente pour éviter l'encombrement
}

void animer (enigme *e){
		e->num_animation++;

		if(e->num_animation==12){
			e->num_animation=0;
			e->time_over=1;	
		}	

}
