/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/09/19 12:35:43 by abensett         ###   ########.fr       */
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
};
#endif
