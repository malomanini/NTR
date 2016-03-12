
#ifndef INITIALISATION_H
#define INITIALISATION_H

#define NB_USERS 10
#define BUFFERS_PER_USER 10

typedef struct Packet Packet;
struct Packet
{
	int dateCreation;
	int bitsRestants;
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
	int bufferVide;
	int debitMoyen;
	int debitsActuels[128];
	Buffer bufferChain;
};

typedef struct Antenne Antenne;
struct Antenne
{
	User usersNear[NB_USERS/2];
	User usersFar[NB_USERS/2];
};

void initAntenne(Antenne *antenne);
void initMatriceDebits(Antenne *antenne);

#endif // INITIALISATION_H