#include "geneticFunctions.h"

using namespace std;



/*
  * Fonction d'evaluation
  * Pour chaque individu donne une valaure
  * @param pop la population
  * @param size la taille de la population
  * @return la variance pour la génération
  **/
double GeneticFunctions::evaluatePopulation(double** pop, int size){
    
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
            individual[7] += Utils::evalPortee(individual);
            
            //Puis on evalue selon la puissance sur l'objectif (pas un caractere tres important sauf si objectif presque atteint attention divergence)
            if(individual[7] > 1.3){
                individual[7] += Utils::evalPower(individual);
            }
        }else{
            // Change le score
            individual[7] = 0.001;
        }

        totalScore += individual[7];
        
    }

    moyenne = totalScore/size;
    variance = totalScore* totalScore;
    variance = variance/size;
    variance -= moyenne*moyenne;

    cout << "Variance" << variance<<endl;

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
    crossCouple(pop, len, index);
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
