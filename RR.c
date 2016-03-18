#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "RR.h"
#include "distribution.h"
#include "initialisation.h"

void RR(Antenne *antenne){
	int i = 0;
	int j = 0;
	int currentUser = 0;

	for(i = 0; i<5 ; i++){
		for(j = 0; j<128 ; i++){
			consumeBit(antenne, currentUser, j);
			currentUser = (currentUser+1) % NB_USERS;
		}
	}
}