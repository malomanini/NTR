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

	int choixAlgo = 0;
	int i;

	Antenne monAntenne;

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n\n");
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);
	printf("Algorithme : 1 pour RR, 2 pour MAXSNR :");
	scanf("%d", &choixAlgo);
	initAntenne(&monAntenne);

	/*---BOUCLE PRINCIPALE---*/
	for(i = 0; i < nb_tours; i++){

		/*Initialisation des paquets utilisateurs*/
		produceBit(&monAntenne, actualTime);
		/*Initilisations des débits des utilisateurs*/
		initMatriceDebits(&monAntenne);		

		/*Application de l'algorithme et ôtage des bits envoyés avec maxSNR*/
		if(choixAlgo == 1){
			debitTotal += RR(&monAntenne);
		}
		if(choixAlgo == 2){
			debitTotal += maxSNR(&monAntenne);
		}
		else{
			printf("choix de l'algorithme mauvais. Arret. \n");
		}
		
		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/


		/*Incrémentation du temps*/
		actualTime += 2;

	}
	
	printf("\nStatistiques : \n\n");
	printf("Débit total de la simulation: %d bits/ms\n", (int)(debitTotal/actualTime));




	return 0;
}

