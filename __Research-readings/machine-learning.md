# Apprentissage profond pour la génération de trajectoire
Recherches de défrichage sur la possibilité d'implémentation d'un algorithme d'apprentissage profond pour la génération de trajectoire.

Notre objectif est de générer des trajectoires pour le bras du robot Reachy, en se basant sur des données d'exemple obtenu par la téléopération par un casque de réalité virtuelle et ses manettes. 

## Les modèles de d'apprentissage applicables à cette problématique
1. **Apprentissage par imitation/démonstration**, en observant les actions d'un opérateur humain
2. **Apprentissage par renforcement**, avec un système de récompensant les actions qui se rapprochent de la cible
3. **Apprentissage par programme/automate**, selon des règles prédéfinies

Dans notre cas, c'est l'apprentissage par démonstration qui concerne plus particulièrement le sujet de notre projet,
et que nous souhaitons implémenter.

Pour utiliser un tel algorithme, il nous faut premièrement collecter des données par la téléopération, en enregistrement des mouvements cibles réalisés par l'opérateur humain.
Il faudra exécuter une certaine variété de mouvements pour couvrir plusieurs situations, ainsi qu'opérer un pré-traitement sur ces données pour les rendre utilisables par l'algorithme.
Enfin, il nous faudra définir une métrique d'évaluation de la qualité d'un mouvement généré par l'algorithme, afin de pouvoir l'optimiser.

## Apprentissage par démonstration
Il existe plusieurs modèles qui permettent de mettre en place un tel algorithme.
1. **Réseau de neurones**, avec des positions sous forme de vecteurs numériques
2. Réseau de neurones **récurrents**, pour un modèle basé sur les séquences évènements
3. **Modèle de dynamique de mouvement**, qui utilisent des équations mathématiques comme donnée pour représenter les mouvements
4. Combinaison d'un **modèle caché de markov** pour la selection de trajectoire, et d'une approche sur les **Non-Uniform Rational B-Spline** (NURBS) pour l'approximation de trajectoire (cf. [nurbs])
Les 2 premières solutions demandent d'avoir une base de donnée d'entraînement conséquente, ce qui sera dur à mettre en place pour notre projet. 
Cette 3e proposition semble donc être la plus envisageable.

## Pour aller plus loin
Différents travaux de recherches proposent des solutions supplémentaires à ajouter, afin de préciser le modèle, ou encore d'optimiser les résultats.
1. Utiliser les **DMP** (Dynamic Movement Primitives) pour représenter les mouvements en précisant le modèle de dynamique de mouvement (cf. [dmp])
2. Combiner ce modèle avec un **modèle de mélange gaussien** pour définir une probabilité de position d'une articulation (cf. [gmm]) 


[nurbs]: https://reader.elsevier.com/reader/sd/pii/S0921889006000212?token=26F0964C179946EE608127CFCBA7FBA13859270CF79230438B896C63DE62A1E8A8EA3832824710F01A02C2D54678FDAB&originRegion=eu-west-1&originCreation=20230104133701
[dmp]: https://pure.mpg.de/rest/items/item_1792287/component/file_3184783/content
[gmm]: https://ieeexplore.ieee.org/document/8081982
