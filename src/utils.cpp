#include "utils.h"

using namespace std;


bool   Utils::calcViability(){
    return 0;
}

double Utils::calcPortee(){
    return 0;
}

double Utils::calcEnergy(){
    return 0;
}

double Utils::calcVelocity(double* genes){

    /*
    0 La hauteur du la butée en ° , alpha
    1 La longueur du bras en m Lb
    2 La masse du bras en kg mb
    3 Longueur de la base en m Lr
    4 La masse du contre poids en kg mc
    5 La masse du projectile en kg mp
    6 L'angle de la force de traction en ° beta
    */    
    
    double momentInertie = calculateInertieBras(genes[2], genes[1]);

    double forceTraction = calculateForceTraction(genes[4], gravity, genes[6], genes[5], genes[0]);
    double momentBras = calculateMomentBras(forceTraction, genes[1]);
    
    double acc = calculateAcceleration(momentBras, momentInertie);
    
    return calculateVelocite(acc, genes[1]);
}

double Utils::calculateForceTraction(double masseContrePoids, double gravite, double beta, double masseProjectile, double alpha) {
    return (masseContrePoids * gravite) * sin(deg2rad(beta)) - (masseProjectile * gravite) * cos(deg2rad(alpha));
}

double Utils::calculateMomentBras(double forceTraction, double longueurBras) {
    return forceTraction * longueurBras;
}

double Utils::calculateInertieBras(double masseBras, double longueurBras) {
    double numerateur = masseBras * pow(longueurBras, 2);

    return numerateur / 3;
}

double Utils::calculateAcceleration(double momentBras, double momentInertie) {
    return momentBras / momentInertie;
}

double Utils::calculateVelocite(double acceleration, double longueurBras) {
    return acceleration * longueurBras;
}

double Utils::calculatePortee(double velocite, double gravite, double alpha) {
    double div = pow(velocite, 2) / gravite;

    return div * sin(2 * (90 - alpha));
}

double Utils::calculateEnergieImpact(double masseProjectile, double velocite) {
    return 1 / 2 * masseProjectile * pow(velocite, 2);
}

bool Utils::calculateViabilite(double alpha, double gravite, double longueurBras, double longueurBase, double masseProjectile, double masseContrePoids) {
    double calc111 = pow(sin(alpha) * longueurBras, 2);
    double calc112 = pow(cos(alpha) * longueurBras - longueurBase, 2);
    double calc110 = calc111 + calc112;
    double calc120 = sin(alpha) * (masseProjectile * gravite);
    double calc100 = calc110 * calc120;
    double calc200 = longueurBase * (masseContrePoids * gravite);

    return calc100 <= calc200;
}

double Utils::deg2rad(double deg) {
    return deg*(180/M_PI);
}
