
#include "struct.h"

#ifndef INITIALISATION_H
#define INITIALISATION_H

Packet* createPacket();
void initUser(User user);
void initAntenne(Antenne *antenne);
void initMatriceDebits(Antenne *antenne);

void createPackets(Antenne *antenne);
void produceBit(Antenne *antenne, int actualTime);
int consumeBit(Antenne *antenne, int currentUser, int subCarrier);

#endif 

