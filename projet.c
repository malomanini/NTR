#include <stdio.h>
#include <stdlib.h>
#define NB_USERS 10
#define BUFFERS_PER_USER 10

typedef struct Packet Packet;
struct Packet
{
	int dateCreation;
	int bit;
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
	int debitActuel, debitMoyen;
	int debitsActuels[128][5];
	Buffer sendBuffer[BUFFERS_PER_USER];
};

typedef struct Antenne Antenne;
struct Antenne
{
	User usersNear[NB_USERS/2];
	User usersFar[NB_USERS/2];
};

int trameToSend[128][5];

<<<<<<< HEAD
int initMatriceDebits(Antenne *antenne);
=======
int RR (){
	/*
	alloue les ressources au tour par tour
	*/
	
}

int MaxSNR (){
	/*
	alloue les ressources en fonctions du meilleur debit possible
	*/
}

>>>>>>> ed9aa9f45b2712eef5d54ae4566b0feb47281f8d
int main(){
	Antenne* monAntenne;
	
	//---INITIALISATIONS---
	if(initAntenne(monAntenne) == -1){
		printf("Erreur lors de l'initialisation de l'antenne\n");
	}
	else{printf("Initialisation Antenne: OK\n");}


	//---BOUCLE PRINCIPALE---
	//Initilisations des matrices de débit des utilisateurs  


}

int initMatriceDebits(Antenne *antenne){
	int i;

	for(i = 0; i < NB_USERS/2; i++){
		
	}
}
