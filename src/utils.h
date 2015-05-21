#ifndef UTILS_H
#define UTILS_H

#include <math.h>

class Utils {
    
public:
	static bool   calcViability(double* genes);
	static double calcPortee(double* genes);
    static double calcEnergy(double* genes);
	static double calcVelocity(double* genes);
    
    static double evalPortee(double* genes);
    static double evalViability(double* genes);
    static double evalPower(double* genes);
    

private:
    static double constexpr gravity = 9.81;

    static double deg2rad(double deg);

    static double calculateForceTraction(double masseContrePoids, double gravite, double beta, double masseProjectile, double alpha);
    static double calculateMomentBras(double forceTraction, double longueurBras);
    static double calculateInertieBras(double masseBras, double longueurBras);
    static double calculateAcceleration(double momentBras, double momentInertie);
    static double calculateVelocite(double acceleration, double longueurBras);
    static double calculatePortee(double velocite, double gravite, double alpha);
    static double calculateEnergieImpact(double masseProjectile, double velocite);
    static bool   calculateViabilite(double alpha, double gravite, double longueurBras, double longueurBase, double masseProjectile, double masseContrePoids);

};
#endif // UTILS
