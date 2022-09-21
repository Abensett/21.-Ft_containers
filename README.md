# Ft_containers
Le but de ce projet est d'implémenter quelques containers C++ de la bibliothèque standard (Standard Template Library).

## Table of contents
* [Vector](#Vector)  
* [Iterators](#Iterators)  
* [Stack](#Stack)
* [Map](#Map)
* [Utils to implement](#Utils)

### Vector
>  ```= Dynamic contiguous array (SEQUENTIEL)```  
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

### Utils
> * __enable_if__ : <bool B, class T >

### To implement  
> The ones to do are vector, map, stack (mandatory) and set (bonus)

<details>
    <summary>The ones to do are vector, map, stack (mandatory) and set (bonus)</summary>   
    
![image](https://user-images.githubusercontent.com/85625233/189640037-e2556d3a-bef5-4f7b-9404-b3643d0f9b72.png)  

</details>


map: Binary Search Tree of key-value pairs, sorted by unique keys.
- stack: Adapts a container to provide stack (LIFO - Last In First Out)
- 
## Sitographie 
* [Cours container STL](http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf)
* [Vector Infos](https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-170)
* [Iterators](https://cplusplus.com/reference/iterator/)
* [Red Black Trees](https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/)

#### Somes questions
* [Diff between 'typename' and 'class'](https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates)
* [When is 'typename' necessary](https://stackoverflow.com/questions/7923369/when-is-the-typename-keyword-necessary)
* [Allocator : allocate then construct](https://en.cppreference.com/w/cpp/memory/allocator)

* Vector
    * [**Size** = number of elements whereas **Capacity** = the amount of total space](https://stackoverflow.com/questions/6296945/size-vs-capacity-of-a-vector)
    * [**Traits** give information, at the compilation, about certain types thanks to a generic base](https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html)
    * [Why and how using **traits**](https://www.youtube.com/watch?v=bFCzd5U2fsk)
    * [Un itérateur != pointeur  must define 5 required member types by specializing iterator_traits](https://learn.microsoft.com/fr-fr/cpp/standard-library/iterators?view=msvc-170)
    * [**std::enable_if** is an important function to enable certain types for template specialization](https://leimao.github.io/blog/CPP-Enable-If/)
