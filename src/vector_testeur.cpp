#include <iostream>
#include <sstream>
#ifndef library
#define library 0
#endif
#if library                 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
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
	// for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
	// 	cout << *it << " ";
	cout << endl;
}

void    Test_Constructors(void)
{

	size_t	n		= 5;
	ft::vector<int> v1;
	ft::vector<int>	v2(n, 8);
	ft::vector<int> v4(v2);
	print_vector(v1);
	print_vector(v2);
	print_vector(v4);
}

void    Test_operator_equal(void)
{
	size_t	n		= 5;
	size_t	n2		= 7;
	size_t	n3		= 5;

	ft::vector<int> v1(n, 5);
	ft::vector<int> v2(n2, 8);
	ft::vector<int> v3(n3, 8);
	v1 = v2;
	print_vector(v1);
}

void    Test_Iterators(void)
{
	// test begin() and end()
	size_t	n		= 5;
    ft::vector<int> v1(n, 5);

	//begin end
    ft::vector<int>::iterator it = v1.begin();
    ft::vector<int>::iterator ite = v1.end();
    ft::vector<int>::const_iterator it_cst = v1.begin();

    print_vector(v1);
	cout << "Ceci est un const iterator: " << *it_cst << endl;

    while (it != ite)
    {
        cout << *it << " ";
        it++;
    }
	cout<< *it++ <<" ";
	cout<< --*it <<" ";
	cout << *it << " ";

	// rebegin rend
	ft::vector<int>::reverse_iterator it2 = v1.rbegin();
    ft::vector<int>::reverse_iterator ite2 = v1.rend();
    print_vector(v1);
    while (it2 != ite2)
    {
        cout << *it2 << " ";
        it2++;
    }
	cout <<endl;
	cout<< *it2++ <<" ";
	cout<< --*it2 <<" ";
	cout << *it2 << " ";

	// test rbegin() and rend()
	ft::vector<int>::reverse_iterator rit(it);
	ft::vector<int>::reverse_iterator rite(ite);

	print_vector(v1);
	cout << endl;
}

// pointeurs sur fonctions tests
 void  (*Fcn_tests[])() =
{
	Test_Constructors,
	Test_operator_equal,
    Test_Iterators,
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
	tmp << *av[1];                                      // flux d'insertio dans tmp
	tmp >> i;                                        // flux d'extraction de tmp

   (*Fcn_tests[i])();        // on exute la fonction a tester dans le tableau de pointeurs grace a l'argument du main

	return 0;
}
