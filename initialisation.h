#include "struct.h"

#ifndef INITIALISATION_H
#define INITIALISATION_H




void initPacket(Packet *packet);
void initBuffer(Buffer *bufferinit, Buffer *nextBuffer, Packet thePacket);
void initUser(User *user, Buffer bufferchain);
void initAntenne(Antenne *antenne);
void initMatriceDebits(Antenne *antenne);

#endif /* INITIALISATION_H*/
