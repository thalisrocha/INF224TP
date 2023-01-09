# INF224TP

* Question 1 : on appelle cela des methodes virtuelles. On les déclare ainsi dans la classe de base : 

```C++
virtual type method(params) = 0;
``` 

* Question 2 : 
    * **Q:** Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?\ 
    **R:** C'est le **polymorphisme**
    * **Q:** Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?\
    **R:** Il est nécessaire de déclarer les méthodes **virtuelles** dans la classe de base pour assurer une liaison dynamique des méthodes (c'est à dire que les méthodes exécutées soient celles du type du pointé et non du pointeur)
    * **Q:** Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.\
    **R:** Les éléments du tableau sont des **pointeurs**. On fait cela pour réduire la taille du tableau et pouvoir changer la valeur d'un élément du tableau sans avoir à copier l'objet directement, il suffit de copier le pointeur. Il faudra cependant penser à delete les pointeurs du tableau avant de delete le tableau pour éviter une **fuite mémoire**. En Java, on stocke des références dans les tableaux, qui sont des pointeurs, mais de manière cachée, et il n'y a pas besoin de les delete soi-même, le ramasse-miette s'en charge.
