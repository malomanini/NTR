#include <stdio.h>
#include <stdlib.h>
#define NB_USERS
#define BUFFERS_PER_USER

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
	Buffer* nextBuffer = NULL;
};

typedef struct User User;
struct User
{
	int debitActuel, debitMoyen;
	Buffer sendBuffer[BUFFERS_PER_USER];
};
typedef struct Antenne Antenne;
struct Antenne
{
	
};

int trameToSend[128][5];

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

int main(){
	Antenne monAntenne;
		
	
}
