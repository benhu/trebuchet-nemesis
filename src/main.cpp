//It is our future main clas
#include <iostream>
#include "utils.h"
#include "geneticFunctions.h"

/**
* Classe qui représente la classe principale .
*/
using namespace std;

double targetDist = 200.0;

double** generatePopulation(int size);
double getRandValue(double min, double max);

int main() {
    // Initialisation de random
    srand(time(NULL));

   // Utils* utils = new Utils();

    //Variable variable
    //int nbGeneration = 100;
    
    //Creation population
    int sizePopulation = 100;

    double** pop = generatePopulation(sizePopulation);

    cout << "100 : " << pop[99][0] << endl;

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
    
    for(int i = 0; i < size; ++i)
    {
        test[i] = new double[7];
        
        // hauteur butée
        test[i][0] = getRandValue(0.0, 90.0);
        // longueur du bras
        test[i][1] = getRandValue(1.0, 100.0);
        // masse du bras
        test[i][2] = getRandValue(1.0, 100.0);
        // longueur de la base
        test[i][3] = getRandValue(1.0, 100.0);
        // masse du contrepoids
        test[i][4] = getRandValue(1.0, 100.0);
        // masse du projectile
        test[i][5] = getRandValue(1.0, 100.0);
        // angle de la force
        test[i][6] = getRandValue(1.0, 90.0);
    }

    return test;
}

double getRandValue(double min, double max) {
    return (rand()/(double)RAND_MAX)*(max-min)+min;
}
