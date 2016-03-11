#include <stdio.h>
#include <stdlib.h>
#define NB_USERS

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

typedef struct Antenne Antenne;
struct Antenne
{
	//Creation d'un tableau contenant le premier buffer de chaque utilisateur
	Buffer sendBuffer[NB_USERS];
};

int trameToSend[128][5];

int main(){
	Antenne monAntenne;
		
	
}
