#include "geneticFunctions.h"

using namespace std;



/*
  * Fonction d'evaluation
  * Pour chaque individu donne une valaure
  * @param
  * @param
  * @return
  **/
void GeneticFunctions::evaluatePopulation(double** pop, int size){
    //Calcule de la variance si on ne varie plus on arrete ou si nbGeneration atteint

    //Pour chaque individu on evalue
    for(int i=0; i < size; i++){
        //On evalue la viabilite 
        double* individual = pop[i];
        
        if(Utils::evalViability(individual) == 1){
            individual[7] = 1;
            
            //On evalue distance par rapport a l'objectif
            individual[7] += Utils::evalPortee(individual);
            
            //Puis on evalue selon la puissance sur l'objectif (pas un caractere tres important sauf si objectif presque atteint attention divergence)
            if(individual[7] > 1.3){
                individual[7] += Utils::evalPower(individual);
            }
        }else{
            // Change le score
            individual[7] = 0.001;
        }
    }
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
    
    for(int i=0; i < len; sumScore+=pop[i][7], ++i);

    double randVal = Utils::getRandValue(0.0, sumScore);

    double selectSumScore = 0;

    for(int i=0; i < len; ++i)
    {
        selectSumScore += pop[i][7];
        
        if(selectSumScore >= randVal)
        {
            return pop[i];
        }
    }

    return NULL;
}

  /*
  * Fonction de croisement
  * Croise des individus
  *
  * @param
  * @param
  * @return
  *
  */
void GeneticFunctions::crossPopulation(double** pop, int len,  int* index){
    double changeCut = Utils::getRandValue(0.0, 100.0);

    if(changeCut <= 50)
    {
        *index = (int)Utils::getRandValue(0.0, 7.0);
    }

    double* dad = selectPopulation(pop, len);
    double* mum = selectPopulation(pop, len);
   
    cout << dad[0] << " " << mum[0] << endl;

    for(int i = *index; i <= 7; ++i)
    {
        swap(dad[i], mum[i]);
    }
}

  /*
  * Fonction de croisement
  * Croise des individus
  *
  * @param
  * @param
  * @return
  *
  */
void GeneticFunctions::crossCouple(double** pop, int len,  int* index){
    double changeCut = Utils::getRandValue(0.0, 100.0);

    if(changeCut <= 50)
    {
        *index = (int)Utils::getRandValue(0.0, 7.0);
    }

    double* dad = selectPopulation(pop, len);
    double* mum = selectPopulation(pop, len);
   
    cout << dad[0] << " " << mum[0] << endl;

    for(int i = *index; i <= 7; ++i)
    {
        swap(dad[i], mum[i]);
    }
}
