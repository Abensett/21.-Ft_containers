/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/09/21 21:25:53 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iterator>

namespace ft
{

	/*
	**	ITERATOR BASE CLASS
	** helper to define the iterator traits of an iterator.
	*/
	template<typename Category, typename T, typename Difference = std::ptrdiff_t, typename Pointer = T*, typename   Reference = T&>
	struct iterator{
	typedef T 					value_type;				// The type "pointed to" by the iterator.
	typedef Difference 			difference_type;		// The type to represent the difference between two iterators.
	typedef	Pointer				pointer;				// A type to represent a pointer-to-value_type
	typedef Reference 			reference;				// A type to represent a reference-to-value_type
	typedef Category			iterator_category;		// The iterator category (input, output, forward, bidirectional, random access)
	};



	struct random_access_iterator_tag {};		//Categories used to identify random access iterators
	struct bidirectional_iterator_tag {};
	struct forward_iterator_tag {};
	struct input_iterator_tag {};
	struct output_iterator_tag {};

		/*
	**	ITERATOR_TRAITS
	** 	- A type trait class that provides a uniform interface to obtaining properties of iterator types.
	**  - specializations for iterator types
	** MANDATORY IF YOU WANT TO IMPLEMENT YOUR OWN ITERATOR
	*/
	// STRUCT public whereas CLASS private
	template <class Iterator> struct iterator_traits
	{
		typedef typename Iterator::difference_type 			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef	typename Iterator::pointer					pointer;
		typedef typename Iterator::reference 				reference;
		typedef typename Iterator::iterator_category		iterator_category;
	};

	template <class T> struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t 							difference_type;
		typedef T 										value_type;
  		typedef T* 										pointer;
  		typedef T& 										reference;
   		typedef std::random_access_iterator_tag 		iterator_category;
	};

	template <class T> struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t 							difference_type;
		typedef T										value_type;
		typedef const	T* 								pointer;
		typedef const	T&								reference;
		typedef std::random_access_iterator_tag 		iterator_category;
	};


/* ENABLE_IF
**
**- A type trait that provides a member typedef type if the condition is true, otherwise no member typedef is provided.
** SFINAE  Substitution Failure Is Not An Error
** Using types that are not enabled by std::enable_if
** for template specialization will result in compile-time error.
*/
template <bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

/* IS_INTEGRAL
**
**- A type trait that determines whether T is an integral type.
** - Integral types are those that can be represented as a sequence of bits.
** - bool, char, wchar_t, char16_t, char32_t, short, int, long, long long,
** - unsigned short, unsigned int, unsigned long, unsigned long long
**
** - if integral type then static const bool value = true
*/
template< class T > struct is_integral
{	static const bool value = false; };

template <> struct is_integral<bool> { static const bool value = true; };
template <> struct is_integral<char> { static const bool value = true; };
template <> struct is_integral<wchar_t> { static const bool value = true; };
template <> struct is_integral<short> { static const bool value = true; };
template <> struct is_integral<int> { static const bool value = true; };
template <> struct is_integral<long> { static const bool value = true; };
template <> struct is_integral<long long> { static const bool value = true; };
template <> struct is_integral<unsigned short> { static const bool value = true; };
template <> struct is_integral<unsigned int> { static const bool value = true; };
template <> struct is_integral<unsigned long> { static const bool value = true; };
template <> struct is_integral<unsigned long long> { static const bool value = true; };

/* LEXICOGRAPHICAL_COMPARE
**
** - Compares the elements in the range [first1,last1) with those of the range beginning at first2,
** and returns true if all the elements in both ranges match or if the first range is lexicographically less than the second.
** - The elements are compared using operator< for this verions
*/
template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
 							InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/* PAIR
**
** - A pair is a simple container defined in <utility> that stores two heterogeneous objects as a single unit.
*/


template< class T1, class T2> struct pair
{
	typedef T1 first_type;									// The type of the first element
	typedef T2 second_type;									// The type of the second element

	T1 first;												// the first stored value
	T2 second;												// the second stored value


	pair() : first(T1()), second(T2()) {};					// DEFAULT CONSTRUCTOR
	template<class U, class V> pair (const pair<U,V>& pr)	// COPY CONSTRUCTOR
	{
		first = pr.first;
		second = pr.second;
	};
	pair (const first_type& a, const second_type& b) : first(a), second(b) {};	// INITIALIZATION CONSTRUCTOR

	pair& operator= (const pair& pr)						// ASSIGNMENT OPERATOR
	{
		first = pr.first;
		second = pr.second;
		return *this;
	};

};

// NON-MEMBER FUNCTIONS FOR PAIR (RELATIONAL OPERATORS)
template <class T1, class T2>  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return lhs.first == rhs.first && lhs.second == rhs.second;};
template <class T1, class T2>  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return !(lhs == rhs);};
template <class T1, class T2>  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); };
template <class T1, class T2> bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); };
template <class T1, class T2>  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; };
template <class T1, class T2>  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }


/* MAKE PAIR
**
** - Constructs a pair object with its elements initialized to the values passed as arguments.
*/
template <class T1, class T2>  pair<T1,T2> make_pair (T1 x, T2 y)
{ return ( pair<T1,T2>(x,y) ); };


};
// End of namespace FT
#endif
