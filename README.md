# Ft_containers
Le but de ce projet est d'implémenter quelques containers C++ de la bibliothèque standard (Standard Template Library).

## Table of contents
* [Vector](#Vector)  
* [Part 2](#Reinterpretation-types)  

### Vector
>  Conteneur séquentiel qui encapsule les tableaux de taille dynamique.  
>  Les éléments sont stockés de façon contigüe, ce qui signifie que les éléments sont ```accessibles non seulement
via les itérateurs```, mais aussi ```à partir des pointeurs``` classiques sur un élément.  
> <details>
    <summary>Propreties STD</summary>  
Sequence
    Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.
Dynamic array
    Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively fast addition/removal of elements at the end of the sequence.
Allocator-aware
    The container uses an allocator object to dynamically handle its storage needs. 
</details>
```C
int main (void)
{
}
```


## Sitographie 
* [Cours container STL](http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf)
* [Red Black Trees](https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/)
*
*
