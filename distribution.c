#include <stdio.h>
#include <stdlib.h>

#include "distribution.h"

//loi de  rayleigh

/* 
   RAND is a macro which returns a pseudo-random numbers from a uniform
   distribution on the interval [0 1]
*/
#define RAND ((double) rand())/((double) RAND_MAX)
 
/*
   TWOPI = 2.0*pi
*/
#define TWOPI 2.0*3.141592653589793238462643383279502884197169399375
 
/* 
   RANDN is a macro which returns a pseudo-random numbers from a normal
   distribution with mean zero and standard deviation one. This macro uses Box
   Muller's algorithm
*/
#define RANDN sqrt(-2.0*log(RAND))*cos(TWOPI*RAND)
 
 
double NormalDistribution(double mu,double sigma)
{
/*
   This function returns a pseudo-random numbers from a normal distribution with
   mean equal at mu and standard deviation equal at sigma > 0
*/
  if(sigma<=0.0)
  {
    fprintf(stderr,"Error in file %s line %u function %s : sigma must be > 0\nExit program\n",__FILE__,__LINE__,__FUNCTION__);
    exit(EXIT_FAILURE);
  }
 
  return (mu+sigma*RANDN);
 
}