#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "maxSNR.h"
#include "distribution.h"
#include "initialisation.h"

int maxSNR(Antenne *antenne, int nb_user) {	
	int MaxU = 0;
	int g, j, debitTotalTrame = 0;
	int count = 0;
	for(g = 0; g < 5 ; g++){// parcours les timeslots, //tant que User.BufferVide > 0 ou que g<5, on transmet au debit actuel a cet user
	
		for(j = 0; j < 128 ; j++){ //parcourt les subcariers

			MaxU = MaxUser(antenne, j, nb_user);
			
			printf("maxU= %d   ", MaxU);

			while(empty(antenne, MaxU, nb_user)){
				MaxU = MaxUser(antenne, j, nb_user);
				count++;
				if(count>nb_user){

					return debitTotalTrame;
				}
			}
			debitTotalTrame += consumeBit(antenne, MaxU, j);
		}

	}
	return debitTotalTrame;
}
