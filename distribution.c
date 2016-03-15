#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "distribution.h"
#include "initialisation.h"

int getSNR(User current){
  int r;
  srand(time(NULL));
  r = rand()% ((current.debitMoyen)+2) ;

  return r;
}

