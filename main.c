#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "distribution.h"
#include "RR.h"
#include "maxSNR.h"
#include "initialisation.h"


int main(){
	FILE* fichier = NULL;

	double debitTotal = 0;
	/*int debitTotalProche = 0;
	int debitTotalLoin = 0;*/

	double sommeDelais = 0;
	int sommeDelaisProche = 0;
	int sommeDelaisLoin = 0;

	int nbPaquetsTotal = 0;
	int nbPaquetsTotalProche = 0;
	int nbPaquetsTotalLoin = 0;
	Antenne monAntenne;
	Packet *tmpPacket = NULL;

	int nb_user = 0;
	int nb_tours = 10;
	int nbBitsgenere = 250;
	int choixAlgo = 0;

	int i;
	
	
	

	/*---INITIALISATIONS---*/
	printf("\nSIMULATION NTR\n\n");
	printf("Nombre d'utilisateur pour la simulation: ");
	scanf("%d", &nb_user);
	printf("Nombre de tours pour la simulation: ");
	scanf("%d", &nb_tours);
	printf("Nombre de bits à générer (>100) :");
	scanf("%d", &nbBitsgenere);
	printf("Algorithme : 1 pour RR, 2 pour MAXSNR :");
	scanf("%d", &choixAlgo);

	initAntenne(&monAntenne, nb_user);

	while(nb_user <= 200){
		/*---BOUCLE PRINCIPALE---*/
		for(i = 0; i < nb_tours; i++){
			
			/*Initialisation des paquets utilisateurs*/
			produceBit(&monAntenne, nbBitsgenere, nb_user);
			/*Initilisations des débits des utilisateurs*/
			initMatriceDebits(&monAntenne, nb_user);		
		
			/*Application de l'algorithme et ôtage des bits envoyés avec maxSNR*/
			if(choixAlgo == 1){
				debitTotal += (double)RR(&monAntenne, nb_user);
			}
			else if(choixAlgo == 2){
				debitTotal += (double)maxSNR(&monAntenne, nb_user);
			}
			else{
				printf("choix de l'algorithme mauvais. Arret. \n");
			}
		

			/*ENVOI DE LA TRAME */

			/*Mise à jours des délais*/


			/*Incrémentation du temps*/
			monAntenne.actualTime += 2;

		}


		for(i = 0; i< nb_user; i++){
			/* Récupération des délais restants dans les paquets non envoyes */
			if(monAntenne.users[i]->lePaquet != NULL){

				tmpPacket = monAntenne.users[i]->lePaquet;
				while(tmpPacket->nextPacket != NULL){
					sommeDelais += (monAntenne.actualTime - tmpPacket->dateCreation);
					nbPaquetsTotal ++;
					tmpPacket = tmpPacket->nextPacket;
					
		        }

			}
			/* Récupération des delais et paquets enregistrés */
			sommeDelais += monAntenne.users[i]->sommeDelais;
			nbPaquetsTotal += monAntenne.users[i]->sommePaquets;
			if(monAntenne.users[i]->distance == 5){	
				sommeDelaisProche += monAntenne.users[i]->sommeDelais;
				nbPaquetsTotalProche += monAntenne.users[i]->sommePaquets;

			}
			else{	
				sommeDelaisLoin += monAntenne.users[i]->sommeDelais;
				nbPaquetsTotalLoin += monAntenne.users[i]->sommePaquets;
			}




		}




		printf("\nStatistiques pour %d utilisateurs: \n", nb_user);
		printf("	Débit total : %f bits\n", debitTotal);
		printf("	Somme des delais: : %f bits\n", sommeDelais);
		printf("	Débit total de la simulation: %f bits/ms\n", (double)(debitTotal/monAntenne.actualTime));
		printf("	nbPaquetsTotal : %d paquets\n", nbPaquetsTotal);

		printf("	Delai moyen : %f ms\n", (double)(sommeDelais/nbPaquetsTotal));
		/*
		printf("	Delai moyen des utilisateurs proches: %d ms\n", (int)(sommeDelaisProche/nbPaquetsTotalProche));
		printf("	Delai moyen des utilisateurs eloignes: %d ms\n", (int)(sommeDelaisLoin/nbPaquetsTotalLoin));
*/

	    
	 
		    fichier = fopen("test.csv", "a");
		 
		    if (fichier != NULL)
		    {
		 
		  /*     fprintf(fichier,"%d;%d;%d;%d\n", debitTotal/monAntenne.actualTime, delaisTotal/nbPaquetsTotal, delaisTotalProche/nbPaquetsTotalProche, delaisTotalLoin/nbPaquetsTotalLoin);
		 */
			fclose(fichier);
		    }

		nb_user=nb_user+5;
		
		debitTotal = 0;

		sommeDelais = 0;
		sommeDelaisProche = 0;
		sommeDelaisLoin = 0;

		nbPaquetsTotal = 0;
		nbPaquetsTotalProche = 0;
		nbPaquetsTotalLoin = 0;

		initAntenne(&monAntenne, nb_user);	
	
	
	}



	return 0;
}


















