#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

int randDist = 0;

Packet* createPacket(){
	
	Packet *packet = malloc(sizeof(Packet));
	packet->dateCreation=0;
	packet->bitsRestants=0;
	packet->nextPacket = NULL;
	return packet;
}

User* initUser(){
	int i = 0 ;
	User *user = malloc(sizeof(User));

	if(randDist%2 == 0){
		user->distance=3;
	}
	else{
		user->distance=5;
	}
	user->bufferVide=0;
	user->SNRmoyen=0;
	user->sommeDelai=0;
	for(i = 0; i<128; i++)
	{
		user->SNRActuels[i]=0;
	}

	user->lePaquet = createPacket();
	randDist++;
	return user;
}

void initAntenne(Antenne *antenne){
	int i = 0;
	for(i = 0; i < NB_USERS; i++)
	{	
		antenne->users[i]=initUser();
	}
	
}



void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i < NB_USERS; i++)
	{
		for(j = 0; j<128; j++){

			antenne->users[i]->SNRActuels[j] = getSNR(antenne->users[i]->distance);
			//printf("initMatriceDebits i :%d j :%d bitsRestants = %d \n", i,j,antenne->users[i]->SNRActuels[j]);
		}
	}
}


//!!! Amélioration possible en ajoutant un LastPacket 
void produceBit(Antenne *antenne, int actualTime){
	int i = 0;
	int random = 250;
	int debordement = 0;
	int resteARemplir = 0;
	int temp = 0;


	// Création d'un nouveau packet 
	Packet *packet;
	
	for(i = 0; i < (NB_USERS); i++){
		packet=NULL;
		random=250;
		packet = antenne->users[i]->lePaquet;
		//recupere le dernier paquet
		while(packet->nextPacket != NULL)
			{
            	packet = packet->nextPacket;
        	}

		while(random > 0){
			temp = 100 - packet->bitsRestants;
			//si supérieur a 100 il faut utiliser un autre packet
			if((packet->bitsRestants + random) > 100){

				packet->bitsRestants = 100;
				packet->dateCreation = actualTime;
				random = random - temp;
				//creationnouveaupaquet
				packet->nextPacket = createPacket();
				packet = packet->nextPacket;
			}else{
				packet->bitsRestants = packet->bitsRestants + random;
				random = 0;

				if(packet->bitsRestants){
					packet->dateCreation = actualTime;
					//creationnouveaupaquet
					packet->nextPacket = createPacket();
					packet = packet->nextPacket;
				}
			}
		}
	}


}


int consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	int debordement;

	if(currentUser<(NB_USERS)){
		//printf("consumeBit1\n");
		debordement = antenne->users[currentUser]->lePaquet->bitsRestants - antenne->users[currentUser]->SNRActuels[subCarrier];
		//printf("consumeBit2 debordement= %d\n",debordement);
		// Mise à jour du nombre de bits restants dans le paquet / Consommation des bits 
		antenne->users[currentUser]->lePaquet->bitsRestants = debordement;

		if(antenne->users[currentUser]->lePaquet->bitsRestants <= 0){
			//printf("consumeBit3\n");

			// Si ce n'est pas le dernier paquet, on décale les paquets et on continue de consommer 
			if(antenne->users[currentUser]->lePaquet -> nextPacket != NULL){
				//printf("consumeBit4\n");
				antenne->users[currentUser]->lePaquet = antenne->users[currentUser]->lePaquet->nextPacket;
				//printf("consumeBit5\n");
				antenne->users[currentUser]->lePaquet->bitsRestants = 100 + debordement;
				//printf("consumeBit6\n");
			}
			// Sinon on marque le buffer comme vide 
			else{
				//printf("consumeBit7\n");
				antenne->users[currentUser]->bufferVide = 1;
				//printf("consumeBit8\n");
			}
			//printf("consumeBit9\n");
		}
		//printf("consumeBit10\n");
	}
				
	// On retourne le nombre de bits côtés 
	return antenne->users[currentUser]->SNRActuels[subCarrier];
}



int MaxUser (Antenne *antenne, int subCarrier){
	int i = 0;
	int res = 0;


	for (i = 0; i < NB_USERS ; i++){
		if((antenne->users[i]->SNRActuels[subCarrier] > antenne->users[res]->SNRActuels[subCarrier]) && (antenne->users[i]->bufferVide == 0)){
			// si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser 
			res = i;
			}
	}

	return res;
}

int empty(Antenne *antenne, int currentUser){
	if(currentUser < NB_USERS){
		return antenne->users[currentUser]->bufferVide;
	}
}