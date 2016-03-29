#ifndef STRUCT_H
#define STRUCT_H

#define NB_SUBCARRIERS 128
#define NB_USERS 10
#define BUFFERS_PER_USER 10
#define PACKETS_CREATION_RATIO 50

typedef struct Packet Packet;
struct Packet
{
	int valeur;
	int dateCreation;
	int bitsRestants;
};

typedef struct Buffer Buffer;
struct Buffer
{
	Packet thePacket;
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

