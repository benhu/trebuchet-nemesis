#include "geneticFunctions.h"

using namespace std;



/*
  * Fonction d'evaluation
  * Pour chaque individu donne une valaure
  * @param pop la population
  * @param size la taille de la population
  * @return la variance pour la génération
  **/
double GeneticFunctions::evaluatePopulation(double** pop, int size, double distance){
    
    double totalScore = 0;
    double variance =0;
    double moyenne = 0;

    //Pour chaque individu on evalue
    for(int i=0; i < size; i++){
        //On evalue la viabilite 
        double* individual = pop[i];
        
        if(Utils::evalViability(individual) == 1){
            individual[7] = 1;
            
            //On evalue distance par rapport a l'objectif
            individual[7] += Utils::evalPortee(individual, distance);
            
            //Puis on evalue selon la puissance sur l'objectif (pas un caractere tres important sauf si objectif presque atteint attention divergence)
            //if(individual[7] > 1.3){
            individual[7] += Utils::evalPower(individual);
            //}
        }else{
            // Change le score
            individual[7] = 0.001;
        }

        totalScore += individual[7];
        variance += individual[7] *individual[7];
    }

    moyenne = totalScore/size;
    
    variance = variance/size;
    variance -= moyenne*moyenne;
    cout <<endl;
    cout << "moyenns : " << moyenne <<endl;
    cout << "Score : " << totalScore<<endl;
    cout << "Variance : " << variance << endl;

    return totalScore;
} 

 /*
  * Fonction de selection
  * Selectionne les individus
  *
  * @param
  * @return
  *
  */
double* GeneticFunctions::selectPopulation(double** pop, int len){
    double sumScore = 0;
    
    // on calcul le score total
    for(int i=0; i < len; sumScore+=pop[i][7], ++i);

    // on get une valeur random entre 0 et le score total
    double randVal = Utils::getRandValue(0.0, sumScore);

    double selectSumScore = 0;

    // on passe sur chaque individu
    for(int i=0; i < len; ++i)
    {
        selectSumScore += pop[i][7];
     
        // si la somme des score entre 0 et i est sup ou egal a
        // la valeur random alors nous avons notre individu
        if(selectSumScore >= randVal)
        {
            return pop[i];
        }
    }

    return NULL;
}

double** GeneticFunctions::mutPopulation(double** pop, int len){
    for(int i = 0; i < len; ++i)
    {
        double prob = Utils::getRandValue(0.0, 100.0);

        if(prob <= 1.0)
        {
            int index = (int)Utils::getRandValue(1.0, 6.0);

            pop[i][index] = Utils::getRandValue(1.0, 100.0);
        }

    }

    return pop;
}

double** GeneticFunctions::crossPopulation(double** pop, int len,  int* index){

    double** popResult = new double*[len];

    for(int popResultSize = 0; popResultSize < len; popResultSize+=2)
    {
        double changeCut = Utils::getRandValue(0.0, 100.0);

        if(changeCut <= 80)
        {
            *index = (int)Utils::getRandValue(1.0, 6.0);
        }

        double* dad = selectPopulation(pop, len);
        double* mum = selectPopulation(pop, len);

        double* newDad = new double[8];
        double* newMum = new double[8];

        memcpy(newDad, dad, 8 * sizeof(double));
        memcpy(newMum, mum, 8 * sizeof(double));
   
        for(int i = *index; i <= 6; ++i)
        {
            swap(newDad[i], newMum[i]);
        }
        
        newDad[8] = 0;
        newMum[8] = 0;

        popResult[popResultSize] = newDad;
        popResult[popResultSize + 1] = newMum;
    }

    delete(pop);

    return popResult;
}
