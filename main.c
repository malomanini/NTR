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
	initAntenne(&monAntenne);
	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){
		/*Initialisation des paquets utilisateurs*/
		produceBit(&monAntenne, actualTime);
		/*Initilisations des débits des utilisateurs*/
		initMatriceDebits(&monAntenne);		

		/*Application de l'algorithme et ôtage des bits envoyés avec RR
		debitTotal += RR(&monAntenne);*/

		/*Application de l'algorithme et ôtage des bits envoyés avec maxSNR*/
		debitTotal += maxSNR(&monAntenne);
		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/


		/*Incrémentation du temps*/
		actualTime += 2;

	}
	
	printf("\nStatistiques : \n\n");
	printf("Débit total de la simulation: %d bits/ms\n", (int)(debitTotal/actualTime));




	return 0;
}

