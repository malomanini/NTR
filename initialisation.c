#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

void initPacket(Packet *packet){
	packet->dateCreation=0;
	packet->bitsRestants=0;
}

void initBuffer(Buffer *bufferinit, Buffer *nextBuffer, Packet thePacket){
	bufferinit->thePacket=thePacket;
	bufferinit->nextBuffer=nextBuffer;
}

void initUser(User *user, Buffer bufferchain){
	int i = 0 ;
	user->distance=5;
	user->bufferVide=0;
	user->debitMoyen=0;
	user->sommeDelai=0;
	for(i = 0; i<128; i++)
	{
		user->debitsActuels[i]=0;
	}
	user->firstBuffer=bufferchain;
}

void initAntenne(Antenne *antenne){
	int i = 0;

	for(i = 0; i<NB_USERS; i++)
	{
		antenne->users[i].firstBuffer.nextBuffer = NULL;
		antenne->users[i].lastBuffer.nextBuffer = NULL;
		antenne->users[i].bufferVide = 1;
	}
}

void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i<NB_USERS/2; i++)
	{
		for(j = 0; j<128; i++){
			antenne->users[i].debitsActuels[j] = getSNR(3);
		}
	}
}

void produceBit(Antenne *antenne){
	int i = 0;

	for(i = 0; i < (NB_USERS/2); i++){

	}
	for(i = 0; i < (NB_USERS/2); i++){
		
	}
}


void consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	if(currentUser<(NB_USERS)){
		antenne->users[currentUser].firstBuffer.thePacket.bitsRestants = antenne->users[currentUser].firstBuffer.thePacket.bitsRestants - antenne->users[currentUser].debitsActuels[subCarrier];
		if(antenne->users[currentUser].firstBuffer.thePacket.bitsRestants <= 0){
			antenne->users[currentUser].firstBuffer = *antenne->users[currentUser].firstBuffer.nextBuffer;
			if((antenne->users[currentUser].firstBuffer.nextBuffer == NULL) && (antenne->users[currentUser].firstBuffer.thePacket.bitsRestants<1)){
				antenne->users[currentUser].bufferVide = 1;
			}
		}
	}
}

int MaxUser (Antenne *antenne, int j){
	User maxU;
	int far = 0;
	int i = 0;

	for (i = 0; i < NB_USERS/2 ; i++){ //parcourt les users
		//on regarde les Nears. (ils sont separes)
		if(antenne->users[i].debitsActuels[j] > maxU.debitsActuels[j] && !antenne->users[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = antenne->users[i];
			far = 0;
			}
		//on regarde les far aussi
		if(antenne->users[i].debitsActuels[j] > maxU.debitsActuels[j]  && !antenne->users[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = antenne->users[i];
			far = 1; 
			}
		}
	
	if(far){
		return (i+5);
	}
	else{
		return i;
	}
};

int empty(Antenne *antenne, int currentUser){
	if(currentUser < (NB_USERS/2)){
		return antenne->users[currentUser].bufferVide;
	}
	else{
		return antenne->users[currentUser - 5].bufferVide;
	}
}