#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

void initPacket(Packet *packet){
	packet->dateCreation=0;
	packet->bitsRestants=0;
	packet->valeur=0;
}

void initBuffer(Buffer *bufferinit, Packet *nextPacket, Packet thePacket){
	bufferinit->thePacket=thePacket;
	bufferinit->nextPacket=nextPacket;
}

void initUser(User *user, Packet thePacket){
	int i = 0 ;
	user->distance=5;
	user->bufferVide=0;
	user->debitMoyen=0;
	user->sommeDelai=0;
	for(i = 0; i<128; i++)
	{
		user->debitsActuels[i]=0;
	}
	user->leBuffer.thePacket=thePacket;
}

void initAntenne(Antenne *antenne){
	int i = 0;

	for(i = 0; i<NB_USERS; i++)
	{
		initPacket(&antenne->users[i].leBuffer.thePacket);
		initPacket(&antenne->users[i].leBuffer.nextPacket);
	}
}

void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i<NB_USERS; i++)
	{
		for(j = 0; j<128; i++){
			antenne->users[i].debitsActuels[j] = getSNR(3);
		}
	}
}

void produceBit(Antenne *antenne){
	int i = 0;

	for(i = 0; i < (NB_USERS); i++){

	}
}


void consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	if(currentUser<(NB_USERS)){
		antenne->users[currentUser].leBuffer.thePacket.bitsRestants = antenne->users[currentUser].leBuffer.thePacket.bitsRestants - antenne->users[currentUser].debitsActuels[subCarrier];
		if(antenne->users[currentUser].leBuffer.thePacket.bitsRestants <= 0){
			antenne->users[currentUser].leBuffer.thePacket = *antenne->users[currentUser].leBuffer.nextPacket;
			if((antenne->users[currentUser].leBuffer.nextPacket == NULL) && (antenne->users[currentUser].leBuffer.thePacket.bitsRestants<1)){
				antenne->users[currentUser].bufferVide = 1;
			}
		}
	}
}

int MaxUser (Antenne *antenne, int j){
	User maxU;
	int i = 0;
	int res;

	for (i = 0; i < NB_USERS ; i++){ //parcourt les users
		if(antenne->users[i].debitsActuels[j] > maxU.debitsActuels[j] && !antenne->users[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
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
