#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "RR.h"
#include "distribution.h"
#include "initialisation.h"

int RR(Antenne *antenne){
	int i = 0;
	int j = 0;
	int currentUser = 0;
	int debitTotalTrame = 0;

	for(i = 0; i<5 ; i++){
		for(j = 0; j<128 ; i++){
			
			debitTotalTrame += consumeBit(antenne, currentUser, j);
			currentUser = (currentUser+1) % NB_USERS;
		}
	}
	return debitTotalTrame;

}