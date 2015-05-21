#include "utils.h"

using namespace std;



/*
To keep it in mind
    0 La hauteur du la butée en ° , alpha
    1 La longueur du bras en m Lb
    2 La masse du bras en kg mb
    3 Longueur de la base en m Lr
    4 La masse du contre poids en kg mc
    5 La masse du projectile en kg mp
    6 L'angle de la force de traction en ° beta
*/    

/**
 * Fonction qui retourne si un individu est viable
 * @param genes les genes de l'individu
 * @return bool si l'element est viable
 */
bool   Utils::calcViability(double* genes){

    return calculateViabilite(genes[0], gravity, genes[1], genes[3], genes[5], genes[4]);
}


/**
 * Fonction qui retourne la portee du lancement
 * @param genes les genes de l'individu
 * @return double la portee en m
 */
double Utils::calcPortee(double* genes){

    double velocity = calcVelocity(genes);
    return calculatePortee(velocity, gravity, genes[0]);
}

/**
 * Fonction qui retourne le score pour la distance (Fct Gaussienne)
 * @param genes Les genes de l'individu
 * @return double Le score
 */
double Utils::evalPortee(double* genes){
    double x = calcPortee(genes);
    return exp(-pow((x-300),2)/10000);
}

/**
 * Fonction qui retourne l'energie du lancement
 * @param genes les genes de l'individu
 * @return double l'energie en J
 */
double Utils::calcEnergy(double* genes){ 

    double velocity = calcVelocity(genes);
    return calculateEnergieImpact(genes[5], velocity);
}


/**
 * Fonction qui retourne la vitesse du projectile
 * @param genes les genes de l'individu
 * @return double la vitesse en m.s-1
 */
double Utils::calcVelocity(double* genes){

    
    double momentInertie = calculateInertieBras(genes[2], genes[1]);

    double forceTraction = calculateForceTraction(genes[4], gravity, genes[6], genes[5], genes[0]);
    double momentBras = calculateMomentBras(forceTraction, genes[1]);
    
    double acc = calculateAcceleration(momentBras, momentInertie);
    
    return calculateVelocite(acc, genes[1]);
}

/*
 * La force de traction
 */
double Utils::calculateForceTraction(double masseContrePoids, double gravite, double beta, double masseProjectile, double alpha) {
    return (masseContrePoids * gravite) * sin(deg2rad(beta)) - (masseProjectile * gravite) * cos(deg2rad(alpha));
}

/**
 * Le moment du bras
 */
double Utils::calculateMomentBras(double forceTraction, double longueurBras) {
    return forceTraction * longueurBras;
}

/**
 * L'inertie du bras
 */
double Utils::calculateInertieBras(double masseBras, double longueurBras) {
    double numerateur = masseBras * pow(longueurBras, 2);

    return numerateur / 3;
}

/**
 * L'acceleration du projectile
 */
double Utils::calculateAcceleration(double momentBras, double momentInertie) {
    return momentBras / momentInertie;
}

/**
 * La velocite du projectile
 */
double Utils::calculateVelocite(double acceleration, double longueurBras) {
    return acceleration * longueurBras;
}

/*
 * Calcul de portee.
 */
double Utils::calculatePortee(double velocite, double gravite, double alpha) {
    double div = pow(velocite, 2) / gravite;

    return div * sin(2 * (90 - alpha));
}

/**
 * Calcul de l'energie d'impact
 */
double Utils::calculateEnergieImpact(double masseProjectile, double velocite) {
    return 1 / 2 * masseProjectile * pow(velocite, 2);
}

/*
 * Calcul de viabilite
 */
bool Utils::calculateViabilite(double alpha, double gravite, double longueurBras, double longueurBase, double masseProjectile, double masseContrePoids) {
    double calc111 = pow(sin(alpha) * longueurBras, 2);
    double calc112 = pow(cos(alpha) * longueurBras - longueurBase, 2);
    double calc110 = calc111 + calc112;
    double calc120 = sin(alpha) * (masseProjectile * gravite);
    double calc100 = calc110 * calc120;
    double calc200 = longueurBase * (masseContrePoids * gravite);

    return calc100 <= calc200;
}

/*
* Retourne degre en radian
*/
double Utils::deg2rad(double deg) {
    return deg*(180/M_PI);
}
