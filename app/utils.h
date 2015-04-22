#ifndef UTILS_H
#define UTILS_H

#include <math.h>

class Utils {
public:
    double calculateForceTraction(double masseContrePoids, double gravite, double beta, double masseProjectile, double alpha);
    double calculateMomentBras(double forceTraction, double longueurBras);
    double calculateInertieBras(double masseBras, double longueurBras);
    double calculateAcceleration(double momentBras, double momentInertie);
    double calculateVelocite(double acceleration, double longueurBras);
    double calculatePortee(double velocite, double gravite, double alpha);
    double calculateEnergieImpact(double masseProjectile, double velocite);
    bool calculateViabilite(double alpha, double longueurBras, double longueurBase, double masseProjectile, double masseContrePoids);
private:
    double deg2rad(double deg);
};
#endif // UTILS
