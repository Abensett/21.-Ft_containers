/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/10/06 13:07:52 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <string>
#include <iostream>
#include "utils.hpp"
// https://www.youtube.com/watch?v=qvZGUFHWChY
// Full explanation https://www.programiz.com/dsa/red-black-tree

namespace ft
{
	// enum for color RED = 0, BLACK = 1 and NIL = 2
	enum color  {RED, BLACK, NIL};

	/* ****************************************************************************
	* ------------------------------- RBNode Class -------------------------------*
	* 																			  *
	*		RBN a Node is a struct with :								   		  *
	*		a value, a color, a parent, a left child and a right child			  *
	*******************************************************************************/
	// nested class RBNode 
	template <typename T>
	struct Node 
	{							
		T									*value;
		color								color; 
		Node								*parent;
		Node								*left;
		Node								*right;

		// Node constructor
		Node(const T& val) : value(val), parent(nullptr), color(RED), left(nullptr), right(nullptr) {};
		// Node default constructor
		Node() : value(), parent(nullptr), color(RED), left(nullptr), right(nullptr) {};
	};
	// end of of Node class


	/******************************************************************************
	A Red Black Tree is a Binary Search Tree with the following 4 properties:
	1. Every Node is either red or black
	2. The root is black and Every leaf (NULL) is black
	3. If a Node is red, then both its children are black
	4. Every simple path from a Node to a descendant leaf contains the same number of black Nodes
	******************************************************************************/
			
	template <class Key, class T, class Compare, class Allocator >
	class RedBlackTree
	{


		public:
		// Class RedBlackTree
			typedef T																mapped_type;
			typedef Key																key_type;
			typedef Compare 														key_compare;
			typedef std::pair<const key_type, mapped_type>							node_type;
			// rebind is used to change the type of the allocator for a container of a different type 
			typedef typename Allocator::template rebind< Node <node_type> >::other 		node_alloc;
			typedef typename node_alloc::pointer										pointer;
			typedef typename node_alloc::const_pointer									const_pointer;
			typedef typename node_alloc::reference										reference;
			typedef typename node_alloc::const_reference								const_reference;
			typedef typename node_alloc::value_type										value_type;
			typedef typename node_alloc::size_type										size_type;
			typedef typename node_alloc::difference_type								difference_type;

		private:
				node_alloc															_alloc;
				key_compare															_cmp;
				pointer																_root;
				pointer																_nil; //leaf
				size_type															_size;

				// PUBLIC MEMBER FUNCTIONS
// 				public:

// 					// DEFAULT CONSTRUCTOR
// 					RedBlackTree(void) :
// 						_alloc(),
// 						_cmp(key_compare()),
// 						_root(_alloc.allocate(1)),
// 						_nil(_root),
// 						_size(0)
// 					{
// 					};

// 					// DEFAULT DESTRUCTOR
// 					~RedBlackTree(void)
// 					{
// 						clear(_root);
// 						free_Node(_nil);
// 					};

// 					// OPERATOR =
// 					RedBlackTree & operator = (const RedBlackTree & other)
// 					{
// 						if (this == &other)
// 							return (*this);
						
// 						pointer		it = other.begin();
// 						pointer		ite = other.end();
						
// 						clear();
// 						_cmp = other._cmp;
// 						while (it != ite)
// 						{
// 							insert(*it->value);
// 							it = next(it);
// 						}
// 						return (*this);
// 					};

// 					// BEGIN
// 					pointer begin(void)
// 					{
// 						return (minimum(_root));
// 					};

// 					// CONST BEGIN
// 					const pointer begin(void) const
// 					{
// 						return (minimum(_root));
// 					};

// 					// END
// 					pointer end(void)
// 					{
// 						return (_nil);
// 					};

// 					// CONST END
// 					const pointer end(void) const
// 					{
// 						return (_nil);
// 					};

// 					// SIZE
// 					size_type size(void) const
// 					{
// 						return (_size);
// 					};

// 					// MAX SIZE
// 					size_type max_size(void) const
// 					{
// 						return (_alloc.max_size());
// 					};

// 					// CLEAR
// 					void clear(void)
// 					{
// 						clear(_root);
// 						return ;
// 					};

// 					// INSERT PAIR
// 					ft::pair<pointer, bool> insert(ft::pair<key_type, mapped_type> pair)
// 					{
// 						pointer	current = _root;
// 						pointer	parent = _nil;

// 						while (current != _nil)
// 						{
// 							if (pair.first == current->value->first)
// 								return (ft::make_pair<pointer, bool>(current, false));
// 							parent = current;
// 							current = _cmp(pair.first, current->value->first) ? current->left : current->right;
// 						}

// 						pointer	new_Node = _alloc.allocate(1);

// 						_alloc.construct(new_Node, value_type(pair.first, pair.second, _nil, RED));
// 						new_Node->parent = parent;
// 						if (parent == _nil)
// 							_root = new_Node;
// 						else
// 						{
// 							if (_cmp(pair.first, parent->value->first))
// 								parent->left = new_Node;
// 							else
// 								parent->right = new_Node;
// 						}
// 						insert_fix(new_Node);
// 						_nil->parent = maximum(_root);
// 						++_size;
// 						return (ft::make_pair<pointer, bool>(new_Node, true));
// 					};

// 					// ERASE KEY
// 					bool erase(key_type key)
// 					{
// 						pointer Node = find(_root, key);

// 						if (Node == _nil)
// 							return (false);
// 						erase_Node(Node);
// 						--_size;
// 						return (true);
// 					};

// 					// SWAP
// 					void swap(RedBlackTree &other)
// 					{
// 						std::swap(_nil, other._nil);
// 						std::swap(_root, other._root);
// 						std::swap(_cmp, other._cmp);
// 						std::swap(_alloc, other._alloc);
// 						std::swap(_size, other._size);
// 					};

// 					// FIND KEY
// 					pointer find(key_type key) const
// 					{
// 						return find(_root, key);
// 					};
					
// 					// PRINT HELPER
// 					void	print(pointer Node, std::string indent, bool last)
// 					{
// 						if (Node != _nil)
// 						{
// 							std::cout << indent;
// 							if (last == true)
// 							{
// 								std::cout << "R----";
// 								indent += "     ";
// 							}
// 							else
// 							{
// 								std::cout << "L----";
// 								indent += "|    ";
// 							}
// 							if (Node->color == BLACK)
// 								std::cout << Node->value->first << " (BLACK)" << std::endl;
// 							else
// 								std::cout << Node->value->first << " (RED)" << std::endl;
// 							print(Node->left, indent, false);
// 							print(Node->right, indent, true);
// 						}
// 					};

// 					// PRINT
// 					void	print(void)
// 					{
// 						if (_root != _nil)
// 						{
// 							print(_root, "", true);
// 						}
// 					};

// 				private:

// 					// FIND HELPER
// 					pointer find(pointer Node, key_type key) const
// 					{
// 						if (Node != _nil)
// 						{
// 							if (Node->value->first == key)
// 								return Node;
// 							else if (_cmp(key, Node->value->first))
// 								return find(Node->left, key);
// 							else
// 								return find(Node->right, key);
// 						}
// 						return _nil;
// 					}

// 					// MAX
// 					pointer maximum(pointer Node) const
// 					{
// 						while (Node->color != NIL && Node->right->color != NIL)
// 						{
// 							Node = Node->right;
// 						}
// 						return (Node);
// 					}

// 					// MIN
// 					pointer minimum(pointer Node) const
// 					{
// 						while (Node->color != NIL && Node->left->color != NIL)
// 							Node = Node->left;
// 						return (Node);
// 					}

// 					// PREV
// 					pointer prev(pointer Node)
// 					{
// 						if (Node->color == NIL)
// 							return (Node->parent);
// 						else if (Node->color != NIL && Node->left->color != NIL)
// 							return (maximum(Node->left));

// 						pointer tmp = Node->parent;

// 						while (tmp->color != NIL && Node == tmp->left)
// 						{
// 							Node = tmp;
// 							tmp = tmp->parent;
// 						}
// 						if (tmp->color != NIL)
// 							return (tmp);
// 						else
// 							return (Node);
// 					}

// 					// NEXT
// 					pointer next(pointer Node)
// 					{
// 						if (Node->color == NIL)
// 							return (Node);
// 						else if (Node->right->color != NIL)
// 							return (minimum(Node->right));

// 						pointer tmp = Node->parent;

// 						while (tmp->color != NIL && Node == tmp->right)
// 						{
// 							Node = tmp;
// 							tmp = tmp->parent;
// 						}
// 						return (tmp);
// 					}

// 					// FREE
// 					void free_Node(const pointer& Node)
// 					{
// 						_alloc.destroy(Node);
// 						_alloc.deallocate(Node, 1);
// 					}

// 					// CLEAR
// 					void clear(pointer& Node)
// 					{
// 						if (Node == NULL || Node == _nil)
// 							return;

// 						clear(Node->left);
// 						clear(Node->right);
// 						if (Node == _root)
// 						{
// 							free_Node(_root);
// 							_root = _nil;
// 							_nil->parent = NULL;
// 							_size = 0;
// 						}
// 						else
// 							free_Node(Node);
// 					}

// 					// DELETE FIX
// 					void delete_fix(pointer x)
// 					{
// 						for (; x != _root && x->color == BLACK;)
// 						{
// 							if (x == x->parent->left)
// 							{
// 								pointer w = x->parent->right;
// 								if (w->color == RED)
// 								{
// 									w->color = BLACK;
// 									x->parent->color = RED;
// 									rotate_left(x->parent);
// 									w = x->parent->right;
// 								}
// 								if (w->left->color == BLACK && w->right->color == BLACK)
// 								{
// 									w->color = RED;
// 									x = x->parent;
// 								}
// 								else
// 								{
// 									if (w->right->color == BLACK)
// 									{
// 										w->left->color = BLACK;
// 										w->color = RED;
// 										rotate_right(w);
// 										w = x->parent->right;
// 									}
// 									w->color = x->parent->color;
// 									x->parent->color = BLACK;
// 									w->right->color = BLACK;
// 									rotate_left(x->parent);
// 									x = _root;
// 								}
// 							}
// 							else
// 							{
// 								pointer w = x->parent->left;
// 								if (w->color == RED)
// 								{
// 									w->color = BLACK;
// 									x->parent->color = RED;
// 									rotate_right(x->parent);
// 									w = x->parent->left;
// 								}
// 								if (w->right->color == BLACK && w->left->color == BLACK)
// 								{
// 									w->color = RED;
// 									x = x->parent;
// 								}
// 								else
// 								{
// 									if (w->left->color == BLACK)
// 									{
// 										w->right->color = BLACK;
// 										w->color = RED;
// 										rotate_left(w);
// 										w = x->parent->left;
// 									}
// 									w->color = x->parent->color;
// 									x->parent->color = BLACK;
// 									w->left->color = BLACK;
// 									rotate_right(x->parent);
// 									x = _root;
// 								}
// 							}
// 						}
// 						if (x->color != NIL)
// 							x->color = BLACK;
// 						return ;
// 					}

// 					// ERASE
// 					void erase_Node(pointer z)
// 					{
// 						pointer x;
// 						pointer y;

// 						if (z != _nil)
// 						{
// 							if (z->left == _nil || z->right == _nil)
// 								y = z;
// 							else
// 							{
// 								y = z->right;
// 								while (y->left != _nil)
// 									y = y->left;
// 							}
// 							if (y->left != _nil)
// 								x = y->left;
// 							else
// 								x = y->right;

// 							if (x != _nil)
// 								x->parent = y->parent;
// 							if (y->parent == _nil)
// 								_root = x;
// 							else
// 							{
// 								if (y == y->parent->left)
// 									y->parent->left = x;
// 								else
// 									y->parent->right = x;
// 							}
// 							if (y != z)
// 							{
// 								delete z->value;
// 								z->value = new ft::pair<const key_type, mapped_type>(y->value->first, y->value->second);
// 							}
// 							if (y->color == BLACK)
// 								delete_fix(x);
// 							_alloc.destroy(y);
// 							_alloc.deallocate(y, 1);
// 							_nil->parent = maximum(_root);
// 						}
// 					}

// 					// ROTATE LEFT
// 					void rotate_left(pointer x)
// 					{
// 						pointer y = x->right;

// 						x->right = y->left;
// 						if (y->left != _nil)
// 							y->left->parent = x;
// 						if (y != _nil)
// 							y->parent = x->parent;
// 						if (x->parent == _nil)
// 							_root = y;
// 						else
// 						{
// 							if (x == x->parent->left)
// 								x->parent->left = y;
// 							else
// 								x->parent->right = y;
// 						}
// 						y->left = x;
// 						if (x != _nil)
// 							x->parent = y;
// 						return ;
// 					}

// 					// ROTATE RIGHT
// 					void rotate_right(pointer x)
// 					{
// 						pointer y = x->left;

// 						x->left = y->right;
// 						if (y->right != _nil)
// 							y->right->parent = x;
// 						if (y != _nil)
// 							y->parent = x->parent;
// 						if (x->parent == _nil)
// 							_root = y;
// 						else
// 						{
// 							if (x == x->parent->right)
// 								x->parent->right = y;
// 							else
// 								x->parent->left = y;
// 						}
// 						y->right = x;
// 						if (x != _nil)
// 							x->parent = y;
// 						return ;
// 					}

// 					// INSERT FIX
// 					void insert_fix(pointer x)
// 					{
// 						while (x != _root && x->parent->color == RED)
// 						{
// 							if (x->parent == x->parent->parent->left)
// 							{
// 								pointer y = x->parent->parent->right;
// 								if (y->color == RED)
// 								{
// 									x->parent->color = BLACK;
// 									y->color = BLACK;
// 									x->parent->parent->color = RED;
// 									x = x->parent->parent;
// 								}
// 								else
// 								{
// 									if (x == x->parent->right)
// 									{
// 										x = x->parent;
// 										rotate_left(x);
// 									}
// 									x->parent->color = BLACK;
// 									x->parent->parent->color = RED;
// 									rotate_right(x->parent->parent);
// 								}
// 							}
// 							else
// 							{
// 								pointer y = x->parent->parent->left;
// 								if (y->color == RED)
// 								{
// 									x->parent->color = BLACK;
// 									y->color = BLACK;
// 									x->parent->parent->color = RED;
// 									x = x->parent->parent;
// 								}
// 								else
// 								{
// 									if (x == x->parent->left)
// 									{
// 										x = x->parent;
// 										rotate_right(x);
// 									}
// 									x->parent->color = BLACK;
// 									x->parent->parent->color = RED;
// 									rotate_left(x->parent->parent);
// 								}
// 							}
// 						}
// 						_root->color = BLACK;
// 					}

// 	};
// };
// End of namespace FT

#endif
