#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"

void initAntenne(Antenne *antenne){
	int i = 0;

	for(i = 0; i<NB_USERS/2; i++)
	{
		antenne->usersFar[i].bufferChain.nextBuffer = NULL;
		antenne->usersFar[i].bufferVide = 1;
		antenne->usersNear[i].bufferChain.nextBuffer = NULL;
		antenne->usersNear[i]bufferVide = 1;
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

void initUser(User *user){
	User->bufferVide=0;
	User->debitMoyen=0;
	for(i = 0; i<128; i++)
	{
		User->debitsActuels[i]=0;
	}
	User->bufferChain=NULL;
}
