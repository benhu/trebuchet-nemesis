//It is our future main class

#include <iostream>
#include "utils.h"
#include "geneticFunctions.h"

/**
* Classe qui représente la classe principale .
*/
using namespace std;

double targetDist = 100.0;

double** generatePopulation(int size);
double getRandValue(double min, double max);

int main() {
    // Initialisation de random
    srand(time(NULL));

   // Utils* utils = new Utils();

    //cout<< utils
    //std::cout << utils->calculateForceTraction(5.2,3.0,2.0,14.0,6.0) << endl;

    //Variable variable
    //int nbGeneration = 100;
    int sizePopulation = 100;

    generatePopulation(sizePopulation);

    //Creation population

    //Evaluation

    //Selection

    //Croisement/Mutation

    //Either(Termine, Evaluationdepop)

    return 0;
}

/**
 * Generate population with specific genes
 *    
 *   0 La hauteur du la butée en ° , alpha
 *   1 La longueur du bras en m Lb
 *   2 La masse du bras en kg mb
 *   3 Longueur de la base en m Lr
 *   4 La masse du contre poids en kg mc
 *   5 La masse du projectile en kg mp
 *   6 L'angle de la force de traction en ° beta
 *
 */
double** generatePopulation(int size) {
    double** test = new double*[size];
    test[1] = new double[7];
    return test;
}

double getRandValue(double min, double max) {
    return (rand()/(double)RAND_MAX)*(max-min)+min;
}
