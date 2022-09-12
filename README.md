# Ft_containers
Le but de ce projet est d'implémenter quelques containers C++ de la bibliothèque standard (Standard Template Library).

## Table of contents
* [Vector](#Vector)  
* [Iterators](#Iterators )  

### Vector
>  Conteneur séquentiel qui encapsule les tableaux de taille dynamique.  
>  Les éléments sont stockés de façon contigüe, ce qui signifie que les éléments sont ```accessibles non seulement
via les itérateurs```, mais aussi ```à partir des pointeurs``` classiques sur un élément.  


<details>
    <summary>Propreties STD</summary>  
Sequence  
    Elements in sequence containers arenordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.  
Dynamic array  
    Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively fast addition/removal of elements at the end of the sequence.
Allocator-aware
    The container uses an allocator object to dynamically handle its storage needs. 
    
</details>

<img width="245" alt="Screenshot 2022-08-24 at 12 47 59" src="https://user-images.githubusercontent.com/85625233/186400146-a6ad44ca-437c-41b1-b85d-473b9dd52b49.png">

  
### Iterators
> Iterators are classified into five categories depending on the functionality they implement  
> ```Random Access Pointers are equivalent to standard pointers.```

<img width="641" alt="Screenshot 2022-08-24 at 13 12 18" src="https://user-images.githubusercontent.com/85625233/186404935-9ab09210-5622-49be-bfe4-0dc20f6d60ca.png">




## Sitographie 
* [Cours container STL](http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf)
* [Red Black Trees](https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/)
* [Iterators](https://cplusplus.com/reference/iterator/)
*
