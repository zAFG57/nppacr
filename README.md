# NPPACR ````N Plus Proche Avrage Rapide```

## description du projet: 
Ce projet est une experience personnel pour développer une IA décisionnelle. 
J'ai vue quelques concepts de l'algorythme ````knn``` en cours ```d'aide à la désision``` en 3ème année.
ce programme est donc une adaptation à ma sauce de cette algo.

## opti intéraissante:

### distance sans racine: 
la fonciton racine ne change pas l'ordre des distances mais juste leurs ordres de grandeur donc on peut juste évaluer la somme des différences des dimmension au carré pour obtenir une distance. 

### multi thread: 
on découpe l'entièrter des points en n groupes de points pour les n thread.
Chaque thread est dédier à trouver les m points les plus proche du point souhaiter.

### élimination rapide:

Le but est déliminer rapidement des points qui ne peuvent pas être ceux que vous chercher sans avoir à évaluer leur distance.
Pour cela prener un point au hazard puis éliminer tout ceux qui sont dans la même direction mais plus loin.
Les points qui correspond à cette description sont des points qui ont une valeur absolue supperieur ou égale sur toutes les
dimmentions. Ainsi on supprimes tout les points qui sont dans les limites des droites ortogonale à la droite dirrectrice relient le point de départ et le point pris au hazard et qui ont comme unique point séquent le point pris au hazard. On supprime tout ces points qui sont au dela de ces limites que si il y a plus de m point dans la boite de x dimension formé entre les x lignes d'origines et les droites ortogonales précédement crée (virtuellemet on ne crée rien en vrai). Ce nouveau groupe de point on peut les reperer si toutes les dimmensions sont du même signe et si leur valeur absolue est compris entre zero et la valeur du point de base.

