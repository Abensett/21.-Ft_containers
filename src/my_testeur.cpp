#include <iostream>
#include <sstream>
#ifndef library
#define library 0
#endif
#if library                 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
#endif

using std::cout;
using std::endl;
using std::string;
using std::stringstream;


// print a vector of any type: size, capacity, element
template <typename T> void print_vector( ft::vector<T> &v )
{
	cout << "VECTOR "<< endl;
	cout << "size: " << v.size() << endl;
	cout << "capacity: " << v.capacity() << endl;
	cout << "content:" << endl;
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
			cout << *it << " ";
	cout << endl;
}


// print a vector of any type: size, capacity, element
template <typename T>
std::string	printPair(const T &iterator, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	o << std::endl;
	return ("");
}

template <typename key, typename T> void print_map( ft::map<key,T> &v )
{
	cout << "MAP"<< endl;
	cout << "size: " << v.size() << endl;
	cout << "content: " << endl;
	for (typename ft::map<key,T>::iterator it = v.begin(); it != v.end(); it++)
		printPair(it);
	cout << endl;
}

template <typename T> void print_set( ft::set<T> &v )
{
	cout << "size: " << v.size() << endl;
	cout << "capacity: " << v.capacity() << endl;
	cout << "content: ";
	for (typename ft::set<T>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

	/************************************************************
	 * 						VECTOR TESTS						*
	 ************************************************************/
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

void	Test_resize(void)
{
	ft::vector<int> v1;
	v1.resize(5);
	print_vector(v1);
	v1.resize(8, 8);
	print_vector(v1);
	v1.resize(3);
	print_vector(v1);
}

void	Test_capacity(void)
{
	ft::vector<string> v1;
	cout << "size: " << v1.size() << endl;
	cout << "capacity: " << v1.capacity() << endl;
	v1.push_back("hello");
	cout << "size: " << v1.size() << endl;
	cout << "capacity: " << v1.capacity() << endl;
	cout << "max size: " << v1.max_size() << endl;
	ft::vector<string> v2;
	cout << "empy: " << v2.empty() << endl;
	cout << "empy: " << v1.empty() << endl;
}

void	Test_assign(void)
{
	ft::vector<int> v1(5, 8);
	ft::vector<int> v2(3, 5);
	print_vector(v1);
	print_vector(v2);
	v1.assign(v2.begin(), v2.end());
	print_vector(v1);
	print_vector(v2);
	v1.assign(5, 8);
	print_vector(v1);
};

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

void	Test_pop_back(void)
{
	ft::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	print_vector(v1);
	v1.pop_back();
	print_vector(v1);
}

void 	Test_push_back(void)
{
	ft::vector<int> v1;
	v1.push_back(1);
	print_vector(v1);
	v1.push_back(2);
	v1.push_back(3);
	print_vector(v1);
}

void	Test_clear(void)
{
	ft::vector<int> v1(5, 8);
	print_vector(v1);
	v1.clear();
	print_vector(v1);
};

void	Test_relationals(void)
{
	ft::vector<int> v1(5, 8);
	ft::vector<int> v2(3, 5);
	if (v1 == v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (v1 != v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (v1 < v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (v1 > v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (v1 <= v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (v1 >= v2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
}

void	Test_swap(void)
{
	ft::vector<int> v1(5, 8);
	ft::vector<int> v2(3, 5);
	print_vector(v1);
	print_vector(v2);
	v1.swap(v2);
	print_vector(v1);
	print_vector(v2);
};
	/************************************************************
	 * 						STACK	 TESTS						*
	 ************************************************************/
void	Test_top(void)
{
	ft::stack<int> s1;
	s1.push(1);
	s1.push(2);
	cout << s1.top() << endl;
	s1.push(3);
	cout << s1.top() << endl;
}

void	Test_pop(void)
{
	ft::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.pop();
	cout << s1.top() << endl;
}

void	Test_push(void)
{
	ft::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << s1.top() << endl;
}

void	Test_empty(void)
{
	ft::stack<int> s1;
	cout << s1.empty() << endl;
	s1.push(1);
	cout << s1.empty() << endl;
}

void	Test_rel_stack(void)
{
	ft::stack<int> s1;
	ft::stack<int> s2;
	ft::stack<string> s3;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s3.push("hello");
	s3.push("world");
	s3.push("!");
	if (s1 == s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (s1 != s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (s1 < s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (s1 > s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (s1 <= s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	if (s1 >= s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
	s2.pop();
	if (s1 == s2)
		cout << "OUI" << endl;
	else
		cout << "NON"<< endl;
}


	/************************************************************
	 * 						MAP		 TESTS						*
	 ************************************************************/


void	Test_constructors_map(void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<char, int>('a', 20) );
	m1.insert( ft::pair<char, int>('b', 23) );
	m1.insert( ft::pair<char, int>('c', 24) );
	m1.insert( ft::pair<char, int>('d', 26) );
	print_map(m1);
	ft::map<int, int> m2(m1);
	print_map(m2);
	ft::map<int, int> m3;
	m3 = m1;
	print_map(m3);
}


void	Test_Iterators_map(void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<char, int>('a', 20) );
	m1.insert( ft::pair<char, int>('b', 23) );
	m1.insert( ft::pair<char, int>('c', 24) );
	m1.insert( ft::pair<char, int>('d', 26) );
	print_map(m1);
	ft::map<int, int>::iterator it = m1.begin();
	ft::map<int, int>::iterator ite = m1.end();
	ite--;
	cout << "begin : " << it->first << " " << it->second << endl;
	cout << "end : " << ite->first << " " << ite->second << endl;
    print_map(m1);
	ft::map<int, int>::reverse_iterator rit = m1.rbegin();
	ft::map<int, int>::reverse_iterator rite = m1.rend();
	rite--;
	cout << "rbegin : " << rit->first << " " << rit->second << endl;
	cout << "rend : " << rite->first << " " << rite->second << endl;
	print_map(m1);

}


void	Test_capacity_map(void)
{
	ft::map<int, int> m1;
	cout << m1.empty() << endl;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	cout << m1.empty() << endl;
	cout << m1.size() << endl;
}

void Test_insert_map(void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	print_map(m1);
	ft::map<int, int>::iterator it = m1.begin();
	it++;
	it++;
	m1.insert( ft::pair<int, char>(8, 'h') );
	print_map(m1);
	m1.insert( ft::pair<int, char>(7, 'g') );
	print_map(m1);
	m1.insert( ft::pair<int, char>(6, 'f') );
	print_map(m1);
}


void Test_erase_map(void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	print_map(m1);
	m1.erase(m1.begin());
	print_map(m1);
	m1.erase(24);
	print_map(m1);
	m1.erase(m1.begin(), m1.begin()++);
	print_map(m1);


}


void Test_clear_map(void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	print_map(m1);
	m1.clear();
	print_map(m1);
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	print_map(m1);
	m1.clear();
	print_map(m1);
}


void	Test_swap_map (void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	ft::map<int, int> m2;
	m2.insert( ft::pair<int, char>(1, 'a') );
	m2.insert( ft::pair<int, char>(2, 'b') );
	m2.insert( ft::pair<int, char>(3, 'c') );
	m2.insert( ft::pair<int, char>(4, 'd') );
	m2.insert( ft::pair<int, char>(5, 'e') );
	m2.insert( ft::pair<int, char>(6, 'f') );
	m2.insert( ft::pair<int, char>(7, 'g') );
	m2.insert( ft::pair<int, char>(8, 'h') );

	print_map(m1);
	print_map(m2);
	m1.swap(m2);
	print_map(m1);
	print_map(m2);
};

void  Test_operations_map (void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );
	m1.insert( ft::pair<int, char>(9, 'i') );
	m1.insert( ft::pair<int, char>(10, 'j') );
	m1.insert( ft::pair<int, char>(11, 'k') );
	m1.insert( ft::pair<int, char>(12, 'l') );
	ft::map<int, int>::iterator it = m1.find(5);
	std::cout << it->first << " " << it->second << std::endl;
	it = m1.find(24);
	if (it == m1.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << it->first << " " << it->second << std::endl;
	if (m1.count(5))
		std::cout << "5 is in the map = " << it->second << std::endl;
	else
		std::cout << "5 is not in the map ="<<std::endl;
	if (m1.count(24))
		std::cout << "24 is in the map = " << it->second << std::endl;
	else
		std::cout << "24 is not in the map ="<<std::endl;
	if (m1.lower_bound(5) != m1.end())
		std::cout << "lower bound of 5 is = " << m1.lower_bound(5)->second << std::endl;
	else
		std::cout << "lower bound of 5 is = " << "end" << std::endl;
	if (m1.lower_bound(24) != m1.end())
		std::cout << "lower bound of 24 is = " << m1.lower_bound(24)->second << std::endl;
	else
		std::cout << "lower bound of 24 is = " << "end" << std::endl;
	if(m1.upper_bound(5) != m1.end())
		std::cout << "upper bound of 5 is = " << m1.upper_bound(5)->second << std::endl;
	else
		std::cout << "upper bound of 5 is = " << "end" << std::endl;
	if(m1.upper_bound(24) != m1.end())
		std::cout << "upper bound of 24 is = " << m1.upper_bound(24)->second << std::endl;
	else
		std::cout << "upper bound of 24 is = " << "end" << std::endl;
	ft::map<int, int>::iterator it1 = m1.equal_range(5).first;
	ft::map<int, int>::iterator it2 = m1.equal_range(5).second;
	std::cout << "equal range of 5 is = ";
	while (it1 != it2)
	{
		std::cout << it1->second << " ";
		it1++;
	}
};

void Test_rel_map (void)
{
	ft::map<int, int> m1;
	m1.insert( ft::pair<int, char>(1, 'a') );
	m1.insert( ft::pair<int, char>(2, 'b') );
	m1.insert( ft::pair<int, char>(3, 'c') );
	m1.insert( ft::pair<int, char>(4, 'd') );
	m1.insert( ft::pair<int, char>(5, 'e') );
	m1.insert( ft::pair<int, char>(6, 'f') );
	m1.insert( ft::pair<int, char>(7, 'g') );
	m1.insert( ft::pair<int, char>(8, 'h') );

	ft::map<int, int> m2;
	m2.insert( ft::pair<int, char>(1, 'a') );
	m2.insert( ft::pair<int, char>(2, 'b') );
	m2.insert( ft::pair<int, char>(3, 'c') );
	m2.insert( ft::pair<int, char>(4, 'd') );
	m2.insert( ft::pair<int, char>(5, 'e') );
	m2.insert( ft::pair<int, char>(6, 'f') );
	m2.insert( ft::pair<int, char>(7, 'g') );
	m2.insert( ft::pair<int, char>(8, 'h') );

	ft::map<int, int> m3;
	m3.insert( ft::pair<int, char>(1, 'a') );
	m3.insert( ft::pair<int, char>(2, 'c') );
	m3.insert( ft::pair<int, char>(3, 'c') );

	if(m2 == m1)
		std::cout << "m2 == m1" << std::endl;
	else
		std::cout << "m2 != m1" << std::endl;
	if(m2 != m3)
		std::cout << "m2 != m3" << std::endl;
	else
		std::cout << "m2 == m3" << std::endl;
	if(m2 < m3)
		std::cout << "m2 < m3" << std::endl;
	else
		std::cout << "m2 > m3" << std::endl;
	if(m2 > m3)
		std::cout << "m2 > m3" << std::endl;
	else
		std::cout << "m2 < m3" << std::endl;
	if(m2 <= m3)
		std::cout << "m2 <= m3" << std::endl;
	else
		std::cout << "m2 > m3" << std::endl;
	if(m2 >= m3)
		std::cout << "m2 >= m3" << std::endl;
	else
		std::cout << "m2 < m3" << std::endl;
};


// pointeurs sur fonctions tests
void  (*Fcn_tests[])() =
{
	// Vector
	Test_Constructors,
	Test_operator_equal,
	Test_Iterators,
	Test_resize,
	Test_capacity,
	Test_assign,
	Test_erase,
	Test_insert,
	Test_push_back,
	Test_pop_back,
	Test_clear,
	Test_relationals,
	Test_swap,

	// Stack
	Test_top,
	Test_push,
	Test_pop,
	Test_empty,
	Test_rel_stack,

	// Map
	Test_constructors_map,
	Test_Iterators_map,
	Test_capacity_map,
	Test_insert_map,
	Test_erase_map,
	Test_clear_map,
	Test_swap_map,
	Test_operations_map,
	Test_rel_map,
};

int main(int ac, char**av)
{
	if(ac != 2)
	{
		cout << "usage: ./vector_testeur [test_number]" << endl;
		return 1;
	}
	stringstream    tmp;
	string          idx(av[1]);

	int             i = 0;                               // on fait un cast comme ATOI dans ces 3 lignes
	tmp << idx;                                      // flux d'insertio dans tmp
	tmp >> i;                                        // flux d'extraction de tmp
	cout << "Test number: " << idx << " = " << endl;
	(*Fcn_tests[i])();        // on exute la fonction a tester dans le tableau de pointeurs grace a l'argument du main
	return 0;
}
