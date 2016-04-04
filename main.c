#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "maxSNR.h"
#include "initialisation.h"


int main(){

	long actualTime = 0;
	int debitTotal = 0;
	int nb_tours = 10;
	int i;

	Antenne monAntenne;

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n");
	/*printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);*/
	printf("Main 1\n");
	initAntenne(&monAntenne);
	printf("Main 2\n");
	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){
		printf("Main 3\n");
		/*Initialisation des paquets utilisateurs*/
		produceBit(&monAntenne, actualTime);
		printf("Main 4\n");
		/*Initilisations des débits des utilisateurs*/
		initMatriceDebits(&monAntenne);
		printf("Main 5\n");			

		/*Application de l'algorithme et ôtage des bits envoyés avec RR
		debitTotal += RR(&monAntenne);*/

		/*Application de l'algorithme et ôtage des bits envoyés avec maxSNR*/
		debitTotal += maxSNR(&monAntenne);

		printf("Main 6\n");
		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/


		/*Incrémentation du temps*/
		actualTime += 2;

	}
	
	printf("\nStatistiques : \n\n");
	printf("Débit total de la simulation: %d bits/ms\n", (int)(debitTotal/actualTime));


	return 0;
}

