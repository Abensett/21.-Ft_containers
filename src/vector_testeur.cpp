#include <iostream>
#include "vector.hpp"
#define library 1
#if library                  //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
#else
	// #include <map.hpp>
	// #include <stack.hpp>
	#include <vector.hpp>
#endif

using namespace std;
int main()
{

    //CONSTRUCTORS
    ft::vector<string> vecteurvide;
    ft::vector<string> vecteurfilled(5, "test vecteur fill");

     const  string tests_vector[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

    ft::vector<int> vect(2);
    vect[0] = 1; // accès direct à l’indice 0 pour affecter la valeur 1
    vect[1] = 2; // accès direct à l’indice 1 pour affecter la valeur 2
    // augmente et diminue la taille du vector
    ft::vector<int> vect2(0, 5);
    ft::vector<int>::iterator it;
    it = vect.begin();
    vect.push_back( 6 ); // ajoute l’entier 6 à la fin
    vect.push_back( 7 ); // ajoute l’entier 7 à la fin
    vect.push_back( 8 ); // ajoute l’entier 8 à la fin
    vect.pop_back(); // enleve le dernier élément et supprime l’entier 8



    cout << "Le vecteur vect contient " << vect.size() << " entiers : \n";
    // utilisation d’un indice pour parcourir le vecteur vect
    for(unsigned int i=0;i<vect.size();i++)
    cout << "vect[" << i << "] = " << vect[i] << '\n';
    cout << '\n';



    return 0;
}
