/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:46:13 by abensett          #+#    #+#             */
/*   Updated: 2022/08/11 21:46:42 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <string> 
#include <iostream>
using std::string;
using std::ostream;  
 
class myheader
{  
 	public:
		myheader(void); 
		~myheader(void);
		myheader(const myheader &myheader);
		myheader &operator=(const myheader &myheader);

		string 		getName(void) const;
		int 		getGrade(void) const;
		void		upGrade(void);
		void		deGrade(void);
 
		class ExceptionToThrow : public std::exception				// first exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("myheader::exception : Something went wrong !");
				}
		};

	private:
		const string  	_name;
		int				_grade;
};

ostream &operator<<(ostream &o, const myheader &myheader);

#endif
