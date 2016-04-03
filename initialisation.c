#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "struct.h"

Packet* createPacket(){
	
	Packet *packet = malloc(sizeof(Packet));
	packet->dateCreation=0;
	packet->bitsRestants=0;
	packet->nextPacket = NULL;
	printf("createPacket\n");
	return packet;
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

	user.lePaquet = createPacket();
	printf("initUser bitsresteant  %d\n",user.lePaquet->bitsRestants);
}

void initAntenne(Antenne *antenne){
	int i = 0;

	for(i = 0; i < NB_USERS; i++)
	{
		initUser(antenne->users[i]);
	}
	printf("initAntenne SNRmoyen %d\n",&(antenne.users[i].SNRmoyen));
	printf("initAntenne bitsrestant %d\n",antenne.users[i].lePaquet->bitsRestants);
}



void initMatriceDebits(Antenne *antenne){
	int i = 0;
	int j = 0;

	for(i = 0; i<NB_USERS; i++)
	{
		for(j = 0; j<128; j++){
			antenne->users[i].SNRActuels[j] = getSNR(3);
		}
	}
}

/*!!! Amélioration possible en ajoutant un LastPacket */
void produceBit(Antenne *antenne, int actualTime){
	int i = 0;
	int random = 250;
	int debordement = 0;
	int resteARemplir = 0;


	/* Création d'un nouveau packet */
	Packet *packet;

	printf("produceBit1\n");
	for(i = 0; i < (NB_USERS); i++){
		printf("produceBit2\n");
		printf("produceBittest de i : %d \n",i );
		printf("produceBittest de NB_USERS : %d \n",NB_USERS );
		printf("produceBittest de SNRmoyen : %d \n",antenne->users[i].SNRmoyen );
		printf("produceBittest de bitsRestants : %d \n",antenne->users[i].lePaquet->bitsRestants );
		printf("produceBittest de distance : %d",antenne->users[i].distance );

		packet = antenne->users[i].lePaquet;
		printf("produceBit3\n");
		/* Recherche de la fin de la chaine */
		while(antenne->users[i].lePaquet->bitsRestants == 100){
			printf("produceBit4\n");
			packet = antenne->users[i].lePaquet->nextPacket;	
			printf("produceBit5\n");	
		}
							
		printf("produceBit6\n");
		/* Remplissage du paquet */
		resteARemplir = random;		
		while(resteARemplir > 0){
			debordement = resteARemplir - (100 - packet->bitsRestants);
			packet->bitsRestants = 100;
			resteARemplir -= debordement;

		}
		printf("EASY after\n");	
			
	}

}


int consumeBit(Antenne *antenne, int currentUser, int subCarrier){

	int debordement;

	if(currentUser<(NB_USERS)){
		printf("ent1\n");
		debordement = antenne->users[currentUser].lePaquet->bitsRestants - antenne->users[currentUser].SNRActuels[subCarrier];

		/* Mise à jour du nombre de bits restants dans le paquet / Consommation des bits */
		antenne->users[currentUser].lePaquet->bitsRestants = debordement;

		if(antenne->users[currentUser].lePaquet->bitsRestants <= 0){
			printf("ent2\n");

			/* Si ce n'est pas le dernier paquet, on décale les paquets et on continue de consommer */
			if(antenne->users[currentUser].lePaquet -> nextPacket != NULL){
				printf("ent3\n");
				antenne->users[currentUser].lePaquet = antenne->users[currentUser].lePaquet->nextPacket;
				printf("sortie3\n");
				antenne->users[currentUser].lePaquet->bitsRestants = 100 + debordement;
				printf("sortie3\n");
			}
			/* Sinon on marque le buffer comme vide */
			else{
				printf("ent4\n");
				antenne->users[currentUser].bufferVide = 1;
				printf("sortie4\n");
			}
			printf("sortie2\n");
		}
		printf("sortie1\n");
	}
				
	/* On retourne le nombre de bits ôtés */
	return antenne->users[currentUser].SNRActuels[subCarrier];
}



int MaxUser (Antenne *antenne, int j){
	User maxU;
	int i = 0;
	int res;

	for (i = 0; i < NB_USERS ; i++){ /* parcourt les users */
		if(antenne->users[i].SNRActuels[j] > maxU.SNRActuels[j] && !antenne->users[i].bufferVide){
			/* si l'User a un meilleur debit, et que son buffer n'est pas vide: il devient le MaxUser */
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
