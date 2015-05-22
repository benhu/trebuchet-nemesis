#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"

class GeneticFunctions {
    
    public:
        GeneticFunctions(){};
        
        double evaluatePopulation(double** pop, int size);
        double* selectPopulation(double** pop, int len);
        void crossPopulation(double** pop, int len,  int* index);

    private:
        void    crossCouple();
};
#endif // GENETICFUNCTIONS
