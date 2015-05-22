Trebuchet
========

![alt tag](https://raw.githubusercontent.com/benhu/trebuchet-nemesis/master/asset/minions.jpg?token=AGIcXMh7GY1PXtyYJcB7W9YVIOyKCRC8ks5VZ4l3wA%3D%3D)

#I. Introduction

Le but de ce TP est d'appliquer les algorithmes de metaheuristique pour créer le meilleur trebuchet possible dans les limites du "réalisable".
L'idée est de faire en sorte que le trebuchet puisse atteindre un objet à une certaine distance. Pour cela nous devons trouver les caractéristiques nécessaires à la réalisation de l'objectif.

Nous souhaitons optimiser plusieurs paramètres du trebuchet. Ce type d'optimisation ne peut pas être fait en temps linéaire du fait de sa complexité. Nous allons donc utitiliser les algorithmes génétiques pour nous permettre de converger plus rapidement vers un résultat.

Comment compiler :
------------------
Le projet est écrit en C++ et est accompagné d'un makefile.
Ils suffit donc d'utiliser la commande :
```
>make
>./main
```

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
## Résultat avec une population de 100, 500 générations et un pourcentage de mutation de 50 %
### Meilleur élément Generation : 0

- Alpha : 89.0633°
- Lb : 75.1406 m
- Mb : 35.4412 kg
- Lr : 99.0082 m
- Mc : 69.3095 kg
- Mp : 34.847 m
- Beta : 54.4652°
- Score : 2.43805

### Meilleur élément Generation : 499

- Alpha : 60.6955°
- Lb : 90.0584 m
- Mb : 9.40355 kg
- Lr : 55.9432 m
- Mc : 63.2467 kg
- Mp : 90.4372 m
- Beta : 81.588°
- Score : 2.99765

### Variances : (generation, variances) 
(0,0);(1,0.166382);(2,0.0407042);(3,0.0992455);(4,0.0909148);(5,0.116275);(6,0.116979);(7,0.0866896);(8,0.154879);(9,0.0549748);(10,0.0366465);(11,0.0745531);(12,0.114242);(13,0.0100412);(14,0.067699);(15,0.0236067);(16,0.125401);(17,0.0797938);(18,0.0512288);(19,0.0320391);(20,0.0360675);(21,0.0642963);(22,0.023034);(23,0.0529893);(24,0.0388356);(25,0.0301485);(26,0.0150357);(27,0.024462);(28,0.0231177);(29,0.0279412);(30,0.0617112);(31,0.0505843);(32,0.0478131);(33,0.0417703);(34,0.0447825);(35,0.0572647);(36,0.0622517);(37,0.087379);(38,0.0823038);(39,0.0587031);(40,0.0664253);(41,0.0779265);(42,0.0680369);(43,0.0748332);(44,0.0620584);(45,0.0657146);(46,0.0581467);(47,0.0388135);(48,0.0439265);(49,0.044887);(50,0.0911586);(51,0.0905531);(52,0.0993645);(53,0.0926929);(54,0.109927);(55,0.108455);(56,0.10833);(57,0.114502);(58,0.0994077);(59,0.0925082);(60,0.16);(61,0.0949852);(62,0.0973392);(63,0.0552085);(64,0.0999996);(65,0.124666);(66,0.140221);(67,0.150483);(68,0.161554);(69,0.155676);(70,0.156005);(71,0.150101);(72,0.153433);(73,0.129647);(74,0.138321);(75,0.144159);(76,0.151814);(77,0.140786);(78,0.148175);(79,0.141879);(80,0.133091);(81,0.13098);(82,0.13049);(83,0.120313);(84,0.162848);(85,0.138604);(86,0.130467);(87,0.127714);(88,0.101218);(89,0.107832);(90,0.155143);(91,0.14867);(92,0.119206);(93,0.105417);(94,0.145226);(95,0.120502);(96,0.164079);(97,0.147428);(98,0.125562);(99,0.100029);(100,0.138061);(101,0.108844);(102,0.0878398);(103,0.105494);(104,0.0337164);(105,0.0388669);(106,0.0121245);(107,-1.59872e-14);(108,-1.59872e-14);(109,-1.59872e-14);(110,0.00985352);(111,-1.59872e-14);(112,0.0195077);(113,0.0195077);(114,0.0289284);(115,0.0471861);(116,0.0381565);(117,0.0289059);(118,0.00985352);(119,-1.59872e-14);(120,-1.59872e-14);(121,0.00985484);(122,-1.59872e-14);(123,-1.59872e-14);(124,0.0098451);(125,-1.59872e-14);(126,-1.59872e-14);(127,0.00984788);(128,-1.59872e-14);(129,-1.59872e-14);(130,-1.59872e-14);(131,-1.59872e-14);(132,-1.59872e-14);(133,-1.59872e-14);(134,-1.59872e-14);(135,0.00985352);(136,0.00985352);(137,0.00985352);(138,0.00985352);(139,-1.59872e-14);(140,0.00985353);(141,0.00985353);(142,0.000527642);(143,0.0103404);(144,0.0114005);(145,0.0116164);(146,0.0251576);(147,0.0395217);(148,0.0316948);(149,0.0129042);(150,0.0172344);(151,0.0302737);(152,0.0302777);(153,0.0251551);(154,0.0264839);(155,0.00629331);(156,0.00629331);(157,0.00162249);(158,0.0115952);(159,0.00985722);(160,0.00985722);(161,0.0194625);(162,0.038127);(163,0.0472346);(164,0.0289652);(165,0.0382214);(166,0.019508);(167,0.00985352);(168,0.0421037);(169,0.0329807);(170,0.019508);(171,0.00985352);(172,0.0194996);(173,0.0382129);(174,0.0472686);(175,0.0472702);(176,0.0382146);(177,0.0561269);(178,0.0382146);(179,0.0289582);(180,0.0195019);(181,0.0195045);(182,0.0212971);(183,0.0306618);(184,0.0141239);(185,0.0195062);(186,-1.59872e-14);(187,0.00178911);(188,-1.59872e-14);(189,0.0186693);(190,0.0291005);(191,0.00125319);(192,0.0121901);(193,-1.59872e-14);(194,0.0195034);(195,0.0195034);(196,0.019508);(197,0.0472769);(198,0.0561304);(199,0.019508);(200,0.019508);(201,0.00985352);(202,0.0287204);(203,0.0643299);(204,0.0648039);(205,0.0195118);(206,0.0289686);(207,0.0289657);(208,0.038222);(209,0.0382266);(210,0.0098559);(211,0.00367159);(212,-1.59872e-14);(213,-1.59872e-14);(214,0.00985757);(215,0.00985828);(216,-1.59872e-14);(217,0.0098535);(218,0.00985546);(219,0.0195064);(220,-1.59872e-14);(221,-1.59872e-14);(222,0.0195073);(223,0.0289233);(224,0.00985281);(225,-1.59872e-14);(226,-1.59872e-14);(227,-1.59872e-14);(228,0.019508);(229,0.019508);(230,0.0195084);(231,0.00985388);(232,0.0195083);(233,0.0191359);(234,0.0282265);(235,0.0191356);(236,-1.59872e-14);(237,0.00985398);(238,-1.59872e-14);(239,-1.59872e-14);(240,-1.59872e-14);(241,0.00369166);(242,0.00369166);(243,0.00985071);(244,-1.59872e-14);(245,0.00985351);(246,-1.59872e-14);(247,-1.59872e-14);(248,-1.59872e-14);(249,-1.59872e-14);(250,-1.59872e-14);(251,-1.59872e-14);(252,0.001922);(253,0.0145949);(254,0.0217935);(255,0.0211739);(256,0.0217245);(257,0.0316786);(258,0.0401511);(259,0.0401511);(260,0.0382197);(261,0.0289634);(262,0.019508);(263,0.0289634);(264,0.0560236);(265,0.0732469);(266,0.0732388);(267,0.0600574);(268,0.0333007);(269,0.0239917);(270,0.0098453);(271,-1.59872e-14);(272,0.0098516);(273,0.0098516);(274,-1.59872e-14);(275,-1.59872e-14);(276,-1.59872e-14);(277,0.00985139);(278,0.0195038);(279,0.0195038);(280,0.00985139);(281,0.00985139);(282,0.00985139);(283,0.0195059);(284,0.00985983);(285,0.00810076);(286,0.00810076);(287,0.00810076);(288,-1.59872e-14);(289,0.00679109);(290,0.00679109);(291,0.00679109);(292,0.00679109);(293,0.00679109);(294,0.00981177);(295,0.00981177);(296,0.00981177);(297,0.00981177);(298,0.0194253);(299,0.0193405);(300,0.0378917);(301,0.0379747);(302,0.0287567);(303,0.00981177);(304,-1.59872e-14);(305,-1.59872e-14);(306,0.00984864);(307,0.00985368);(308,0.00983347);(309,-1.59872e-14);(310,-1.59872e-14);(311,0.00984762);(312,0.0098535);(313,0.0098535);(314,0.010584);(315,0.000798049);(316,0.00985612);(317,-1.59872e-14);(318,0.00985352);(319,-1.59872e-14);(320,-1.59872e-14);(321,-1.59872e-14);(322,0.00984116);(323,0.0188272);(324,0.0135268);(325,0.00886617);(326,0.0237193);(327,0.0195094);(328,0.0648012);(329,0.0647985);(330,0.0382204);(331,0.0289634);(332,0.00985307);(333,1.78367e-07);(334,3.45701e-07);(335,2.35371e-07);(336,2.35371e-07);(337,2.91149e-07);(338,3.45701e-07);(339,0.00985308);(340,1.20137e-07);(341,-1.59872e-14);(342,0.00985486);(343,0.00985817);(344,-1.59872e-14);(345,-1.59872e-14);(346,-1.59872e-14);(347,0.00985355);(348,-1.59872e-14);(349,-1.59872e-14);(350,-1.59872e-14);(351,-1.59872e-14);(352,-1.59872e-14);(353,0.00983809);(354,0.0098597);(355,0.00985367);(356,-1.59872e-14);(357,-1.59872e-14);(358,-1.59872e-14);(359,0.0129947);(360,0.00985351);(361,0.0195018);(362,0.0195079);(363,0.0164215);(364,0.00985351);(365,-1.59872e-14);(366,-1.59872e-14);(367,-1.59872e-14);(368,0.00985079);(369,0.0195091);(370,0.0195025);(371,0.00985068);(372,0.0472716);(373,0.0289578);(374,0.0289449);(375,0.0289449);(376,0.00981621);(377,0.0194341);(378,-1.59872e-14);(379,-1.59872e-14);(380,-1.59872e-14);(381,-1.59872e-14);(382,-1.59872e-14);(383,0.00985352);(384,0.0472665);(385,0.0472704);(386,0.0289752);(387,0.0288293);(388,0.0289713);(389,0.00985756);(390,-1.59872e-14);(391,-1.59872e-14);(392,0.0171492);(393,0.00985892);(394,0.0195088);(395,0.00985438);(396,0.00985438);(397,0.0195173);(398,-1.59872e-14);(399,-1.59872e-14);(400,-1.59872e-14);(401,0.00984442);(402,-1.59872e-14);(403,0.00985352);(404,-1.59872e-14);(405,-1.59872e-14);(406,0.0098535);(407,0.0220702);(408,0.0195081);(409,0.0191255);(410,0.0191255);(411,0.0289498);(412,0.0472638);(413,0.0382201);(414,0.0289636);(415,0.0647895);(416,0.0472668);(417,0.0289476);(418,0.0289581);(419,0.0289496);(420,0.0467756);(421,0.0584171);(422,0.0271437);(423,0.0472643);(424,0.0472614);(425,-1.59872e-14);(426,0.0121185);(427,0.0143339);(428,0.0195084);(429,0.0195084);(430,1.68193e-05);(431,0.00835424);(432,0.00835521);(433,0.0180078);(434,0.00988598);(435,0.0375897);(436,0.0289104);(437,0.0288931);(438,0.0644933);(439,0.0558172);(440,0.0379804);(441,0.0436563);(442,0.0558396);(443,0.0725799);(444,0.0468795);(445,0.0379045);(446,0.037813);(447,0.0287468);(448,0.00996086);(449,0.00978311);(450,0.00978295);(451,0.000363399);(452,0.000291535);(453,0.00996647);(454,0.0194231);(455,0.0194305);(456,0.00996575);(457,0.000326872);(458,0.000318548);(459,0.00996524);(460,0.000300879);(461,0.00184807);(462,0.00330619);(463,0.00474211);(464,0.0061616);(465,0.0206892);(466,0.0400775);(467,0.0311312);(468,0.0127739);(469,0.00759483);(470,0.00758421);(471,0.00822501);(472,0.0147417);(473,0.00319638);(474,0.0016546);(475,0.00168903);(476,0.000192148);(477,0.000139142);(478,0.0099082);(479,8.06987e-05);(480,9.58191e-05);(481,9.58191e-05);(482,0.00989137);(483,0.00989137);(484,0.0098838);(485,1.68193e-05);(486,6.52386e-05);(487,0.00987865);(488,0.00834321);(489,0.00833396);(490,0.00985418);(491,0.0190122);(492,0.0284727);(493,-1.59872e-14);(494,5.4357e-06);(495,0.0195011);(496,0.0237526);(497,5.4357e-06);(498,0.00984873);(499,0.0195013);

## Résultat avec une population de 100, 500 générations et un pourcentage de mutation de 80 %

### Meilleur élément Generation : 0

- Alpha : 41.5507°
- Lb : 41.0177 m
- Mb : 6.54246 kg
- Lr : 12.8632 m
- Mc : 27.4028 kg
- Mp : 46.2684 m
- Beta : 45.5862°
- Score : 2.52942

### Meilleur élément Generation : 499

- Alpha : 47.8433°
- Lb : 99.2547 m
- Mb : 14.1695 kg
- Lr : 97.3873 m
- Mc : 30.5919 kg
- Mp : 58.8288 m
- Beta : 2.5678°
- Score : 2.98648

### Variances : (generation, variances) 
(0,0);(1,0.331452);(2,0.0449292);(3,0.0118115);(4,0.128039);(5,0.0205472);(6,0.050158);(7,0.0562368);(8,0.0190081);(9,0.029603);(10,0.0513875);(11,0.0250137);(12,0.0654324);(13,0.0334623);(14,0.0394359);(15,0.0315118);(16,0.0278269);(17,0.0696992);(18,0.0143704);(19,0.0722167);(20,0.0343282);(21,0.0572384);(22,0.00515752);(23,0.00732952);(24,0.0163754);(25,0.0198603);(26,0.00727243);(27,0.00407679);(28,0.0169041);(29,0.0247709);(30,0.0256537);(31,0.0403854);(32,0.0624087);(33,0.0701218);(34,0.0458324);(35,0.0666811);(36,0.0764201);(37,0.0661086);(38,0.0554633);(39,0.0989696);(40,0.112146);(41,0.131418);(42,0.134504);(43,0.117259);(44,0.101467);(45,0.107222);(46,0.102442);(47,0.118016);(48,0.124052);(49,0.145723);(50,0.139899);(51,0.172159);(52,0.154195);(53,0.147628);(54,0.146549);(55,0.133442);(56,0.145182);(57,0.109986);(58,0.0775735);(59,0.0714982);(60,0.0670349);(61,0.0710925);(62,0.0562868);(63,0.0510977);(64,0.0483443);(65,0.0355601);(66,0.0402324);(67,0.054142);(68,0.0413308);(69,0.0209565);(70,0.0255097);(71,0.0336026);(72,0.0176686);(73,0.0128529);(74,0.00808195);(75,0.00811261);(76,0.00800572);(77,0.00769828);(78,0.0208949);(79,0.0182218);(80,0.0256124);(81,0.0329629);(82,0.0179504);(83,0.00927797);(84,0.0125608);(85,0.00681499);(86,0.0055913);(87,0.00613337);(88,0.00843421);(89,0.0223349);(90,0.0433815);(91,0.0412873);(92,0.027983);(93,0.0183062);(94,0.0202375);(95,0.0290736);(96,0.018227);(97,0.0288855);(98,0.00882287);(99,0.00492566);(100,0.0138911);(101,0.0191031);(102,0.0281052);(103,0.0454243);(104,0.0367192);(105,0.0013194);(106,0.00117994);(107,0.0105531);(108,0.0106625);(109,0.00185755);(110,0.00174748);(111,0.00919695);(112,0.00185755);(113,0.00147827);(114,0.00123107);(115,0.00150791);(116,0.00174435);(117,0.00108176);(118,0.00109935);(119,0.00101751);(120,0.00106359);(121,0.0014734);(122,0.00270856);(123,0.0023272);(124,0.000938466);(125,0.000427447);(126,0.000606317);(127,0.000687291);(128,0.00068967);(129,0.00108359);(130,0.000857511);(131,0.000772622);(132,0.00127126);(133,0.00147044);(134,0.0103877);(135,0.0105047);(136,0.0196419);(137,0.0148628);(138,0.00813628);(139,0.00105248);(140,0.00112708);(141,0.0105645);(142,0.00131479);(143,0.00130781);(144,0.0104452);(145,0.0195181);(146,0.0371031);(147,0.0284067);(148,0.0370771);(149,0.00060248);(150,0.00989648);(151,0.0097982);(152,0.019025);(153,0.000431374);(154,0.000432498);(155,0.00996121);(156,0.000166903);(157,8.09583e-05);(158,8.65862e-05);(159,0.000170014);(160,0.000144266);(161,0.00181184);(162,0.00668153);(163,0.00506379);(164,0.0160618);(165,0.0306262);(166,0.0147638);(167,0.00964125);(168,0.00964898);(169,0.0189966);(170,0.0190134);(171,0.0281766);(172,0.0189783);(173,0.00974343);(174,0.0189923);(175,0.00973005);(176,0.00971467);(177,0.0189924);(178,0.0226316);(179,0.0210512);(180,0.00804594);(181,0.00414605);(182,0.000314288);(183,0.00966803);(184,0.000282735);(185,0.000191774);(186,0.000183095);(187,0.000138224);(188,0.000113851);(189,0.00960159);(190,0.0096187);(191,8.84992e-05);(192,8.93632e-05);(193,9.15043e-05);(194,9.0152e-05);(195,8.96578e-05);(196,8.96578e-05);(197,0.00202011);(198,7.04312e-05);(199,0.00959171);(200,8.17378e-05);(201,8.75601e-05);(202,9.29692e-05);(203,0.000588427);(204,0.00957187);(205,0.0188149);(206,0.00951678);(207,0.000155423);(208,8.98336e-05);(209,8.60669e-05);(210,0.00956656);(211,8.60697e-05);(212,7.40373e-05);(213,7.22718e-05);(214,6.44587e-05);(215,7.40373e-05);(216,6.44587e-05);(217,6.65247e-05);(218,6.44587e-05);(219,7.73429e-05);(220,7.04312e-05);(221,6.65247e-05);(222,6.44587e-05);(223,0.00306267);(224,6.65247e-05);(225,0.00962352);(226,0.0192611);(227,0.00869774);(228,0.00870136);(229,0.0188426);(230,0.0188605);(231,0.019054);(232,0.0283296);(233,0.0374006);(234,0.0284161);(235,0.00981614);(236,0.0191505);(237,0.00968298);(238,1.93898e-05);(239,1.54513e-05);(240,0.0093358);(241,0.0121303);(242,1.27973e-05);(243,9.92516e-06);(244,6.83491e-06);(245,7.88923e-06);(246,1.27973e-05);(247,1.51169e-05);(248,0.00414447);(249,0.00320919);(250,0.00320077);(251,0.00313642);(252,0.00313642);(253,0.00313085);(254,0.00312843);(255,2.96066e-07);(256,4.44089e-14);(257,0.00963421);(258,1.40836e-06);(259,4.44089e-14);(260,0.00963421);(261,0.00963369);(262,0.0368939);(263,0.0301914);(264,0.0210563);(265,0.0190713);(266,4.44089e-14);(267,4.44089e-14);(268,0.00983223);(269,0.00958201);(270,0.009635);(271,2.6906e-06);(272,4.44089e-14);(273,4.44089e-14);(274,0.00963124);(275,0.0283074);(276,0.00962127);(277,0.00962127);(278,0.00962127);(279,4.44089e-14);(280,0.0094872);(281,0.0094868);(282,3.01688e-06);(283,0.00448242);(284,0.00447949);(285,0.00447949);(286,4.44089e-14);(287,4.44089e-14);(288,0.0181895);(289,0.0190697);(290,0.00963282);(291,0.00963339);(292,1.31289e-07);(293,2.21416e-07);(294,1.94925e-07);(295,6.63146e-08);(296,0.000428199);(297,2.31421e-06);(298,0.00962468);(299,0.00962131);(300,0.0281729);(301,0.00975232);(302,0.0190955);(303,0.0191178);(304,0.000161044);(305,0.000174299);(306,0.000144087);(307,0.0190747);(308,0.00970067);(309,0.000314064);(310,0.00992844);(311,0.0100211);(312,0.00068838);(313,0.00068838);(314,0.000749486);(315,0.00996517);(316,0.00995346);(317,0.000775628);(318,0.00940211);(319,0.0094637);(320,0.0178129);(321,0.0181416);(322,0.00970457);(323,0.0267303);(324,0.0184592);(325,0.0100787);(326,0.000918458);(327,0.0105118);(328,0.00152545);(329,0.0014021);(330,0.00400271);(331,0.00170652);(332,0.00157233);(333,0.00127427);(334,0.00117374);(335,0.00132641);(336,0.00109983);(337,0.00112368);(338,0.0012128);(339,0.00103234);(340,0.00122207);(341,0.00117032);(342,0.0103867);(343,0.0104761);(344,0.00121257);(345,0.00212756);(346,0.00212078);(347,0.0121885);(348,0.012227);(349,0.0221481);(350,0.0141039);(351,0.0167892);(352,0.022731);(353,0.0322115);(354,0.0507202);(355,0.0384879);(356,0.00247175);(357,0.00585547);(358,0.00095063);(359,0.000811148);(360,0.000812186);(361,0.00095063);(362,0.0101606);(363,0.019358);(364,0.0194591);(365,0.0100296);(366,0.0100802);(367,0.000355521);(368,0.000272563);(369,0.000453622);(370,0.00980743);(371,0.00972272);(372,0.0192022);(373,0.00028969);(374,0.00996863);(375,0.000727017);(376,0.000658263);(377,0.0103);(378,0.0194497);(379,0.019717);(380,0.0378445);(381,0.037592);(382,0.0191319);(383,0.0096971);(384,3.37508e-14);(385,3.90799e-14);(386,0.00962987);(387,0.00962889);(388,0.00962987);(389,3.37508e-14);(390,3.90799e-14);(391,0.00963376);(392,0.00963689);(393,0.00968214);(394,0.00011981);(395,6.0516e-05);(396,0.0097227);(397,5.20063e-07);(398,0.000435497);(399,1.17876e-05);(400,0.0096883);(401,0.0191809);(402,4.08562e-14);(403,3.90799e-14);(404,0.00884168);(405,0.00963329);(406,4.08562e-14);(407,0.00952027);(408,4.44089e-14);(409,4.08562e-14);(410,0.00931003);(411,0.0187677);(412,0.00931003);(413,0.0152709);(414,0.000858749);(415,0.00938929);(416,0.0185889);(417,0.0188307);(418,0.0368851);(419,0.00938929);(420,0.00938929);(421,0.01882);(422,0.0282763);(423,3.90799e-14);(424,0.00136156);(425,3.37508e-14);(426,3.90799e-14);(427,0.00686948);(428,0.00686889);(429,0.00686889);(430,6.56829e-05);(431,0.00953272);(432,4.87602e-07);(433,3.37508e-14);(434,3.37508e-14);(435,6.46515e-05);(436,0.019138);(437,0.0191682);(438,0.0191013);(439,0.0283188);(440,0.0373691);(441,0.00963422);(442,3.90799e-14);(443,0.00963517);(444,0.0190757);(445,0.0190808);(446,0.00964036);(447,0.00964036);(448,0.0283368);(449,0.0283368);(450,0.0462484);(451,0.00964036);(452,3.90799e-14);(453,0.00959399);(454,3.37508e-14);(455,4.15592e-05);(456,4.15592e-05);(457,4.08562e-14);(458,3.37508e-14);(459,3.37508e-14);(460,3.37508e-14);(461,4.30413e-05);(462,0.00962763);(463,2.67755e-05);(464,2.67755e-05);(465,2.67755e-05);(466,2.67755e-05);(467,3.37508e-14);(468,1.89001e-07);(469,0.0119622);(470,0.0218288);(471,0.0283155);(472,0.0462194);(473,0.0373647);(474,0.0283155);(475,0.00993854);(476,0.00963421);(477,3.37508e-14);(478,0.00963285);(479,0.0283124);(480,0.00962935);(481,0.0114232);(482,0.00552553);(483,0.00729697);(484,0.00553452);(485,0.0123699);(486,0.0214046);(487,0.00729142);(488,0.00901934);(489,0.00187982);(490,0.00187982);(491,2.57454e-06);(492,5.09707e-06);(493,0.00962808);(494,0.00962808);(495,3.37508e-14);(496,0.00962403);(497,0.0119515);(498,0.00242506);(499,0.00242506);




# Conclusion

Nous pouvons constater qu'au fil des générations la variance diminue, par analogie nous pouvons donc affirmer que nous convergeons vers une catapulte qui produit beaucoup de dégâts et qui vise dans le mille.
