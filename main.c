#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "initialisation.h"


int main(int argc, char *argv[]){

	long actualTime = 0;

	int nb_tours = 1000;
	int i, x, y;

	
	Packet thePacket;
	Buffer bufferinit;
	Buffer nextBuffer;
	Buffer bufferchain;
	User users;
	Antenne monAntenne;

	int trameToSend[128][5];

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n");
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);

	
	initPacket(&thePacket);
	initBuffer(&bufferinit, &nextBuffer, thePacket);
	initUser(&users, bufferchain);
	initAntenne(&monAntenne);
	printf("initMatriceDebits s'execute pas\n");
	/*initMatriceDebits(&monAntenne);*/
	printf("consumeBit s'execute pas\n");
	/*consumeBit(&monAntenne, 1, 1);*/
	MaxUser (&monAntenne, 1);
	empty(&monAntenne, 1);

	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){

		/*Initialisation des paquets utilisateurs*/

		/*Initilisations des débits des utilisateurs*/

		/*Application de l'algorithme et remplissage de trameToSend*/

		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/

		/*Nettoyage de trameToSend*/
		for(x = 0; x < 128; x++){
			for(y = 0; y < 5; y++){
				trameToSend[x][y] = 0;
			}
		}


		/*Incrémentation du temps*/
		actualTime += 2;

	}
	printf("FIN du programme\n");
	return 0;
}

