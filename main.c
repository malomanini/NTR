#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "initialisation.h"


int main(int argc, char *argv[]){

	long actualTime = 0;
	int debitTotal;
	int nb_tours = 1000;
	int i, x, y;

	Antenne monAntenne;

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n");
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);

	initAntenne(&monAntenne);

	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){

		/*Initialisation des paquets utilisateurs*/
		produceBit(&monAntenne);

		/*Initilisations des débits des utilisateurs*/
		initMatriceDebits(&monAntenne);

		/*Application de l'algorithme et ôtage des bits envoyés*/
		debitTotal += RR(&monAntenne);

		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/


		/*Incrémentation du temps*/
		actualTime += 2;

	}
	
	printf("\nStatistiques : \n\n");
	printf("Débit total de la simulation: %d bits/ms\n", (int)(debitTotal/actualTime));


	return 0;
}

