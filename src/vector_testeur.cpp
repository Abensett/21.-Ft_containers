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
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void    Test_Constructors(void)
{
	// std::time_t avant = system_clock::now();
	ft::vector<int> v1;
	ft::vector<int>	v2(5, 8);
	ft::vector<int>::iterator first = v2.begin();
    ft::vector<int>::iterator end = v2.end();

	ft::vector<int>	v3(first, end);
	ft::vector<int> v4(v2);
	print_vector(v1);
	print_vector(v2);
	print_vector(v3);
	print_vector(v4);
	// cout << std::ctime(system_clock::now() - avant) << endl;
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
    ft::vector<int>::const_reverse_iterator it_rev_cst = v1.rbegin();
	cout << "Ceci est un const rev iterator: " << *it_rev_cst << endl;


	print_vector(v1);
	cout << endl;
}


void    Test_erase(void)
{
	ft::vector<int> v1;
	v1.push_back(1);
	print_vector(v1);
	v1.push_back(2);
	v1.push_back(3);
	print_vector(v1);

	v1.push_back(4);
	v1.push_back(5);
	print_vector(v1);

	v1.push_back(6);
	print_vector(v1);
	v1.erase(v1.begin() + 1);
	print_vector(v1);
	v1.erase(v1.end() - 1);
	print_vector(v1);
}

void	Test_insert(void)
{
	ft::vector<int> v1;
	ft::vector<int> v2(5, 8);

	print_vector(v1);
	v1.insert(v1.begin(), 2);
	print_vector(v1);
	v1.insert(v1.begin(), 1);
	print_vector(v1);
	v1.insert(v1.end(), 4);
	print_vector(v1);
	v1.insert(v1.end() - 1, 3);


	print_vector(v1);
	v1.insert(v1.end(), 3, 8);
	print_vector(v1);

	print_vector(v2);
	v2.insert(v2.end(),1);
	print_vector(v2);
	v2.insert(v2.end(), 4, 8);
	print_vector(v2);
	v2.insert(v2.begin() + 2, v1.begin(), v1.end());

}

// pointeurs sur fonctions tests
 void  (*Fcn_tests[])() =
{
	Test_Constructors,
	Test_operator_equal,
    Test_Iterators,
	Test_erase,
	Test_insert
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
	// std::chrono::time_point<std::chrono::system_clock> begin, end;


	int             i = 0;                               // on fait un cast comme ATOI dans ces 3 lignes
	tmp << *av[1];                                      // flux d'insertio dans tmp
	tmp >> i;                                        // flux d'extraction de tmp
	// begin = std::chrono::system_clock::now();
    (*Fcn_tests[i])();        // on exute la fonction a tester dans le tableau de pointeurs grace a l'argument du main
	// end = std::chrono::system_clock::now();
	// duration<double> duration = end - begin;
	// cout << "Temps d'execution: " << duration.count() << endl;
	return 0;
}
