#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "RR.h"
#include "distribution.h"
#include "initialisation.h"

User MaxUser (Antenne *antenne, int j){
	//initialisation des variables Users utilises dans l'algo.
	Buffer buffini;
	buffini.packet = 0;
	buffini.nextBuffer = NULL;
	User maxU;
	maxU.bufferVide = 0;
	maxU.debitMoyen = 0;
	maxU.bufferChain = buffini;

	for (int i = 0; i < NB_USERS/2 ; i++){ //parcourt les users
		//on regarde les Nears. (ils sont separes)
		if(a.userNear[i].debitActuels[j] > maxU.debitActuels[j] && !a.userNear[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = a.userNear[i];
			}
		//on regarde les far aussi
		if(a.userFar[i].debitActuels[j] > maxU.debitActuels[j]  && !a.userFar[i].bufferVide){
			//si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser
			maxU = a.userFar[i];
			}
		}
	
	return maxU;
};


void MaxSNR(Antenne *antenne) {	
	User MaxU;
	int g, j;
	for( j = 0; j < 128 ; j++){ //parcourt les subcariers
		MaxU = MaxUser(j);

		for(int g = 0; g < 5 ; g++){// parcours les timeslots, //tant que User.BufferVide > 0 ou que g<5, on transmet au debit actuel a cet user
			if(MaxU.bufferVide){
				MaxU = MaxUser(antenne,j);
			}
			consumeBit(currentUser, j);
		}

	}
}
			
	