#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

Packet* createPacket(){
	Packet *packet = malloc(sizeof(Packet));
	packet->dateCreation=0;
	packet->bitsRestants=0;
	packet->nextPacket = NULL;
	return packet;
}

void initUser(User user){
	int i = 0 ;

	user.distance=5;
	user.bufferVide=0;
	user.SNRmoyen=0;
	user.sommeDelai=0;
	for(i = 0; i<128; i++)
	{
		user.SNRActuels[i]=0;
	}
	createPacket(user.lePaquet);

}

void initAntenne(Antenne *antenne){
	int i = 0;

	for(i = 0; i < NB_USERS; i++)
	{
		initUser(antenne->users[i]);
	}
}



void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i<NB_USERS; i++)
	{
		for(j = 0; j<128; j++){
			antenne->users[i].SNRActuels[j] = getSNR(3);
		}
	}
}

/*!!! Amélioration possible en ajoutant un LastPacket */
void produceBit(Antenne *antenne, int actualTime){
	int i = 0;
	int random = 250;
	int debordement = 0;
	int resteARemplir = 0;

	
	/* Création d'un nouveau packet */
	Packet *packet = createPacket();

	
	for(i = 0; i < (NB_USERS); i++){
		*packet = antenne->users[i].lePaquet;
		/* Recherche de la fin de la chaine */
		while(packet->bitsRestants == 100){
			packet = antenne->users[i].lePaquet.nextPacket;		
		}

		/* Remplissage du paquet */
		resteARemplir = random;		
		while(resteARemplir > 0){
			debordement = resteARemplir - (100 - packet->bitsRestants);
			packet->bitsRestants = 100;
			resteARemplir -= debordement;

		}

		
	}
}


int consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	int debordement;

	if(currentUser<(NB_USERS)){
		debordement = antenne->users[currentUser].lePaquet.bitsRestants - antenne->users[currentUser].SNRActuels[subCarrier];

		/* Mise à jour du nombre de bits restants dans le paquet / Consommation des bits */
		antenne->users[currentUser].lePaquet.bitsRestants = debordement;

		/* Mise à jour du buffer si le paquet actuel est vide*/
		if(antenne->users[currentUser].lePaquet.bitsRestants <= 0){

			antenne->users[currentUser].lePaquet = *(antenne->users[currentUser].lePaquet.nextPacket);

			antenne->users[currentUser].lePaquet.bitsRestants = 100 + debordement;
			
			/* Mise à jour du champ */
			if((antenne->users[currentUser].lePaquet.nextPacket == NULL) && (antenne->users[currentUser].lePaquet.bitsRestants<1)){
				antenne->users[currentUser].bufferVide = 1;
			}
		}
	}

	/* On retourne le nombre de bits ôtés */
	return antenne->users[currentUser].SNRActuels[subCarrier];
}



int MaxUser (Antenne *antenne, int j){
	User maxU;
	int i = 0;
	int res;

	for (i = 0; i < NB_USERS ; i++){ /* parcourt les users */
		if(antenne->users[i].SNRActuels[j] > maxU.SNRActuels[j] && !antenne->users[i].bufferVide){
			/* si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser */
			maxU = antenne->users[i];
			res = i;
			}
	
	return res;
}
}

int empty(Antenne *antenne, int currentUser){
	if(currentUser < NB_USERS){
		return antenne->users[currentUser].bufferVide;
	}
}
