/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/10/03 17:46:27 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "utils.hpp"

// https://www.youtube.com/watch?v=qvZGUFHWChY

/* ****************************************************************************
* ------------------------------- RBNode Class -------------------------------*
* 																			  *
*		RBN a node is a struct with :								   		  *
*		a value, a color, a parent, a left child and a right child			  *
*******************************************************************************/
template <typename T>
struct node
{
	int		key;
	char	color;
	node	*parent;
	node	*left;
	node	*right;
};

/******************************************************************************
A Red Black Tree is a binary search tree with the following 4 properties:
 1. Every node is either red or black
 2. The root is black and Every leaf (NULL) is black
 3. If a node is red, then both its children are black
 4. Every simple path from a node to a descendant leaf contains the same number of black nodes
******************************************************************************/

template <class Key, class T, class Compare, class Allocator >
class RedBlackTree
{
	private :
		node <T?*		root;
		node *q;

	public :
		RBtree()
		{
			q=NULL;
			root=NULL;
		}
	void insert();
	void insertfix(node *);
	void leftrotate(node *);
	void rightrotate(node *);
	void del();
	node* successor(node *);
	void delfix(node *);
	void disp();
	void display( node *);
}
// End of namespace FT
#endif
