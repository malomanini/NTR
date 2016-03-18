#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "RR.h"
#include "distribution.h"
#include "initialisation.h"


void MaxSNR() {	
	int MaxU;
	int g, j;
	for( j = 0; j < 128 ; j++){ //parcourt les subcariers
		MaxU = MaxUser();

		for(int g = 0; g < 5 ; g++){// parcours les timeslots, //tant que User.BufferVide > 0 ou que g<5, on transmet au debit actuel a cet user
			if(empty(MaxU)){
				MaxU = MaxUser();
			}
			consumeBit(MaxUser, j);
		}

	}
}
			
	