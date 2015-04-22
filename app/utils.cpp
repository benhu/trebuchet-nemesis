#include "utils.h"

using namespace std;

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

bool Utils::calculateViabilite(double alpha, double longueurBras, double longueurBase, double masseProjectile, double masseContrePoids) {
    double calc111 = pow(sin(alpha) * longueurBras, 2);
    double calc112 = pow(cos(alpha) * longueurBras - longueurBase, 2);
    double calc110 = calc101 + calc102;
    double calc120 = sin(alpha) * (masseProjectile * gravite);
    double calc100 = calc110 * calc120;
    double calc200 = longueurBase * (masseContrePoids * gravite);

    return calc100 <= calc200;
}

double Utils::deg2rad(double deg) {
    return deg*(180/M_PI);
}
