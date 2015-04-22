#include "utils.h"

using namespace std;

double Utils::calculateForceTraction(double mc, double g, double beta, double mp, double alpha) {
    return (mc * g) * sin(deg2rad(beta)) - (mp * g) * cos(deg2rad(alpha));
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

double Utils::calculatePortee() {
    return 0.0;
}

double Utils::calculateEnergieImpact() {
    return 0.0;
}

double Utils::calculateViabilite() {
    return 0.0;
}

double Utils::deg2rad(double deg) {
    return deg*(180/M_PI);
}
