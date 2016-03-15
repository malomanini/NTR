#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "initialisation.h"


int main(int argc, char *argv[]){

	long actualTime = 0;

	int nb_tours;
	int i, x, y;

	Antenne* monAntenne;
	int trameToSend[128][5];

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n");
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);

		initAntenne(monAntenne);
	

	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){

		/*Initialisation des paquets utilisateurs*/

		/*Initilisations des débits des utilisateurs*/

		/*Application de l'algorithme et remplissage de trameToSend*/
		RR(trameToSend);
		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/

		/*Nettoyage de trameToSend*/
		for(x = 0; x < 128; x++){
			for(y = 0; y < 5; y++){
				trameToSend[x][y] = 0;
			}
		}


		/*Incrémentation du temps*/
		actualTime += 10;

	}

}

