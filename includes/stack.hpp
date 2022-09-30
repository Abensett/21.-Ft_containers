/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:15 by abensett          #+#    #+#             */
/*   Updated: 2022/09/30 20:02:11 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
namespace ft
{
	template< class T,
		class Container = ft::vector<T>
	> class stack
	{
		public :
		typedef				Container 					container_type;
		typedef typename	Container::value_type		value_type;
		typedef typename	Container::size_type		size_type;
		typedef typename	Container::reference		reference;
		typedef typename	Container::const_reference	const_reference;

		// Constructor
		explicit 		stack (const container_type& ctnr = container_type())
		{
			container = ctnr;
		};

		// Member functions
		bool			empty() const { return (container.empty());};
		size_type		size() const { return (container.size());};
		value_type &	top() { return (container.back());};
		void			push (const value_type& val) { container.push_back(val);};
		void			pop() { container.pop_back();};

		

		private :
			container_type	container;
	};

	// Non-member function overloads
	template< class T, class Container >
	bool operator ==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs == rhs);
	};
	template< class T, class Container >
	bool operator !=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs != rhs);
	};
	template< class T, class Container >
	bool operator <( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs < rhs);
	};
	template< class T, class Container >
	bool operator <=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs <= rhs);
	};
	template< class T, class Container >
	bool operator >( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs > rhs);
	};
	template< class T, class Container >
	bool operator >=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs >= rhs);
	};

}

#endif
