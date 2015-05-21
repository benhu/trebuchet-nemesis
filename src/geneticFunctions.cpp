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
  * @param
  * @return
  *
  */
void GeneticFunctions::selectPopulation(){

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
void GeneticFunctions::crossPopulation(){

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
void GeneticFunctions::crossCouple(){

}
