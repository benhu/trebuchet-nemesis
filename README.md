Trebuchet
=

<p align="center">
![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/minions.jpg?token=AGIcXMh7GY1PXtyYJcB7W9YVIOyKCRC8ks5VZ4l3wA%3D%3D)  
</p>

# I.    Introduction

Le but de ce TP est d'appliquer les algorithmes de metaheuristique pour créer le meilleur trebuchet possible dans les limites du "réalisable".
L'idée est de faire en sorte que le trebuchet puisse atteindre un objet à une certaine distance. Pour cela nous devons trouver les caractéristiques nécessaires à la réalisation de l'objectif.

Nous souhaitons optimiser plusieurs paramètres du trebuchet. Ce type d'optimisation ne peut pas être fait en temps linéaire du fait de sa complexité. Nous allons donc utitiliser les algorithmes génétiques pour nous permettre de converger plus rapidement vers un résultat.

# II.   L'algorithme

<p align="center">
![alt tag]( https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/schemaAlgo.png?token=AGIcXAn1Li3cgsbfuydXL6dznOVtZKUlks5VZ419wA%3D%3D )
</p>


Selection
---------
La selection s'effectue de manière aléatoire et est pondérée avec la somme des scores des fonctions d'évaluations.

Croisement
----------
Le croisement s'effectue sur un gène défini aleatoirement au début de génération, les deux gènes se croisent et forme deux nouveaux gènes, la proba que le gène change est de 50%. 

Mutation
--------
La mutation s'effectue sur un gène définis aléatoirement et la probabilité de mutation est de 1%



# III.   Element de l'algorithme
- Population
    - Ens de trebuchet
- Individu
    - Un trebuchet
- Gènes
    - La hauteur du la butée en °
    - La longueur du bras en m
    - La masse du bras en kg
    - Longueur de la base en m
    - La masse du contre poids en kg
    - La masse du projectile en kg
    - L'angle de la force de traction en °
- Variables
    -Nb Generation
    -Nb Population
    - La gravité en m.s^-2

# IV.  Structure de données

Gènes : double[]
Découpage de 0 à 6

To keep it in mind
- 0 La hauteur du la butée en ° , alpha
- 1 La longueur du bras en m Lb
- 2 La masse du bras en kg mb
- 3 Longueur de la base en m Lr
- 4 La masse du contre poids en kg mc
- 5 La masse du projectile en kg mp
- 6 L'angle de la force de traction en ° beta

Nous avons aussi le score en position 7.

# V.   Variations des gènes
- Hauteur de la butée en °
    - de 30° à 90°
- Longueur du bras
    - de 0 à bcp
- Masse du bras
    - de 0 à bcp

# VI.    Evaluation
- De la portée
    - Fonction gaussienne
- De l'énergie de l'impact
- De la viabilité
