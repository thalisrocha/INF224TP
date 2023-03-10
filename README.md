# INF224TP

* Question 1 :
    * **Q:** Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?\
    **R:** On appelle cela des methodes virtuelles. On les déclare ainsi dans la classe de base : 
    ```C++
    virtual type method(params) = 0;
    ``` 
    * **Q:** Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?\
    **R:** Car la classe de base possède une méthode abstraite.

* Question 2 : 
    * **Q:** Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?\
    **R:** C'est le **polymorphisme**
    * **Q:** Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?\
    **R:** Il est nécessaire de déclarer les méthodes **virtuelles** dans la classe de base pour assurer une liaison dynamique des méthodes (c'est à dire que les méthodes exécutées soient celles du type du pointé et non du pointeur)
    * **Q:** Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.\
    **R:** Les éléments du tableau sont des **pointeurs**. On fait cela pour permettre le traitement uniforme des éléments du tableau en utilisant le polymorphisme. Il faudra cependant penser à delete les pointeurs du tableau avant de delete le tableau pour éviter une **fuite mémoire**. En Java, on stocke des références dans les tableaux, qui sont des pointeurs, mais de manière cachée, et il n'y a pas besoin de les delete soi-même, le ramasse-miette s'en charge.

* Question 3 :
    * **Q:** Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?\
    **R:** La seule classe ayant pour attribut un pointeur alloué sur le tas est la classe ``Film`` (le tableau des chaptires). Il faut donc s'assurer de libérer ce tableau quand un élément de type ``Film``. On met donc ce bout de code dans le destructeur de la classe ``Film``, après s'être assuré que le desctructeur de ``MultimediaObject`` est bien virtual :  
    ```C++
    ~Film() override {delete[] chapters;}
    ```
    * **Q:** La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?\
    **R:** Le problème est que par défaut les copies sont superficielles, donc seuls les pointeurs seront copiés et ils pointeront donc vers le même objet, qui sera donc modifié par les deux copies et qui sera aussi détruit deux fois. La solution pour pallier ce problème est de définir des opérateurs de copie.

* Question 4 : 
    * **Q:** Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.\
    **R:** Il faut avoir des pointeurs pour pouvoir permettre un traitement uniforme via le polymorphisme. En Java, tout est référence (donc pointeur) donc un tableau contient forcément des références vers les objets (i.e des pointeurs)

* Question 5 : 
    * **Q:** Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?\
    **R:** Il faut déclarer les constructeurs de `Picture`, `Film`, `Video` et `Group` en tant que `protected` (pour permettre l'héritage) et déclarer la classe `DataBase` en tant que `friend` de ces dernières.