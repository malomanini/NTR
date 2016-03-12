#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"
#include "RR.h"
#include "initialisation.h"

#define NB_USERS 10
#define BUFFERS_PER_USER 10

typedef struct Packet Packet;
struct Packet
{
	int dateCreation;
	int bitsRestants;
};

typedef struct Buffer Buffer;
struct Buffer
{
	Packet thePacket;
	Buffer* nextBuffer;
};

typedef struct User User;
struct User
{
	int bufferVide;
	int debitMoyen;
	int debitsActuels[128];
	Buffer bufferChain;
};

typedef struct Antenne Antenne;
struct Antenne
{
	User usersNear[NB_USERS/2];
	User usersFar[NB_USERS/2];
};

void initMatriceDebits(Antenne *antenne);

int main(){

	long actualTime = 0;
	int nb_tours;
	int i, x, y;

	Antenne* monAntenne;
	int trameToSend[128][5];

	//---INITIALISATIONS---
	printf("\nSIMULATION NTR\n");
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);

	

	//---BOUCLE PRINCIPALE---
	for(i = 0; i < nb_tours; i++){

		//Initialisation des paquets utilisateurs

		//Initilisations des débits des utilisateurs

		//Application de l'algorithme et remplissage de trameToSend

		// * ENVOI DE LA TRAME * 

		//Mise à jours des délais

		//Nettoyage de trameToSend
		for(x = 0; x < 128; x++){
			for(y = 0; y < 5; y++){
				trameToSend[x][y] = 0;
			}
		}

		//Incrémentation du temps
		actualTime += 10;

	}
}

