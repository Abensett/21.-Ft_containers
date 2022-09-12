/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:13 by abensett          #+#    #+#             */
/*   Updated: 2022/09/12 14:34:00 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <iostream>
using std::string;
using std::ostream;

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key,T>>>
	class map
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

		/************************************************************
		* 						MEMBER TYPES						*
		************************************************************/

		typedef T											mapped_type;
		typedef Key											Key_type;


#endif
