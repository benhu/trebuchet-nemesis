//It is our future main class

#include <iostream>
#include "utils.h"

/**
* Classe qui représente la classe principale .
*/
using namespace std;

/*
  * Fonction d'evaluation
  * Pour chaque individu donne une valaure
  * @param
  * @param
  * @return
  **/
 void evaluateIndividual(){

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
  void selectIndividual(){

  }

int main() {

    Utils* utils = new Utils();

    std::cout << utils->calculateForceTraction(5.2,3.0,2.0,14.0,6.0) << endl;

    return 0;
}
