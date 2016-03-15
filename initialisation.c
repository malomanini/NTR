#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"

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




