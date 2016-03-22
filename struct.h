#ifndef STRUCT_H
#define STRUCT_H

#define NB_USERS 10
#define BUFFERS_PER_USER 10
#define PACKETS_CREATION_RATIO 50

typedef struct Packet Packet;
struct Packet
{
	int valeur[100];
	int dateCreation;
	int bitsRestants;
};

typedef struct Buffer Buffer;
struct Buffer
{
	Packet thePacket;
	Buffer *nextBuffer;
};

typedef struct User User;
struct User
{
	int bufferVide;
	int debitMoyen;
	int debitsActuels[128];
	int sommeDelai;
	Buffer firstBuffer;
	Buffer lastBuffer;
};

typedef struct Antenne Antenne;
struct Antenne
{
	User usersNear[NB_USERS/2];
	User usersFar[NB_USERS/2];
};

#endif
