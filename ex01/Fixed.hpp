/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:12 by lomont            #+#    #+#             */
/*   Updated: 2025/10/08 00:25:23 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		~Fixed( void );
		Fixed ( Fixed const & src );
		Fixed& operator=( Fixed const & other);

		float toFloat( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
