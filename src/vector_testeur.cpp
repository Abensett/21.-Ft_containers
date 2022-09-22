#include <iostream>
#include <sstream>
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

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// print a vector of any type: size, capacity, element
template <typename T> void print_vector( ft::vector<T> &v )
{
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "content: ";
    for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void    Test_Constructors(void)
{
    cout << "Test_Constructor" << endl;
    ft::vector<int> v1;

}

void    Test_operator_equal(void)
{
    cout << "Test_Constructor2" << endl;
    ft::vector<int> v1;

}

// pointeurs sur fonctions tests
 void  (*Fcn_tests[])() =
{
	Test_Constructors,
    Test_operator_equal,
};

int main(int ac, char**av)
{
    if(ac != 2)
    {
        cout << "usage: ./vector_testeur [test_number]" << endl;
        return 1;
    }

    stringstream    tmp;
    string          idx;

    int             i = 0;                               // on fait un cast comme ATOI dans ces 3 lignes
    tmp << *av[i];                                      // flux d'insertio dans tmp
    tmp >> i;                                        // flux d'extraction de tmp

   (*Fcn_tests[i])();        // on exute la fonction a tester dans le tableau de pointeurs grace a l'argument du main

    return 0;
}
