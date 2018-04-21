#include "foo.h"

double add(double f, int total)
{
    double sum = 0.0;     
    for (int i = 0; i < total; ++i)
    {    
        sum += f;
    }
   return sum;
}
