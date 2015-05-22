#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"
#include <string.h>

class GeneticFunctions {
    
    public:
        GeneticFunctions(){};
        
        void evaluatePopulation(double** pop, int size);
        double* selectPopulation(double** pop, int len);
        double** crossPopulation(double** pop, int len,  int* index);
};
#endif // GENETICFUNCTIONS
