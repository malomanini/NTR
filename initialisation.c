#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

void initPacket(Packet packet){
	packet.dateCreation=0;
	packet.bitsRestants=0;
	packet.valeur=0;
}

void initBuffer(Buffer buffer){
	initPacket(buffer.thePacket);
	buffer.nextPacket = NULL;
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
	initBuffer(user.leBuffer);

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
		for(j = 0; j<128; i++){
			antenne->users[i].SNRActuels[j] = getSNR(3);
		}
	}
}

void produceBit(Antenne *antenne){
	int i = 0;

	for(i = 0; i < (NB_USERS); i++){

	}
}


int consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	if(currentUser<(NB_USERS)){
		antenne->users[currentUser].leBuffer.thePacket.bitsRestants = antenne->users[currentUser].leBuffer.thePacket.bitsRestants - antenne->users[currentUser].SNRActuels[subCarrier];
		if(antenne->users[currentUser].leBuffer.thePacket.bitsRestants <= 0){
			antenne->users[currentUser].leBuffer.thePacket = *antenne->users[currentUser].leBuffer.nextPacket;
			if((antenne->users[currentUser].leBuffer.nextPacket == NULL) && (antenne->users[currentUser].leBuffer.thePacket.bitsRestants<1)){
				antenne->users[currentUser].bufferVide = 1;
			}
		}
	}
	return antenne->users[currentUser].SNRActuels[subCarrier];
}

int MaxUser (Antenne *antenne, int j){
	User maxU;
	int i = 0;
	int res;

	for (i = 0; i < NB_USERS ; i++){ //parcourt les users
		if(antenne->users[i].SNRActuels[j] > maxU.SNRActuels[j] && !antenne->users[i].bufferVide){
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
