#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "distribution.h"
#include "initialisation.h"

int getSNR(int distance){
  int r;
  srand(time(NULL));
  r = (rand() % distance)*2 ;

  return r;
}



