/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstConstMapIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/10/06 11:58:32 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTMAPRITERATOR_HPP
#define CONSTMAPITERATOR_HPP

#include "utils.hpp"
#include "VectorIterator.hpp"

namespace ft
{

	// Iterator Map = random access iterator
	// template <class T>
	// class ConstConstMapIterator;
	template < typename T >
	class ConstConstMapIterator
	{
				public:
			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, T> >		traits;			// specify the iterator traits
			typedef typename traits::value_type												value_type;
			typedef	typename traits::difference_type										difference_type;
			typedef	typename traits::pointer												pointer;
			typedef	typename traits::reference												reference;
			typedef	typename traits::iterator_category										iterator_category;

			// Constructors
			ConstMapIterator() : _ptr(NULL) {};
			// Copy, constructor from pointer
			ConstMapIterator(pointer ptr) : _ptr(ptr) {};
			// destructor
			~ConstMapIterator() {};
			// Operators
			// assignation operator
			ConstMapIterator operator=( const ConstMapIterator &rhs)
			{
				// protection de l'autodéfinition
				if (*this != rhs)
					this->_ptr = rhs._ptr;
				return (*this);
			}
			// comparison operators
			bool operator==(const ConstMapIterator &rhs) const { return (_ptr == rhs._ptr); };
			bool operator!=(const ConstMapIterator &rhs) const { return (_ptr != rhs._ptr); };
			// rvalue dereferencing operator
			reference operator*() const { return (*(_ptr->data)); };
			// pointer dereferencing operator
			pointer operator->() const { return (_ptr->data); };
			// lvalue pointer dereferencing operator
			pointer operator&() const { return (_ptr); };
			// incrementation operator iterator++
			ConstMapIterator &operator++() { _ptr = next(_ptr); return (*this); };
			// post-incrementation operator ++iterator
			ConstMapIterator operator++(int) {
				ConstMapIterator tmp(*this);
				_ptr = next(_ptr);
				return (tmp); };
			// decrementation operator iterator--
			ConstMapIterator &operator--() { _ptr = prev(_ptr); return (_ptr); };
			// post-decrementation operator --iterator
			ConstMapIterator operator--(int) 
			{
				ConstMapIterator tmp(*this);
				_ptr = prev(_ptr);
				return (tmp); 
			};
			
		private:	
				// find last node of the branch
				Node* maximum(Node* Node)
				{
					while (Node->right->color != NIL)
						Node = Node->right;
					return (Node);
				};
				
				// find first node of the branch
				Node* minimum(Node* Node)
				{
					while (Node->left->color != NIL) 
						Node = Node->left;
					return (Node);
				};

				// return the previous node in the tree and check if it's a NIL node 
				Node* prev(Node* Node)
				{
					if (Node->color == NIL)
						return (Node->parent);
					if (Node->color != NIL && Node->left->color != NIL)
						return (maximum(Node->left));
					Node* _ptr = Node->parent;
					while (_ptr->color != NIL && Node == _ptr->left)
					{
						Node = _ptr;
						_ptr = _ptr->parent;
					}
					if (_ptr->color != NIL)
						return (_ptr);
					return (Node);
				};
				
				// return the next node in the tree and check if it's the end of the tree
				Node* next(Node* Node)
				{
					if (Node->color == NIL)
						return (Node);
					if (Node->right->color != NIL)
						return (minimum(Node->right));
					Node* _ptr = Node->parent;
					while (_ptr->color != NIL && Node == _ptr->right)
					{
						Node = _ptr;
						_ptr = _ptr->parent;
					}
					return (_ptr);
				};
				// pointer to the current element
				pointer 															_ptr;

	};

};
// End of namespace FT
#endif
