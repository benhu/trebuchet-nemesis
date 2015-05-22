#ifndef GENETICFUNCTIONS_H
#define GENETICFUNCTIONS_H

#include "utils.h"
#include <string.h>

class GeneticFunctions {
    
    public:
        GeneticFunctions(int size, int nbGen):sizePop(size), nbGeneration(nbGen), cptGeneration(0){
        	variances = new double[nbGeneration]; 
        	scoreTotale = new double[nbGeneration];
        };
        
        double evaluatePopulation(double** pop, int size, double distance);
        double* selectPopulation(double** pop, int len);
        double** crossPopulation(double** pop, int len,  int* index);
        double** mutPopulation(double** pop, int len);

        double* getVariances(){return variances;}
        void showVariances();

    private:

    	int sizePop;
    	int nbGeneration;
    	int cptGeneration;

    	double* variances;
    	double* scoreTotale;
};
#endif // GENETICFUNCTIONS
