/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:13 by abensett          #+#    #+#             */
/*   Updated: 2022/10/06 12:24:01 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include <limits>
#include <iostream>

#include "utils.hpp"
#include "RedBlackTree.hpp"
#include "MapIterator.hpp"

// https://cplusplus.com/reference/map/map/

namespace ft
{

	// Map class
	// std::less<key> is to  strict total order <
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
		class map
		{
			/************************************************************
			 * 						MEMBER TYPES						*
			 ************************************************************/
			public:

				typedef Key														key_type;
				typedef T														mapped_type;
				typedef ft::pair<const Key, T>									value_type;
				typedef std::size_t												size_type;
				typedef std::ptrdiff_t											difference_type;
				typedef Compare													key_compare;
				typedef Allocator												allocator_type;
				typedef T &														reference;
				typedef const T &												const_reference;
				typedef T *														pointer;
				typedef const pointer											const_pointer;
				typedef ft::MapIterator<value_type>								iterator;
				typedef ft::MapIterator<value_type>								const_iterator;
				typedef ft::reverse_iterator<iterator>							reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			// MEMBER OBJECTS
			private:
				key_compare														_key_compare;
				RedBlackTree<Key, T, Compare, Allocator>						_tree;
				allocator_type													_alloc;

			/************************************************************
			 * 				  NESTED VALUE COMPARE CLASS			 	*
			 ************************************************************/
			public :

				class value_compare
				{
					friend class map;

					// Public member types and function
					public :

						typedef bool											result_type;
						typedef value_type										first_argument_type;
						typedef value_type										second_argument_type;

						result_type operator () (const value_type & lhs, const value_type & rhs) const
						{
							return (comp(lhs.first, rhs.first));
						};
					// Protected member objects and functions
					protected :

						key_compare												comp;
						value_compare(key_compare c) :
							 comp(c){};

				 };

			/************************************************************
			 * 				CONSTRUCTEURS/DESTRUCTOR					*
			 ************************************************************/
			public:
				// DEFAULT CONSTRUCTOR
				explicit map(const Compare & comp = key_compare(), const Allocator & alloc = allocator_type()) :
					 	_key_compare(comp), _tree(), _alloc(alloc)
				{	};
				// RANGE CONSTRUCTOR
				template<class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
					_key_compare(comp), _tree(), _alloc(alloc)
				{insert(first, last);};

				// COPY CONSTRUCTOR
				map(const map & x)
				{
					*this = x;
					return ;
				};

				// OPERATOR =
				map& operator = (const map & x)
				{
					if (this == &x)
						return (*this);
					_tree = x._tree;
					_alloc = x._alloc;
					_key_compare = x._key_compare;
					return (*this);
				};

				// return the allocator
				allocator_type get_allocator(void) const
				{
					return (_alloc);
				};

				// DESTRUCTOR
				~map(void){};

			/************************************************************
			 * 						ITERATORS							*
			 ************************************************************/
				// BEGIN
				iterator begin(void)
				{
					return (iterator(_tree.begin()));
				};

				// CONST BEGIN
				const_iterator begin(void) const
				{
					return (const_iterator(_tree.begin()));
				};

				// END
				iterator end(void)
				{
					return (iterator(_tree.end()));
				};

				// CONST END
				const_iterator end(void) const
				{
					return (const_iterator(_tree.end()));
				};

				// REVERSE BEGIN
				reverse_iterator rbegin(void)
				{
					return (reverse_iterator(_tree.end()));
				};

				// CONST REVERSE BEGIN
				const_reverse_iterator rbegin(void) const
				{
					return (reverse_iterator(_tree.end()));
				};

				// REVERSE END
				reverse_iterator rend(void)
				{
					return (reverse_iterator(_tree.begin()));
				};

				// CONST REVERSE END
				const_reverse_iterator rend(void) const
				{
					return (reverse_iterator(_tree.begin()));
				};
				/************************************************************
				 * 						CAPACITY							*
				 ************************************************************/
				bool empty(void) const
				{
					return (_tree.size() == 0);
				};
				size_type size(void) const
				{
					return (_tree.size());
				};
				size_type max_size(void) const
				{
					return (_tree.max_size());
				};

				/************************************************************
				 * 						ELEMENT ACCESS						*
				 ************************************************************/
				// return a reference to the mapped value of the element identified with key k
				mapped_type & operator [] (const key_type& key)
				{
					return (insert(ft::pair<Key, mapped_type>(key, _tree.find(key)->data->second)).first->second);
				};

				/************************************************************
				 * 						MODIFIERS							*
				 ************************************************************/

				// erase all elements and set size to 0
				void clear(void)
				{ _tree.clear();	};

				// insert single element
				ft::pair<iterator, bool> insert(const value_type& val)
				{
					return (_tree.insert(val));
				};
				// insert with hint
				iterator insert(iterator hint, const value_type& val)
				{
					(void)hint;
					return (_tree.insert(val).first);
				};

				// insert a range of elements
				template<class InputIterator>
					void insert(InputIterator first, InputIterator last)
					{
						while (first != last)
						{
							_tree.insert(value_type(first->first, first->second));
							++first;
						}
						return ;
					};

				// erase single element at position
				void erase(iterator pos)
				{
					_tree.erase(pos->first);
					return ;
				};

				//  removes the elements of a range
				void erase(iterator first, iterator last)
				{
					map	cpy(first, last);

					for (iterator it = cpy.begin() ; it != cpy.end() ; ++it)
					{
						erase(it->first);
					}
				};

				// remove element with a specific key (if it exists)
				size_type erase(const key_type& key)
				{
					return (_tree.erase(key));
				};

				// exchange the contents of the container by those of x
				void swap(map& other)
				{
					_tree.swap(other._tree);
					std::swap(_alloc, other._alloc);
					std::swap(_key_compare, other._key_compare);
				};

				/************************************************************
				 * 						LOOKUP								*
				 ************************************************************/

				//  find element with specific key
				iterator find(const key_type& key)
				{ return (iterator(_tree.find(key)));};

				// find element with specific key (const version)
				const_iterator find(const key_type& key) const
				{ return (const_iterator(_tree.find(key))); };

				// returns the number of elements matching specific key  (0 or 1)
				size_type count(const key_type& key) const
				{
					if (_tree.find(key) != _tree.end())
						return (1);
					return (0);
				};

				// returns an iterator to the first element that is not considered to go before key
				iterator lower_bound(const key_type& key)
				{
					 iterator	it;
					 iterator	ite;

					 ite = end();
					 it = begin();
					 while (it != ite)
					 {
						 if (key_comp()(it->first, key) == false)
							 return (it);
						 ++it;
					 }
					 return (ite);
				};

				// returns an iterator to the first element that is considered to go after key
				const_iterator lower_bound(const key_type& key) const
				{
					 const_iterator	it = begin();
					 const_iterator	ite = end();

					 while (it != ite)
					 {
						 if (key_comp()(it->first, key) == false)
							 return (it);
						 ++it;
					 }
					 return (ite);
				};

				// returns an iterator to the first element that is considered to go after key
				iterator upper_bound(const key_type& key)
				{
					 iterator	it;
					 iterator	ite;

					 ite = end();
					 it = begin();
					 while (it != ite)
					 {
						 if (key_comp()(key, it->first) == true)
							 return (it);
						 ++it;
					 }
					 return (ite);
				};

				// const version of upper_bound
				const_iterator upper_bound(const key_type& key) const
				{
					 const_iterator	it = begin();
					 const_iterator	ite = end();

					 while (it != ite)
					 {
						 if (key_comp()(key, it->first) == true)
							 return (it);
						 ++it;
					 }
					 return (ite);
				};

				// returns a range containing all elements matching a specific key, the range is defined by two iterators
				// first element is not less than key, second element is greater than key
				ft::pair<iterator, iterator> equal_range(const key_type& key)
				{
					return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
				};


				// CONST EQUAL RANGE
				ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
				{ 	return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));};

				/************************************************************
				 * 						OBSERVERS							*
				 ************************************************************/

				// return the key comparison object
				key_compare key_comp(void) const {return (_key_compare);};
				// return the comparison object used by the container to compare keys
				value_compare value_comp(void) const {return (value_compare(Compare()));
				};



		};
		// end of map

				/************************************************************
				* 				Non-member function overloads	   	 	    *
				************************************************************/

			// RELATIONAL OPERATORS
			template< class Key, class T, class Compare, class Alloc >
				bool operator == (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					if (!(lhs.size() == rhs.size()))
						return (false);
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				};

			template< class Key, class T, class Compare, class Alloc >
				bool operator != (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					return (!(lhs == rhs));
				};

			template< class Key, class T, class Compare, class Alloc >
				bool operator < (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
				};

			template< class Key, class T, class Compare, class Alloc >
				bool operator <= (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					return !(rhs < lhs);
				};

			template< class Key, class T, class Compare, class Alloc >
				bool operator > (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					return (rhs < lhs);
				};

			template< class Key, class T, class Compare, class Alloc >
				bool operator >= (const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
				{
					return !(lhs < rhs);
				};

			// SWAP
			template< class Key, class T, class Compare, class Alloc >
				void swap(ft::map<Key, T, Compare, Alloc> & lhs, ft::map<Key, T, Compare, Alloc> & rhs)
				{
					lhs.swap(rhs);
				};

}

#endif
