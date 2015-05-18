//It is our future main class

#include <iostream>
#include "utils.h"
#include "geneticFunctions.h"

/**
* Classe qui représente la classe principale .
*/
using namespace std;

int main() {

    Utils* utils = new Utils();

    std::cout << utils->calculateForceTraction(5.2,3.0,2.0,14.0,6.0) << endl;

    //Variable variable
    //int nbGeneration = 100;
    //int sizePopulation = 100;



    //Creation population

    //Evaluation

    //Selection

    //Croisement/Mutation

    //Either(Termine, Evaluationdepop)



    return 0;
}
