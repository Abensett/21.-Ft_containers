/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/09/12 14:28:10 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		/*
		** Public Member Functions divided into 6 categories
		* 1. Member types
		* 2. Member functions
		* 3. Iterators
		* 4. Capacity
		* 5. Element access
		* 6. Modifiers
		*/


	// protected :
	// 			allocator_type		_allocator;
	// 			size_type			_n;
	// 			value				_value_type;
	// 			size_type			_capacity;
	// 			pointer				_elements;
	public:

			/************************************************************
			 * 						MEMBER TYPES						*
			 ************************************************************/

			// typedef -> to define a type
			// typename -> specifies that the next identifier is a type

			/* First template parameter T -> represents the type of data stored */
			typedef T											value_type;
			/* Second template parameter Alloc
			** default allocator template used if not specified in args
			** (allocator<value_type>)
			**/
			typedef Alloc                                       allocator_type;
			/*
			** allocator_type::reference
			** A type provides a reference to an element stored in
			** a vector.

			** For the default allocator is a reference to value_type
			** (value_type&)
			*/
			typedef typename allocator_type::reference          reference;

			/*
			** allocator_type::const_reference
			** Type that give a reference to a const element stored.
			** Useful to read and perform const operator.
			** A type const_reference can't be used to modify the value
			** of an element.
			** For the default allocator is a const reference to value_type
			** (const value_type&)
			*/
			typedef typename allocator_type::const_reference    const_reference;

			/*
			** allocator_type::pointer
			** Type that gives a pointer to an element stored.
			** A type pointer can be used to modify the value of
			** an element.

			** For the default allocator is a pointer to value_type
			** (value_type*)
			*/
			typedef typename allocator_type::pointer            pointer;

			/*
			** allocator_type::const_pointer
			** Type that gives a const pointer to an element stored.
			**  !!  Can't be used to modify the value of an element. !!
			** Better be using and iterator.

			** For the default allocator is a const pointer to value_type
			** (const value_type*)
			*/
			typedef typename allocator_type::const_pointer      const_pointer;

			/*
			** A random access iterator to value_type
			** That can read or modify any element stored.
			** !! Works like standard pointers !!
			** Convertible to const_iterator;
			*/
			typedef ft::random_access_iterator<value_type>               iterator;

			/*
			** A random access iterator to const value_type
			** That can read element stored.
			*/
			typedef ft::random_access_iterator<const value_type>            const_iterator;

			/*
			** ft::reverse_iterator<iterator>
			** That can read or modify any element in a reversed vector.
			** Iterate in reverse.
			** !! Works like standard pointers !!
			*/
			typedef ft::reverse_iterator<iterator>             reverse_iterator;

			/*
			** ft::reverse_iterator<const_iterator>
			** That can read any element in a reversed the vector.
			*/
			typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

			/*
			** A signed integral type.
			** Usually the same as ptrdiff_t.
			** Can represent the difference between iterators to the
			** element actually stored.
			** "The number of elements between two iterators."
			*/
			typedef typename ft::iterator_traits<iterator>::difference_type    difference_type;

			/*
			** An unsigned integral type that can represent any
			** non-negative value of difference_type
			** Usually the same as size_t.
			** = number of elements
			*/
			typedef typename allocator_type::size_type          size_type;


			/************************************************************
			 * 				CONSTRUCTEURS/DESTRUCTOR					*
			 ************************************************************/

			/*
			** DEFAULT CONSTRUCTOR
			** Constructs an empty container, with no elements.
			*/
			explicit vector (const allocator_type& alloc = allocator_type());
			/*
			** FILL CONSTRUCTOR
			** Constructs a container with n elements.
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
			/*
			** RANGE CONSTRUCTOR
			** Constructs a container with as many elements as the range
			** from first to last, with each element constructed from its
			*/
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
			/*
			** COPY CONSTRUCTOR
			** Constructs a container with a copy of each of the elements
			*/
			vector (const vector& x);
			/*
			** Destructor
			** Destroys the container object.
			*/
			~vector();

			/*
			** Overload of the assignement operator
			** Assigns new contents to the container, replacing its current
			** contents, and modifying its size accordingly.
			*/
			vector& operator= (const vector& x);

			allocator_type	get_allocator(void) const
			{
				return (allocator_type);
			}
			/************************************************************
			 * 					      ITERATORS		   		 		    *
			 ************************************************************/
			//Returns an iterator pointing to the first element in the vector.
			iterator begin();
			//Returns a const_iterator pointing to the first element in the vector.
			const_iterator begin() const;
			// Returns an iterator referring to the past-the-end element in the vector container.
			iterator end();
			// Returns a const_iterator referring to the past-the-end element in the vector container.
			const_iterator end() const;
			// Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
			reverse_iterator rbegin();
			// Returns a const_reverse_iterator pointing to the last element in the vector (i.e., its reverse beginning).
			const_reverse_iterator rbegin() const;
			// Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
			// (which is considered its reverse end).
			reverse_iterator rend();
			// Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the vector
			const_reverse_iterator rend() const;


			/************************************************************
			 * 					      CAPACITY		   		 		    *
			 ************************************************************/

			// Returns the number of elements in the vector.
			size_type size() const;
			// Returns the maximum number of elements that the vector can hold.
			size_type max_size() const;
			// Returns the number of elements the storage space currently allocated for the vector
			size_type capacity() const;
			// Returns whether the vector is empty (i.e. whether its size is 0).
			bool empty() const;
			// Requests that the vector capacity be at least enough to contain n elements.
			void reserve (size_type n);
			// Resizes the container so that it contains n elements.
			void resize (size_type n, value_type val = value_type());

			/************************************************************
			 * 					  Element access	   		 		    *
			 ************************************************************/

			// Returns a reference to the element at position n in the vector container.
			reference operator[] (size_type n);
			// Returns a const_reference to the element at position n in the vector container.
			const_reference operator[] (size_type n) const;
			// Returns a reference to the element at position n in the vector.
			// Checks if out of range
			reference at (size_type n);
			// Returns a const_reference to the element at position n in the vector.
			// Checks too
			const_reference at (size_type n) const;
			// Returns a reference to the first element in the vector.
			reference front();
			// Returns a const_reference to the first element in the vector.
			const_reference front() const;
			// Returns a reference to the last element in the vector.
			reference back();
			// Returns a const_reference to the last element in the vector.
			const_reference back() const;
			// Returns a pointer to the first element in the vector.
			value_type* data() noexcept;
			// Returns a pointer to the first element in the vector.
			const value_type* data() const noexcept;


			/************************************************************
			 * 						  Modifiers	   		 		 	    *
			 ************************************************************/

			// Assigns new contents to the container, replacing its current contents,
			// and modifying its size accordingly. In the range between first and last
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);

			// Assigns new contents to the container, replacing its current contents,
			// the new contents are n elements, each initialized to a copy of val.
			void assign (size_type n, const value_type& val);

			// Adds a new element at the end of the vector, after its current last element.
			void push_back (const value_type& val);
			// Removes the last element in the vector, effectively reducing the container size by one.
			void pop_back();
			// single element (1)
			iterator insert (iterator position, const value_type& val);
			// fill (2)
			void insert (iterator position, size_type n, const value_type& val)
			// range (3)
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr);
			// Removes from the vector either a single element (position)
			iterator erase (iterator position);
			// or a range of elements ([first,last)).
			iterator erase (iterator first, iterator last);
			// Exchanges the content of the container by the content of x, which is another vector object of the same type.
			// size may differ
			void swap (vector& x);
			// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			void clear();
	};

			/************************************************************
			 * 				Non-member function overloads	   	 	    *
			 ************************************************************/
	// Relational operators
	// Compares whether the contents of lhs are equal to the contents of rhs.
	// lefhandside is compared to the righthandside
	template <class T, class Alloc>
		bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

	template <class T, class Alloc>
		bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
	// The contents of container x are exchanged with those of y.
	// Both container objects must be of the same type (same template parameters), although sizes may differ.
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>&y);
}

#endif
