#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "maxSNR.h"
#include "initialisation.h"


int main(){

	int debitTotal = 0;
	int debitTotalProche = 0;
	int debitTotalLoin = 0;

	int delaisTotal = 0;
	int delaisTotalProche = 0;
	int delaisTotalLoin = 0;

	int nbPaquetsTotal = 0;
	int nbPaquetsTotalProche = 0;
	int nbPaquetsTotalLoin = 0;

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
		produceBit(&monAntenne);
		/*Initilisations des débits des utilisateurs*/
		initMatriceDebits(&monAntenne);		
		
		/*Application de l'algorithme et ôtage des bits envoyés avec maxSNR*/
		if(choixAlgo == 1){
			debitTotal += RR(&monAntenne);
		}
		else if(choixAlgo == 2){
			debitTotal += maxSNR(&monAntenne);
		}
		else{
			printf("choix de l'algorithme mauvais. Arret. \n");
		}
		
		/*ENVOI DE LA TRAME */

		/*Mise à jours des délais*/


		/*Incrémentation du temps*/
		monAntenne.actualTime += 2;

	}

	for(i = 0; i< NB_USERS; i++){
		delaisTotal += monAntenne.users[i]->sommeDelais;
		nbPaquetsTotal += monAntenne.users[i]->sommePaquets;
		if(monAntenne.users[i]->distance == 5){	
			delaisTotalProche += monAntenne.users[i]->sommeDelais;
			nbPaquetsTotalProche += monAntenne.users[i]->sommePaquets;

		}
		else{	
			delaisTotalLoin += monAntenne.users[i]->sommeDelais;
			nbPaquetsTotalLoin += monAntenne.users[i]->sommePaquets;
		}

	}

	printf("\nStatistiques : \n");
	printf("	Débit total de la simulation: %d bits/ms\n", (int)(debitTotal/monAntenne.actualTime));
	printf("	Delai moyen : %d ms\n", (int)(delaisTotal/nbPaquetsTotal));
	printf("	Delai moyen des utilisateurs proches: %d ms\n", (int)(delaisTotalProche/nbPaquetsTotalProche));
	printf("	Delai moyen des utilisateurs eloignes: %d ms\n", (int)(delaisTotalLoin/nbPaquetsTotalLoin));





	return 0;
}

