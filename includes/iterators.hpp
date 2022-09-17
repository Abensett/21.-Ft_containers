/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/09/17 12:04:27 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iterator>

namespace ft
{
	template <typename Vector> 
	class VectorIterator
	{
		typedef T         		value_type;
		typedef Distance  		difference_type;
		typedef Pointer  		pointer;
		typedef Reference 		reference;
   		typedef Category  		iterator_category;
		public : 
			
	};
	/*
	*	ITERATOR BASE CLASS
	*/
	template<typename Category, typename T, typename Difference = ptrdiff_t,
         typename Pointer = T*, typename   Reference = T&>
	struct iterator{	
	typedef T 					value_type;				// The type "pointed to" by the iterator.
	typedef Difference 			difference_type;		// A signed integer type, identical to: iterator_traits<iterator>::difference_type
	typedef	Pointer				pointer;				// A type to represent a pointer-to-value_type
	typedef Reference 			reference;				// A type to represent a reference-to-value_type
	typedef Category			iterator_category;		// The iterator category (input, output, forward, bidirectional, random access)
	};

	/*
	**	ITERATOR_TRAITS
	** 	- A type trait class that provides a uniform interface to obtaining properties of iterator types.
	**  - specializations for iterator types
	*/

	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct forward_iterator_tag {};
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	
	template <class Iterator> class iterator_traits
	{
		typedef typename Iterator::difference 			difference_type;		
		typedef typename Iterator::value_type			value_type;				
		typedef	typename Iterator::pointer				pointer;				
		typedef typename Iterator::reference 			reference;				
		typedef typename Iterator::iterator_Category	iterator_category;		
	};
	
	template <class T> class iterator_traits<T*>
	{
		typedef ptrdiff_t 								difference_type;		
 		typedef ptrdiff_t 								difference_type;
  		typedef T* 										pointer;
  		typedef T& 										reference;
   		typedef random_access_iterator_tag 				iterator_category;
	};
	
	template <class T> class iterator_traits<const T*>
	{
		typedef ptrdiff_t 								difference_type;		
 		typedef ptrdiff_t 								difference_type;
  		typedef T* 										pointer;
  		typedef T& 										reference;
   		typedef random_access_iterator_tag 				iterator_category;
	};
};
#endif
