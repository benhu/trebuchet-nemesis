Trebuchet
========

![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/minions.jpg?token=AGIcXMh7GY1PXtyYJcB7W9YVIOyKCRC8ks5VZ4l3wA%3D%3D)

# I.    Introduction

Le but de ce TP est d'appliquer les algorithmes de metaheuristique pour créer le meilleur trebuchet possible dans les limites du "réalisable".
L'idée est de faire en sorte que le trebuchet puisse atteindre un objet à une certaine distance. Pour cela nous devons trouver les caractéristiques nécessaires à la réalisation de l'objectif.

Nous souhaitons optimiser plusieurs paramètres du trebuchet. Ce type d'optimisation ne peut pas être fait en temps linéaire du fait de sa complexité. Nous allons donc utitiliser les algorithmes génétiques pour nous permettre de converger plus rapidement vers un résultat.

# II.   L'algorithme

![alt tag]( https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/schemaAlgo.png?token=AGIcXAn1Li3cgsbfuydXL6dznOVtZKUlks5VZ419wA%3D%3D )


L'Evaluation
-------------
Pour évaluer l'impact de nos évolutions, il nous mesurer nos différentes générations. Cette évaluation retrounera un score relatif à l'adapatation du trebuchet.
Cette mesure est faite avec une fonction d'évaluation qui se base sur trois élément:
Le plus important, la viabilité qui va nous dire si oui ou non notre catapulte est réalisable.
Nous avons donc décider d'attribuer un score de 0.001 à un élément non viable, pour ne pas l'exclure et 1 pour un élément viable.

Le second indicateur, se base sur la portée, il est plus qu'important que les minions atteignent leur cible. Nous avons donc décider d'attribuer un score en fonction de la distance l'écartant de sa cible.
Le score devra être plus important en étant dans la zone autour de la cible. Pour reproduire cela nous utilisons une fonction gaussienne hyperbolique. Le but étant qu'il y ait une forte pente dés qu'on s'écarte trop de la cible.

![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/funcPortee.png?token=AGIcXOgJmfwAXsN5PQzfIARCEZN3E0PAks5VZ5YAwA%3D%3D )

Pour finir si nous sommes suffisament proche, de l'objet nous considérons la force de l'impact.  Plus la force de l'impact est grand plus on doit considérerla force. Cependant cette élément peut être un facteur à forte divergence, il ne faut donc pas le prendre en compte si l'on est pas proche de l'élément.

![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/funcPower.png?token=AGIcXHHX6dhUa-KbgX4CXKrF30Je6A2Lks5VZ5YfwA%3D%3D) 

Selection
---------
La selection est une méthode qui permet de récupérer n/2 couples. Chaque individu sera sélectionné selon son score personnel obtenu lors de l'évaluation.
Les individus ainsi rangé ont plus ou moins de chance d'être selectionné.


![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/minionOrder.jpg?token=AGIcXGhMwJM-Ubd-Lgsnfu-ry1epJyeJks5VZ5mFwA%3D%3D)

Elle s'effectue de manière aléatoire et est pondérée avec la somme des scores des fonctions d'évaluations.
Nous récupérons donc la somme des scores de notre population. Avec celle ci nous créons un random entre 0 et la somme des scores, qui représente l'individu qui sera choisi. On parcourt notre tableau en comparant les scores au randement.



Croisement
----------
Le croisement s'effectue sur un gène défini aléatoirement au début de la génération, cette génération est bornée entre le deuxième gène et le dernier. Les deux gènes se croisent et en formes deux nouveaux, la probabilité que le gène change est de 80%. Afin de respecter les 80%, on génère un nombre entre 0 et 100, si le nombre est inférieur à 80 alors on change la valeur de l'index par une valeur aléatoire. Cela permet d'une convergence plus rapide vers une catapulte de meilleures qualités.

Mutation
--------
La mutation à une chance de se produire de 1%, pour cela nous utilisons la même technique que pour le croisement, on génère un nombre entre 0 et 100, si le nombre est inférieur ou égale a 1, alors on change un gène de l'individu avec une valeur aléatoire.


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

Structure de données
--------------------
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

Variations des gènes
--------------------
- Hauteur de la butée en °
    - de 0° à 100°
- Longueur du bras
    - de 0 à 100 m
- Masse du bras
    - de 0 à 100 m

#Test



# Conclusion

Nous pouvons constater qu'au fil des générations la variance diminue, par analogie nous pouvons donc affirmer que nous convergeons vers une catapulte qui produit beaucoup de dégâts et qui vise dans le mille.
