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
void     showPopulation(double** pop, int size, int generation);   

int main() {
    // Initialisation de random
    srand(time(NULL));

   // Utils* utils = new Utils();

    GeneticFunctions* genetic = new GeneticFunctions();

    //Variable variable
    //int nbGeneration = 100;
    
    //Creation population
    int sizePopulation = 100;

    double** pop = generatePopulation(sizePopulation);

    genetic->evaluatePopulation(pop,sizePopulation);

    showPopulation(pop,sizePopulation,1);

    //Selection
    /*for(int i = 0; i < sizePopulation; ++i)
    {
        pop[i][7] = Utils::getRandValue(0.01, 3.0);
    }
    
    double* indiv = genetic->selectPopulation(pop, sizePopulation);

    cout << "Score : " << indiv[7] << endl;
    */
    //Croisement/Mutation
    int indexMutation = Utils::getRandValue(0.0, 7.0);
    genetic->crossPopulation(pop, sizePopulation, &indexMutation);
    genetic->evaluatePopulation(pop,sizePopulation);
    showPopulation(pop,sizePopulation,2);

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
        test[i] = new double[8];
        
        // hauteur butée
        test[i][0] = Utils::getRandValue(0.0, 90.0);
        // longueur du bras
        test[i][1] = Utils::getRandValue(1.0, 100.0);
        // masse du bras
        test[i][2] = Utils::getRandValue(1.0, 100.0);
        // longueur de la base
        test[i][3] = Utils::getRandValue(1.0, 100.0);
        // masse du contrepoids
        test[i][4] = Utils::getRandValue(1.0, 100.0);
        // masse du projectile
        test[i][5] = Utils::getRandValue(1.0, 100.0);
        // angle de la force
        test[i][6] = Utils::getRandValue(1.0, 90.0);
        // Le score
        test[i][7] = 0;
    }

    return test;
}

/**
 * Pour faire un affichage de la population
 *
 */ 
void showPopulation(double** pop, int size, int generation){

    cout<< " Generation : " << generation <<endl;
    cout<< " ================================== "<<endl;

    for(int i = 0; i < size; i++)
    {
        
        cout<< " Alpha : "<< pop[i][0] << "°" <<endl; 
        cout<< " Lb : "   << pop[i][1] << " m"   <<endl; 
        cout<< " Mb : "   << pop[i][2] << " kg"  <<endl; 
        cout<< " Lr : "   << pop[i][3] << " m"   <<endl; 
        cout<< " Mc : "   << pop[i][4] << " kg"  <<endl; 
        cout<< " Mp : "   << pop[i][5] << " m" <<endl;
        cout<< " Beta : " << pop[i][6] << "°" <<endl;
        cout<< " Score : " << pop[i][7] <<endl;
        cout<<endl;
    }

}
