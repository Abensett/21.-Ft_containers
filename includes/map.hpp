/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:13 by abensett          #+#    #+#             */
/*   Updated: 2022/10/27 19:59:05 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include <limits>
#include <iostream>

#include "utils.hpp"

// https://cplusplus.com/reference/map/map/

# ifndef RED
#  define RED true
# endif
# ifndef BLACK
#  define BLACK false
# endif

namespace ft
{


	template <class T>
	void swap (T & a, T & b)
	{
		T	tmp(a);
		a = b;
		b = tmp;
	}
	template <class T, class U>
	struct same_type { static const bool value = false; };

	template <class T>
	struct same_type<T, T> { static const bool value = true; };


	template <bool B, class T = void, class U = void>
	struct whichtype {};

	template <class T, class U>
	struct whichtype<true, T, U> { typedef T type; };

	template <class T, class U>
	struct whichtype<false, T, U> { typedef U type; };



template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
class map {
public:

	/* ****************************************************************************
	* ------------------------------- RBNode Class -------------------------------*
	* 					P														  *
	*		RBN a Node is a struct with :								   		  *
	*		a value, a color, a parent, a left child and a right child			  *
	*******************************************************************************/

	typedef struct				s_node
	{
		ft::pair<const Key, T>	data;
		struct s_node *			left;
		struct s_node *			right;
		struct s_node *			parent;
		bool					color;


		s_node (ft::pair<const Key, T> data) : data(data) {}
		const Key &	key (void)	{ return (data.first); }
		T &			val (void)	{ return (data.second); }
	}							node;



	template <bool checkconst>
	class mapIterator {
	public:
		typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, T> >		traits;			// specify the iterator traits
		typedef	typename traits::pointer													pointer;
		typedef	typename traits::reference													reference;
		typedef	typename traits::iterator_category											iterator_category;
		typedef					ft::pair<const Key, T>										pair_type;
		typedef typename		ft::whichtype<checkconst, const pair_type, pair_type>::type	value_type;
		typedef typename		ft::whichtype<checkconst, const node, node>::type			node_type;
		typedef					std::ptrdiff_t												difference_type;
		typedef					std::size_t													size_type;
		mapIterator				(void)														{ _ptr = NULL; }
		mapIterator				(node_type * const ptr)										{ _ptr = ptr; }
		~mapIterator			(void)													{}

		template <bool B>		mapIterator
			(const mapIterator<B> & x, typename ft::enable_if<!B>::type* = 0)				{ _ptr = x.getPtr(); }

		mapIterator &			operator=	(const mapIterator & x)							{ _ptr = x.getPtr(); return (*this); }
		template <bool B> bool	operator==	(const mapIterator<B> & x) const				{ return (_ptr == x.getPtr()); }
		template <bool B> bool	operator!=	(const mapIterator<B> & x) const				{ return (_ptr != x.getPtr()); }
		mapIterator &			operator++	(void)											{ this->nextNode(); return (*this); }
		mapIterator &			operator--	(void)											{ this->prevNode(); return (*this); }
		mapIterator				operator++	(int)											{ mapIterator<checkconst> x(*this); this->nextNode(); return (x); }
		mapIterator				operator--	(int)											{ mapIterator<checkconst> x(*this); this->prevNode(); return (x); }
		value_type &			operator*	(void) const									{ return (_ptr->data); }
		value_type *			operator->	(void) const									{ return (&_ptr->data); }
		node_type *				getPtr		(void) const									{ return (_ptr); }

	private:
		node_type *				_ptr;

		// find the next node in the tree (in-order) which is the smallest node greater than the current node
		void nextNode (void)
		{
			if (_ptr->right != _ptr->right->left)
			{
				_ptr = _ptr->right;
				while (_ptr->left != _ptr->left->left)
					_ptr = _ptr->left;
			}
			else
			{
				while (_ptr == _ptr->parent->right && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}

		// find the previous node in the tree (in-order) which is the largest node smaller than the current node
		void prevNode (void)
		{
			if (_ptr == _ptr->parent)
			{
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			else if (_ptr->left != _ptr->left->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			else
			{
				while (_ptr == _ptr->parent->left && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}
	}; // Iterator

	/************************************************************
	* 						MEMBER TYPES						*
	************************************************************/

	class		ValueCompare;

	typedef		Key												key_type;
	typedef		T												mapped_type;
	typedef		ft::pair<const key_type, mapped_type>			value_type;
	typedef		Compare											key_compare;
	typedef		ValueCompare									value_compare;
	typedef		typename Alloc::template rebind<node>::other	allocator_type;
	typedef		typename allocator_type::reference				reference;
	typedef		typename allocator_type::const_reference		const_reference;
	typedef		typename allocator_type::pointer				pointer;
	typedef		typename allocator_type::const_pointer			const_pointer;
	typedef		mapIterator<false>								iterator;
	typedef		mapIterator<true>								const_iterator;
	typedef		ft::reverse_iteratormap<iterator>					reverse_iterator;
	typedef		ft::reverse_iteratormap<const_iterator>			const_reverse_iterator;
	typedef		typename mapIterator<false>::difference_type	difference_type;
	typedef		typename mapIterator<false>::size_type			size_type;

	// nested class for comparing values (used in lower_bound, upper_bound, equal_range) - compares keys of values

	class ValueCompare {
	public:
		friend			class			map;
		typedef			bool			result_type;
		typedef			value_type		first_argument_type;
		typedef			value_type		second_argument_type;
		bool			operator()		(const value_type & x, const value_type & y) const
			{ return (comp(x.first, y.first)); }
	protected:
		ValueCompare	(Compare c)		: comp(c) {}
		Compare			comp;
	};

	/************************************************************
	 * 				CONSTRUCTEURS/DESTRUCTOR					*
	************************************************************/

	explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
	{
		_alloc = alloc;
		_comp = comp;
		this->_new_nil_node();
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(),
	typename ft::enable_if<!ft::same_type<InputIterator, int>::value>::type* = 0)
	{
		_alloc = alloc;
		_comp = comp;
		this->_new_nil_node();

		while (first != last)
			this->insert(*first++);
	}

	map (const map & x)
	{
		this->_new_nil_node();
		*this = x;
	}


	~map (void)
	{
		this->clear();
		_alloc.destroy(_nil);
		_alloc.deallocate(_nil, 1);
	}

	map & operator= (const map & x)
	{
		if (this == &x)
			return (*this);

		this->clear();
		_alloc = x._alloc;
		_comp = x._comp;

		for (const_iterator it = x.begin() ; it != x.end() ; it++)
			this->insert(*it);
		return (*this);
	}

	/************************************************************
	 * 					      ITERATORS		   		 		    *
	 ************************************************************/
	iterator begin (void)
	{
		return (iterator(this->_find_min(_nil->right)));
	}

	const_iterator begin (void) const
	{
		return (const_iterator(this->_find_min(_nil->right)));
	}

	iterator end (void)
	{
		return (iterator(_nil));
	}

	const_iterator end (void) const
	{
		return (const_iterator(_nil));
	}

	reverse_iterator rbegin (void)
	{
		return (reverse_iterator(_nil));
	}

	const_reverse_iterator rbegin (void) const
	{
		return (const_reverse_iterator(_nil));
	}

	reverse_iterator rend (void)
	{
		return (reverse_iterator(this->_find_min(_nil->right)));
	}

	const_reverse_iterator rend (void) const
	{
		return (const_reverse_iterator(this->_find_min(_nil->right)));
	}

	/************************************************************
	 * 					      CAPACITY		   		 		    *
	 ************************************************************/
	bool empty (void) const
	{
		return (_nil == _nil->right);
	}

	size_type size (void) const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
			n++;
		return (n);
	}

	size_type max_size (void) const
	{
		return (_alloc.max_size());
	}

	/************************************************************
	 * 					      ELEMENT ACCESS		   		 	*
	 ************************************************************/

	mapped_type & operator[] (const key_type & k)
	{
		this->insert(ft::make_pair(k, mapped_type()));
		return (this->find(k)->second);
	}

	/************************************************************
	 * 					      MODIFIERS		   		 	    *
	 ************************************************************/

	ft::pair<iterator,bool> insert (const value_type & val)
	{
		iterator it;
		if (this->count(val.first))
		{
			it = this->find(val.first);
			return (ft::make_pair(it, false));
		}
		else
		{
			it = iterator(this->_new_node(val));
			return (ft::make_pair(it, true));
		}
	}

	iterator insert (iterator position, const value_type & val)
	{
		(void)position;
		return (this->insert(val).first);
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::same_type<InputIterator, int>::value>::type* = 0)
	{
		while (first != last)
			this->insert(*first++);
	}

	void erase (iterator position)
	{
		node * ptr = position.getPtr();

		if (ptr->left != _nil && ptr->right != _nil)
		{
			position--;
			this->_swap_nodes(ptr, position.getPtr());
			this->erase(ptr);
		}
		else
		{
			node * child = (ptr->left != _nil) ? ptr->left : ptr->right;

			if (child != _nil)
				child->parent = ptr->parent;
			if (ptr->parent->left == ptr)
				ptr->parent->left = child;
			else
				ptr->parent->right = child;

			this->_remove_node(ptr, child);
		}
	}

	size_type erase (const key_type & k)
	{
		if (this->count(k))
		{
			this->erase(this->find(k));
			return (1);
		}
		return (0);
	}

	void erase (iterator first, iterator last)
	{
		for (iterator it = first++ ; it != last ; it = first++)
			this->erase(it);
	}

	void swap (map & x)
	{
		ft::swap(_alloc, x._alloc);
		ft::swap(_comp, x._comp);
		ft::swap(_nil, x._nil);
	}

	void clear (void)
	{
		iterator first = this->begin();
		for (iterator it = first++ ; it != this->end() ; it = first++)
			this->erase(it);
	}

	/************************************************************
	 * 					      OBSERVERS		   		 	    *
	 ************************************************************/
	key_compare key_comp (void) const
	{
		return (key_compare());
	}

	value_compare value_comp (void) const
	{
		return (value_compare(_comp));
	}

	/************************************************************
	 * 					      OPERATIONS		   		 	    *
	 ************************************************************/

	iterator find (const key_type & k)
	{
		if (this->count(k))
			return (iterator(this->_find_node(_nil->right, k)));
		else
			return (this->end());
	}

	const_iterator find (const key_type & k) const
	{
		if (this->count(k))
			return (const_iterator(this->_find_node(_nil->right, k)));
		else
			return (this->end());
	}

	size_type count (const key_type & k) const
	{
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
		{
			if (this->_equal(k, it->first))
				n++;
		}
		return (n);
	}



	iterator lower_bound (const key_type & k)
	{
		iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	}

	const_iterator lower_bound (const key_type & k) const
	{
		const_iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	}

	iterator upper_bound (const key_type & k)
	{
		iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}

	const_iterator upper_bound (const key_type & k) const
	{
		const_iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}

	ft::pair<iterator,iterator> equal_range (const key_type & k)
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

	ft::pair<const_iterator,const_iterator> equal_range (const key_type & k) const
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

	allocator_type get_allocator (void) const
	{
		return (allocator_type());
	}

	/************************************************************
	 * 				 PRIVATE  HELPING FUNCTIONS		   		     *
	 ************************************************************/

private:
	// create a new nil node with the given value
	void _new_nil_node (void)
	{
		_nil = _alloc.allocate(1);
		this->_construct(_nil);
		_nil->color = BLACK;
	}

	// create a new node
	node * _new_node (const value_type & val = value_type())
	{
		node * new_node = _alloc.allocate(1);
		this->_construct(new_node, val);

		node * parent = this->_find_parent(_nil->right, val.first);
		if (parent == _nil || !this->_comp(val.first, parent->key()))
			parent->right = new_node;
		else
			parent->left = new_node;
		new_node->parent = parent;

		this->_insert_in_RB(new_node);

		return (new_node);
	}

	// create a new node with the given value
	void _construct (node * ptr, const value_type & val = value_type())
	{
		node tmp(val);
		tmp.left = _nil;
		tmp.right = _nil;
		tmp.parent = _nil;
		tmp.color = RED;
		_alloc.construct(ptr, tmp);
	}

	// swap two nodes
	void _swap_nodes (node * a, node * b)
	{
		if (a->left != b && a->left != _nil)
			a->left->parent = b;
		if (a->right != b && a->right != _nil)
			a->right->parent = b;
		if (a->parent != b && a->parent != _nil)
		{
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}

		if (b->left != a && b->left != _nil)
			b->left->parent = a;
		if (b->right != a && b->right != _nil)
			b->right->parent = a;
		if (b->parent != a && b->parent != _nil)
		{
			if (b->parent->left == b)
				b->parent->left = a;
			else
				b->parent->right = a;
		}

		if (a->parent == b)
			a->parent = a;
		if (a->left == b)
			a->left = a;
		if (a->right == b)
			a->right = a;
		if (b->parent == a)
			b->parent = b;
		if (b->left == a)
			b->left = b;
		if (b->right == a)
			b->right = b;

		ft::swap(a->parent, b->parent);
		ft::swap(a->left, b->left);
		ft::swap(a->right, b->right);
		ft::swap(a->color, b->color);

		if (_nil->right == a)
			_nil->right = b;
		else if (_nil->right == b)
			_nil->right = a;
	}

	// delete a node
	void _remove_node (node * ptr, node * child)
	{
		this->_delete_from_RB(ptr, child);

		_alloc.destroy(ptr);
		_alloc.deallocate(ptr, 1);
	}

	// find the node with the given key
	node * _find_node (node * current, const key_type & k) const
	{
		if (current == _nil || this->_equal(current->key(), k))
			return (current);
		else if (this->_comp(k, current->key()))
			return (this->_find_node(current->left, k));
		else
			return (this->_find_node(current->right, k));
	}

	// find the parent of the node with the given key
	node * _find_parent (node * current, const key_type & k) const
	{
		if (!this->_comp(k, current->key()))
		{
			if (current->right == _nil)
				return (current);
			else
				return (this->_find_parent(current->right, k));
		}
		else
		{
			if (current->left == _nil)
				return (current);
			else
				return (this->_find_parent(current->left, k));
		}
	}

	// find the minimum node in the tree
	node * _find_min (node * root) const
	{
		while (root->left != root->left->left)
			root = root->left;
		return (root);
	}

	// find the maximum node in the tree
	bool _equal (const key_type & lhs, const key_type & rhs) const
	{
		return (this->_comp(lhs, rhs) == false && this->_comp(rhs, lhs) == false);
	}
	/************************************************************
	 * 				 PREDBLACK TREE FUNCTIONS		   		     *
	 ************************************************************/
	/******************************************************************************
	A Red Black Tree is a Binary Search Tree with the following 4 properties:
	1. Every Node is either red or black
	2. The root is black and Every leaf (NULL) is black
	3. If a Node is red, then both its children are black
	4. Every simple path from a Node to a descendant leaf contains the same number of black Nodes
	******************************************************************************/

	// fix the tree after insertion
	void _insert_in_RB (node * x)
	{
		node * parent = x->parent;
		node * grandparent = parent->parent;
		node * uncle = (grandparent->right == parent) ? grandparent->left : grandparent->right;

		if (parent == _nil)
			x->color = BLACK;
		else if (parent->color == BLACK)
			return ;
		else if (uncle->color == RED)
		{
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			this->_insert_in_RB(grandparent);
		}
		else if (uncle->color == BLACK)
		{
			if (grandparent->left->left == x || grandparent->right->right == x)
			{
				if (grandparent->left->left == x)
					this-> _left_rotation(grandparent, parent);
				else if (grandparent->right->right == x)
					this->_right_rotation(grandparent, parent);
				ft::swap(grandparent->color, parent->color);
			}
			else
			{
				if (grandparent->left->right == x)
					this->_left_right_rotation(grandparent, parent, x);
				else if (grandparent->right->left == x)
					this->_right_left_rotation(grandparent, parent, x);
				ft::swap(grandparent->color, x->color);
			}
		}
	}

	// fix the tree after deletion
	void _delete_from_RB (node * v, node * u)
	{
		if (v->color == RED || u->color == RED)
			u->color = BLACK;
		else
			this->_double_black(u, v->parent);
	}

	// fix the tree after deletion
	// double black node
	void _double_black (node * u, node * parent)
	{

		node * sibling = (parent->left != u) ? parent->left : parent->right;

		// Case 1: x
		if (u == _nil->right)
			return ;
		else if (sibling->color == BLACK && (sibling->left->color == RED || sibling->right->color == RED))
		{
			if (sibling == parent->left && sibling->left->color == RED)
				this-> _left_rotation(parent, sibling);
			else if (sibling == parent->left && sibling->right->color == RED)
				this->_left_right_rotation(parent, sibling, sibling->right);
			else if (sibling == parent->right && sibling->right->color == RED)
				this->_right_rotation(parent, sibling);
			else if (sibling == parent->right && sibling->left->color == RED)
				this->_right_left_rotation(parent, sibling, sibling->left);

			if (sibling->left->color == RED)
				sibling->left->color = BLACK;
			else
				sibling->right->color = BLACK;
		}
		else if (sibling->color == BLACK)
		{
			sibling->color = RED;
			if (parent->color == RED)
				parent->color = BLACK;
			else
				this->_double_black(parent, parent->parent);
		}
		else if (sibling->color == RED)
		{
			if (sibling == parent->left)
				this-> _left_rotation(parent, sibling);
			else
				this->_right_rotation(parent, sibling);
			ft::swap(parent->color, sibling->color);
			this->_double_black(u, parent);
		}
	}

	// Left Rotation
	// make the right child of the node the new root
	// make the left child of the new root the right child of the node
	void  _left_rotation (node * grandparent, node * parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->right != _nil)
			parent->right->parent = grandparent;
		grandparent->left = parent->right;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->right = grandparent;
	}

	// Right Right Rotation
	// 1. Make the left child of the right child the parent
	// 2. Make the right child of the parent the left child of the new parent
	void _right_rotation (node * grandparent, node * parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->left != _nil)
			parent->left->parent = grandparent;
		grandparent->right = parent->left;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->left = grandparent;
	}

	// Left Right Rotation
	void _left_right_rotation (node * grandparent, node * parent, node * x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != _nil)
			x->left->parent = parent;
		if (x->right != _nil)
			x->right->parent = grandparent;
		grandparent->left = x->right;
		parent->right = x->left;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = parent;
		x->right = grandparent;
	}

	// Right Left Rotation
	void _right_left_rotation (node * grandparent, node * parent, node * x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != _nil)
			x->left->parent = grandparent;
		if (x->right != _nil)
			x->right->parent = parent;
		grandparent->right = x->left;
		parent->left = x->right;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = grandparent;
		x->right = parent;
	}


	allocator_type		_alloc;
	key_compare			_comp;
	node *				_nil;
}; // Map

	// Non-member function overloads
	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc> & x, map<Key,T,Compare,Alloc> & y)
	{
		x.swap(y);
	}

} // Namespace ft

#endif
