#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"

class geneticFunctions {
    
    public:
        geneticFunctions(){Utils utils();};
        
        void evaluatePopulation(double* pop);
        void selectPopulation();
        void crossPopulation();


    private:
        void crossCouple();
};
#endif // GENETICFUNCTIONS
