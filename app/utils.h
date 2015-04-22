#ifndef UTILS_H
#define UTILS_H

#include <math.h>

class Utils {
public:
    double calculateForceTraction(double mc, double g, double beta, double mp, double alpha);
    double calculateMomentBras(double forceTraction, double longueurBras);
    double calculateInertieBras(double masseBras, double longueurBras);
    double calculateAcceleration(double momentBras, double momentInertie);
    double calculateVelocite();
    double calculatePortee();
    double calculateEnergieImpact();
    double calculateViabilite();
private:
    double deg2rad(double deg);
};
#endif // UTILS
