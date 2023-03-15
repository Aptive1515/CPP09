# Module C09 - Ecole 42

## Ex00
Vous devez créer un programme qui affiche la valeur d'une certaine quantité de bitcoins à une certaine date.

Ce programme doit utiliser une base de données au format CSV qui représente le prix du bitcoin au fil du temps. Cette base de données est fournie avec cet exercice.

Le programme prendra en entrée une deuxième base de données stockant les différentes dates et prix à évaluer.

Votre programme doit respecter les règles suivantes :
- Le nom du programme est btc.
- Votre programme doit prendre un fichier en argument.
- Chaque ligne de ce fichier doit utiliser le format suivant : "date | valeur".
- Une date valide sera toujours au format Année-Mois-Jour.
- Une valeur valide doit être soit un nombre décimal, soit un entier positif compris entre 0 et 1000.


Votre programme utilisera la valeur dans votre fichier d'entrée ainsi que la date associée.

Votre programme doit afficher sur la sortie standard le résultat de la valeur multipliée par le taux de change en fonction de la date indiquée dans votre base de données.

## ex01

```
La notation polonaise inversée (NPI) est une notation mathématique dans laquelle les opérateurs suivent les opérandes. Par exemple, pour l'expression arithmétique "3 + 4", en notation polonaise inversée, elle serait écrite comme "3 4 +".

La notation polonaise inversée a été inventée par le mathématicien polonais Jan Łukasiewicz dans les années 1920. Elle est utilisée dans certains calculatrices et langages de programmation pour évaluer des expressions arithmétiques.
```

Vous devez créer un programme qui respecte ces contraintes:
- Le nom du programme est RPN.
- Votre programme doit prendre en argument une expression mathématique en notation polonaise inversée.
- Les nombres utilisés dans cette opération seront toujours inférieurs à 10.
- Votre programme doit traiter cette expression et afficher le résultat correct sur la sortie standard.
- Si une erreur se produit pendant l'exécution du programme, un message d'erreur doit être affiché sur la sortie standard.
- Votre programme doit être capable de gérer les opérations avec ces opérateurs : "+ - / *

You don’t need to manage the brackets or decimal numbers.

```
Here is an example of a standard use:
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "(1 + 1)"
Error
```

Warning: The container(s) you used in the previous exercise are
forbidden here. The container(s) you used to validate this exercise
will not be usable for the rest of this module.

## ex02

Vous devez créer un programme qui respecte ces contraintes :
- Le nom du programme est PmergeMe.
- Votre programme doit être capable d'utiliser une séquence d'entiers positifs en argument.
- Votre programme doit utiliser un algorithme de tri par fusion-insertion pour trier la séquence d'entiers positifs.
- Si une erreur se produit pendant l'exécution du programme, un message d'erreur doit être affiché sur la sortie standard.

Vous devez utiliser au moins deux conteneurs différents dans votre code pour valider cet exercice. Votre programme doit être capable de gérer au moins 3000 entiers différents.

Il est fortement conseillé d'implémenter votre algorithme pour chaque conteneur et donc d'éviter d'utiliser une fonction générique.

Voici quelques directives supplémentaires sur les informations que vous devez afficher ligne par ligne sur la sortie standard :

- Sur la première ligne, vous devez afficher un texte explicite suivi de la séquence d'entiers positifs non triée.
- Sur la deuxième ligne, vous devez afficher un texte explicite suivi de la séquence d'entiers positifs triée.
- Sur la troisième ligne, vous devez afficher un texte explicite indiquant le temps utilisé par votre algorithme en précisant le premier conteneur utilisé pour trier la séquence d'entiers positifs.
- Sur la dernière ligne, vous devez afficher un texte explicite indiquant le temps utilisé par votre algorithme en précisant le deuxième conteneur utilisé pour trier la séquence d'entiers positifs.


```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
```
