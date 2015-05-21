#include "geneticFunctions.h"

using namespace std;



/*
  * Fonction d'evaluation
  * Pour chaque individu donne une valaure
  * @param
  * @param
  * @return
  **/
void geneticFunctions::evaluatePopulation(double* pop){
    delete(pop);
    //Calcule de la variance si on ne varie plus on arrete ou si nbGeneration atteint

    //Pour chaque individu on evalue

        //On calcule la velocite

        //On evalue la viabilite si non viable on met 1
        //Sinon on evalue distance par rapport a objectif
            //Puis on evalue selon la puissance sur l'objectif (pas un caractere tres important sauf si objectif atteint)
} 

 /*
  * Fonction de selection
  * Selectionne les individus
  *
  * @param
  * @return
  *
  */
double* geneticFunctions::selectPopulation(double** pop, int len){
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
void geneticFunctions::crossPopulation(){
    
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
void geneticFunctions::crossCouple(){

}
