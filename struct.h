#ifndef STRUCT_H
#define STRUCT_H

#define NB_SUBCARRIERS 128
#define NB_USERS 10
#define NB_TIME_SLOTS 5 
#define BUFFERS_PER_USER 10
#define PACKETS_CREATION_RATIO 50

typedef struct Packet Packet;
struct Packet
{
	int dateCreation;
	/*Nombre de bits dans le paquet (MAX = 100) */
	int bitsRestants;
};

typedef struct Buffer Buffer;
struct Buffer
{
	/*Paquet destiné à etre consommé prochainement */
	Packet thePacket;
	/*Suite de la liste */
	Packet *nextPacket;
};

typedef struct User User;
struct User
{
	int distance;
	int bufferVide;
	int SNRmoyen;
	int SNRActuels[NB_SUBCARRIERS];
	int sommeDelai;
	Buffer leBuffer;
};

typedef struct Antenne Antenne;
struct Antenne
{
	User users[NB_USERS];
};

#endif

