/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:13 by abensett          #+#    #+#             */
/*   Updated: 2022/10/02 18:20:15 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include <memory>
#include <stdexcept>
#include <limits>
#include <iostream>
// https://cplusplus.com/reference/map/map/

namespace ft
{

	// Map class
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, Value> > >
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
				typedef ft::MapIterator<Key, Value, value_type*>				iterator;
				typedef ft::ConstMapIterator<Key, Value, const value_type*>		const_iterator;
				typedef ft::reverse_iterator<iterator>							reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			// MEMBER OBJECTS
			private:
				key_compare														_key_compare;
				red_black_tree<Key, Value, Compare, Allocator>					_tree;
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

			// MEMBER FUNCTIONS
			public:

				// DEFAULT CONSTRUCTOR
				explicit map(const Compare & comp = key_compare(), const Allocator & alloc = allocator_type()) :
					_tree(),
					_key_compare(comp),
					_alloc(alloc)
				{
					return ;
				};

				// RANGE CONSTRUCTOR
				template<class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
						_tree(),
						_key_compare(comp),
						_alloc(alloc)
				{
					insert(first, last);
					return ;
				};

				// COPY CONSTRUCTOR
				map(const map & other)
				{
					*this = other;
					return ;
				};

				// OPERATOR =
				map& operator = (const map & other)
				{
					if (this == &other)
						return (*this);
					_tree = other._tree;
					_alloc = other._alloc;
					_key_compare = other._key_compare;
					return (*this);
				};

				// DESTRUCTOR
				~map(void)
				{
					return ;
				};

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

				// EMPTY
				bool empty(void) const
				{
					return (_tree.size() == 0);
				};

				// SIZE
				size_type size(void) const
				{
					return (_tree.size());
				};

				// MAX SIZE
				size_type max_size(void) const
				{
					return (_tree.max_size());
				};

				// OPERATOR []
				mapped_type & operator [] (const key_type& key)
				{
					return (insert(ft::pair<Key, mapped_type>(key, _tree.find(key)->data->second)).first->second);
				};

				// INSERT VALUE
				ft::pair<iterator, bool> insert(const value_type& val)
				{
					return (_tree.insert(val));
				};

				// INSERT VALUE
				iterator insert(iterator hint, const value_type& val)
				{
					(void)hint;
					return (_tree.insert(val).first);
				};

				// INSERT BY RANGE
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

				// ERASE POS
				void erase(iterator pos)
				{
					_tree.erase(pos->first);
					return ;
				};

				// ERASE RANGE
				void erase(iterator first, iterator last)
				{
					map	cpy(first, last);

					for (iterator it = cpy.begin() ; it != cpy.end() ; ++it)
					{
						erase(it->first);
					}
				};

				// ERASE KEY
				size_type erase(const key_type& key)
				{
					return (_tree.erase(key));
				};

				// SWAP
				void swap(map& other)
				{
					_tree.swap(other._tree);
					std::swap(_alloc, other._alloc);
					std::swap(_key_compare, other._key_compare);
					return ;
				};

				// CLEAR
				void clear(void)
				{
					_tree.clear();
					return ;
				};

				// KEY COMP
				key_compare key_comp(void) const
				{
					return (_key_compare);
				};

				// VALUE COMP
				value_compare value_comp(void) const
				{
					return (value_compare(Compare()));
				};

				// FIND
				iterator find(const key_type& key)
				{
					return (iterator(_tree.find(key)));
				};

				// FIND CONST
				const_iterator find(const key_type& key) const
				{
					return (const_iterator(_tree.find(key)));
				};

				// COUNT
				size_type count(const key_type& key) const
				{
					if (_tree.find(key) != _tree.end())
						return (1);
					return (0);
				};

				// LOWER BOUND
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

				// CONST LOWER BOUND
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

				// UPPER BOUND
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

				// CONST UPPER BOUND
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

				// EQUAL RANGE
				ft::pair<iterator, iterator> equal_range(const key_type& key)
				{
					return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
				};

				// CONST EQUAL RANGE
				ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
				{
					return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
				};

				// GET_ALLOCATOR
				allocator_type get_allocator(void) const
				{
					return (_alloc);
				};


		}; // END OF CLASS MAP


		// NON-MEMBER FUNCTIONS

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
