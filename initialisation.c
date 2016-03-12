#include <stdio.h>
#include <stdlib.h>

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

}