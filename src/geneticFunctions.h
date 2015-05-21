#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"

class geneticFunctions {
    
    public:
        geneticFunctions(){Utils utils();};
        
        void    evaluatePopulation(double* pop);
        double* selectPopulation(double** pop, int len);
        void    crossPopulation();


    private:
        void    crossCouple();
};
#endif // GENETICFUNCTIONS
