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

	for(i = 0; i<NB_USERS/2; i++)
	{
		antenne->usersFar[i].firstBuffer.nextBuffer = NULL;
		antenne->usersFar[i].lastBuffer.nextBuffer = NULL;
		antenne->usersFar[i].bufferVide = 1;
		antenne->usersNear[i].firstBuffer.nextBuffer = NULL;
		antenne->usersNear[i].lastBuffer.nextBuffer = NULL;
		antenne->usersNear[i].bufferVide = 1;
	}
}

void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i<NB_USERS/2; i++)
	{
		for(j = 0; j<128; i++){
			antenne->usersFar[i].debitsActuels[j] = getSNR(3);
			antenne->usersNear[i].debitsActuels[j] = getSNR(5);
		}
	}
}

void consumeBit(Antenne *antenne, int currentUser, int subCarrier){
	/*NearUser*/

	if(currentUser<(NB_USERS/2)){
		antenne->usersNear[currentUser].firstBuffer.thePacket.bitsRestants = antenne->usersNear[currentUser].firstBuffer.thePacket.bitsRestants - antenne->usersNear[currentUser].debitsActuels[subCarrier];
		if(antenne->usersNear[currentUser].firstBuffer.thePacket.bitsRestants <= 0){
			antenne->usersNear[currentUser].firstBuffer = *antenne->usersNear[currentUser].firstBuffer.nextBuffer;
			if((antenne->usersNear[currentUser].firstBuffer.nextBuffer == NULL) && (antenne->usersNear[currentUser].firstBuffer.thePacket.bitsRestants<1)){
				antenne->usersNear[currentUser].bufferVide = 1;
			}
		}
	}
	//User far
	else{
		currentUser = currentUser-5;

		antenne->usersFar[currentUser].firstBuffer.thePacket.bitsRestants = antenne->usersFar[currentUser].firstBuffer.thePacket.bitsRestants - antenne->usersFar[currentUser].debitsActuels[subCarrier];
		if(antenne->usersFar[currentUser].firstBuffer.thePacket.bitsRestants <= 0){
			antenne->usersFar[currentUser].firstBuffer = *antenne->usersFar[currentUser].firstBuffer.nextBuffer;
			if((antenne->usersFar[currentUser].firstBuffer.nextBuffer == NULL) && (antenne->usersFar[currentUser].firstBuffer.thePacket.bitsRestants <1)){
				antenne->usersFar[currentUser].bufferVide = 1;
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
		if(antenne->usersNear[i].debitsActuels[j] > maxU.debitsActuels[j] && !antenne->usersNear[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = antenne->usersNear[i];
			far = 0;
			}
		//on regarde les far aussi
		if(antenne->usersFar[i].debitsActuels[j] > maxU.debitsActuels[j]  && !antenne->usersFar[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = antenne->usersFar[i];
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
		return antenne->usersNear[currentUser].bufferVide;
	}
	else{
		return antenne->usersFar[currentUser - 5].bufferVide;
	}
}