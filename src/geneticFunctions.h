#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"
#include <iostream>

class GeneticFunctions {
    
    public:
        GeneticFunctions(){};
        
        void evaluatePopulation(double** pop, int size);
        void selectPopulation();
        void crossPopulation();


    private:
        void crossCouple();
};
#endif // GENETICFUNCTIONS
