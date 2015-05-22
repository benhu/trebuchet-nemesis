Trebuchet
========

![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/minions.jpg?token=AGIcXMh7GY1PXtyYJcB7W9YVIOyKCRC8ks5VZ4l3wA%3D%3D)

#I. Introduction

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
Résultat avec une population de 100, 500 générations et un pourcentage de mutation de 50 %
```
Meilleur élément Generation : 0
==================== 
Alpha : 89.0633°
Lb : 75.1406 m
Mb : 35.4412 kg
Lr : 99.0082 m
Mc : 69.3095 kg
Mp : 34.847 m
Beta : 54.4652°
Score : 2.43805

Meilleur élément Generation : 499
==================== 
Alpha : 60.6955°
Lb : 90.0584 m
Mb : 9.40355 kg
Lr : 55.9432 m
Mc : 63.2467 kg
Mp : 90.4372 m
Beta : 81.588°
Score : 2.99765

Variances : (generation, variances) 
=========== 
(0,0);(1,0.166382);(2,0.0407042);(3,0.0992455);(4,0.0909148);(5,0.116275);(6,0.116979);(7,0.0866896);(8,0.154879);(9,0.0549748);(10,0.0366465);(11,0.0745531);(12,0.114242);(13,0.0100412);(14,0.067699);(15,0.0236067);(16,0.125401);(17,0.0797938);(18,0.0512288);(19,0.0320391);(20,0.0360675);(21,0.0642963);(22,0.023034);(23,0.0529893);(24,0.0388356);(25,0.0301485);(26,0.0150357);(27,0.024462);(28,0.0231177);(29,0.0279412);(30,0.0617112);(31,0.0505843);(32,0.0478131);(33,0.0417703);(34,0.0447825);(35,0.0572647);(36,0.0622517);(37,0.087379);(38,0.0823038);(39,0.0587031);(40,0.0664253);(41,0.0779265);(42,0.0680369);(43,0.0748332);(44,0.0620584);(45,0.0657146);(46,0.0581467);(47,0.0388135);(48,0.0439265);(49,0.044887);(50,0.0911586);(51,0.0905531);(52,0.0993645);(53,0.0926929);(54,0.109927);(55,0.108455);(56,0.10833);(57,0.114502);(58,0.0994077);(59,0.0925082);(60,0.16);(61,0.0949852);(62,0.0973392);(63,0.0552085);(64,0.0999996);(65,0.124666);(66,0.140221);(67,0.150483);(68,0.161554);(69,0.155676);(70,0.156005);(71,0.150101);(72,0.153433);(73,0.129647);(74,0.138321);(75,0.144159);(76,0.151814);(77,0.140786);(78,0.148175);(79,0.141879);(80,0.133091);(81,0.13098);(82,0.13049);(83,0.120313);(84,0.162848);(85,0.138604);(86,0.130467);(87,0.127714);(88,0.101218);(89,0.107832);(90,0.155143);(91,0.14867);(92,0.119206);(93,0.105417);(94,0.145226);(95,0.120502);(96,0.164079);(97,0.147428);(98,0.125562);(99,0.100029);(100,0.138061);(101,0.108844);(102,0.0878398);(103,0.105494);(104,0.0337164);(105,0.0388669);(106,0.0121245);(107,-1.59872e-14);(108,-1.59872e-14);(109,-1.59872e-14);(110,0.00985352);(111,-1.59872e-14);(112,0.0195077);(113,0.0195077);(114,0.0289284);(115,0.0471861);(116,0.0381565);(117,0.0289059);(118,0.00985352);(119,-1.59872e-14);(120,-1.59872e-14);(121,0.00985484);(122,-1.59872e-14);(123,-1.59872e-14);(124,0.0098451);(125,-1.59872e-14);(126,-1.59872e-14);(127,0.00984788);(128,-1.59872e-14);(129,-1.59872e-14);(130,-1.59872e-14);(131,-1.59872e-14);(132,-1.59872e-14);(133,-1.59872e-14);(134,-1.59872e-14);(135,0.00985352);(136,0.00985352);(137,0.00985352);(138,0.00985352);(139,-1.59872e-14);(140,0.00985353);(141,0.00985353);(142,0.000527642);(143,0.0103404);(144,0.0114005);(145,0.0116164);(146,0.0251576);(147,0.0395217);(148,0.0316948);(149,0.0129042);(150,0.0172344);(151,0.0302737);(152,0.0302777);(153,0.0251551);(154,0.0264839);(155,0.00629331);(156,0.00629331);(157,0.00162249);(158,0.0115952);(159,0.00985722);(160,0.00985722);(161,0.0194625);(162,0.038127);(163,0.0472346);(164,0.0289652);(165,0.0382214);(166,0.019508);(167,0.00985352);(168,0.0421037);(169,0.0329807);(170,0.019508);(171,0.00985352);(172,0.0194996);(173,0.0382129);(174,0.0472686);(175,0.0472702);(176,0.0382146);(177,0.0561269);(178,0.0382146);(179,0.0289582);(180,0.0195019);(181,0.0195045);(182,0.0212971);(183,0.0306618);(184,0.0141239);(185,0.0195062);(186,-1.59872e-14);(187,0.00178911);(188,-1.59872e-14);(189,0.0186693);(190,0.0291005);(191,0.00125319);(192,0.0121901);(193,-1.59872e-14);(194,0.0195034);(195,0.0195034);(196,0.019508);(197,0.0472769);(198,0.0561304);(199,0.019508);(200,0.019508);(201,0.00985352);(202,0.0287204);(203,0.0643299);(204,0.0648039);(205,0.0195118);(206,0.0289686);(207,0.0289657);(208,0.038222);(209,0.0382266);(210,0.0098559);(211,0.00367159);(212,-1.59872e-14);(213,-1.59872e-14);(214,0.00985757);(215,0.00985828);(216,-1.59872e-14);(217,0.0098535);(218,0.00985546);(219,0.0195064);(220,-1.59872e-14);(221,-1.59872e-14);(222,0.0195073);(223,0.0289233);(224,0.00985281);(225,-1.59872e-14);(226,-1.59872e-14);(227,-1.59872e-14);(228,0.019508);(229,0.019508);(230,0.0195084);(231,0.00985388);(232,0.0195083);(233,0.0191359);(234,0.0282265);(235,0.0191356);(236,-1.59872e-14);(237,0.00985398);(238,-1.59872e-14);(239,-1.59872e-14);(240,-1.59872e-14);(241,0.00369166);(242,0.00369166);(243,0.00985071);(244,-1.59872e-14);(245,0.00985351);(246,-1.59872e-14);(247,-1.59872e-14);(248,-1.59872e-14);(249,-1.59872e-14);(250,-1.59872e-14);(251,-1.59872e-14);(252,0.001922);(253,0.0145949);(254,0.0217935);(255,0.0211739);(256,0.0217245);(257,0.0316786);(258,0.0401511);(259,0.0401511);(260,0.0382197);(261,0.0289634);(262,0.019508);(263,0.0289634);(264,0.0560236);(265,0.0732469);(266,0.0732388);(267,0.0600574);(268,0.0333007);(269,0.0239917);(270,0.0098453);(271,-1.59872e-14);(272,0.0098516);(273,0.0098516);(274,-1.59872e-14);(275,-1.59872e-14);(276,-1.59872e-14);(277,0.00985139);(278,0.0195038);(279,0.0195038);(280,0.00985139);(281,0.00985139);(282,0.00985139);(283,0.0195059);(284,0.00985983);(285,0.00810076);(286,0.00810076);(287,0.00810076);(288,-1.59872e-14);(289,0.00679109);(290,0.00679109);(291,0.00679109);(292,0.00679109);(293,0.00679109);(294,0.00981177);(295,0.00981177);(296,0.00981177);(297,0.00981177);(298,0.0194253);(299,0.0193405);(300,0.0378917);(301,0.0379747);(302,0.0287567);(303,0.00981177);(304,-1.59872e-14);(305,-1.59872e-14);(306,0.00984864);(307,0.00985368);(308,0.00983347);(309,-1.59872e-14);(310,-1.59872e-14);(311,0.00984762);(312,0.0098535);(313,0.0098535);(314,0.010584);(315,0.000798049);(316,0.00985612);(317,-1.59872e-14);(318,0.00985352);(319,-1.59872e-14);(320,-1.59872e-14);(321,-1.59872e-14);(322,0.00984116);(323,0.0188272);(324,0.0135268);(325,0.00886617);(326,0.0237193);(327,0.0195094);(328,0.0648012);(329,0.0647985);(330,0.0382204);(331,0.0289634);(332,0.00985307);(333,1.78367e-07);(334,3.45701e-07);(335,2.35371e-07);(336,2.35371e-07);(337,2.91149e-07);(338,3.45701e-07);(339,0.00985308);(340,1.20137e-07);(341,-1.59872e-14);(342,0.00985486);(343,0.00985817);(344,-1.59872e-14);(345,-1.59872e-14);(346,-1.59872e-14);(347,0.00985355);(348,-1.59872e-14);(349,-1.59872e-14);(350,-1.59872e-14);(351,-1.59872e-14);(352,-1.59872e-14);(353,0.00983809);(354,0.0098597);(355,0.00985367);(356,-1.59872e-14);(357,-1.59872e-14);(358,-1.59872e-14);(359,0.0129947);(360,0.00985351);(361,0.0195018);(362,0.0195079);(363,0.0164215);(364,0.00985351);(365,-1.59872e-14);(366,-1.59872e-14);(367,-1.59872e-14);(368,0.00985079);(369,0.0195091);(370,0.0195025);(371,0.00985068);(372,0.0472716);(373,0.0289578);(374,0.0289449);(375,0.0289449);(376,0.00981621);(377,0.0194341);(378,-1.59872e-14);(379,-1.59872e-14);(380,-1.59872e-14);(381,-1.59872e-14);(382,-1.59872e-14);(383,0.00985352);(384,0.0472665);(385,0.0472704);(386,0.0289752);(387,0.0288293);(388,0.0289713);(389,0.00985756);(390,-1.59872e-14);(391,-1.59872e-14);(392,0.0171492);(393,0.00985892);(394,0.0195088);(395,0.00985438);(396,0.00985438);(397,0.0195173);(398,-1.59872e-14);(399,-1.59872e-14);(400,-1.59872e-14);(401,0.00984442);(402,-1.59872e-14);(403,0.00985352);(404,-1.59872e-14);(405,-1.59872e-14);(406,0.0098535);(407,0.0220702);(408,0.0195081);(409,0.0191255);(410,0.0191255);(411,0.0289498);(412,0.0472638);(413,0.0382201);(414,0.0289636);(415,0.0647895);(416,0.0472668);(417,0.0289476);(418,0.0289581);(419,0.0289496);(420,0.0467756);(421,0.0584171);(422,0.0271437);(423,0.0472643);(424,0.0472614);(425,-1.59872e-14);(426,0.0121185);(427,0.0143339);(428,0.0195084);(429,0.0195084);(430,1.68193e-05);(431,0.00835424);(432,0.00835521);(433,0.0180078);(434,0.00988598);(435,0.0375897);(436,0.0289104);(437,0.0288931);(438,0.0644933);(439,0.0558172);(440,0.0379804);(441,0.0436563);(442,0.0558396);(443,0.0725799);(444,0.0468795);(445,0.0379045);(446,0.037813);(447,0.0287468);(448,0.00996086);(449,0.00978311);(450,0.00978295);(451,0.000363399);(452,0.000291535);(453,0.00996647);(454,0.0194231);(455,0.0194305);(456,0.00996575);(457,0.000326872);(458,0.000318548);(459,0.00996524);(460,0.000300879);(461,0.00184807);(462,0.00330619);(463,0.00474211);(464,0.0061616);(465,0.0206892);(466,0.0400775);(467,0.0311312);(468,0.0127739);(469,0.00759483);(470,0.00758421);(471,0.00822501);(472,0.0147417);(473,0.00319638);(474,0.0016546);(475,0.00168903);(476,0.000192148);(477,0.000139142);(478,0.0099082);(479,8.06987e-05);(480,9.58191e-05);(481,9.58191e-05);(482,0.00989137);(483,0.00989137);(484,0.0098838);(485,1.68193e-05);(486,6.52386e-05);(487,0.00987865);(488,0.00834321);(489,0.00833396);(490,0.00985418);(491,0.0190122);(492,0.0284727);(493,-1.59872e-14);(494,5.4357e-06);(495,0.0195011);(496,0.0237526);(497,5.4357e-06);(498,0.00984873);(499,0.0195013);
```


# Conclusion

Nous pouvons constater qu'au fil des générations la variance diminue, par analogie nous pouvons donc affirmer que nous convergeons vers une catapulte qui produit beaucoup de dégâts et qui vise dans le mille.
