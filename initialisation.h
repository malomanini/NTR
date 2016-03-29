
#include "struct.h"

#ifndef INITIALISATION_H
#define INITIALISATION_H

void initPacket(Packet *packet);
void initBuffer(Buffer *bufferinit, Packet *nextPacket, Packet thePacket);
void initUser(User *user, Packet thePacket);
void initAntenne(Antenne *antenne);
void initMatriceDebits(Antenne *antenne);

void createPackets(Antenne *antenne);

#endif /* INITIALISATION_H*/

