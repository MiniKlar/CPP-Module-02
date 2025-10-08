/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:12 by lomont            #+#    #+#             */
/*   Updated: 2025/10/08 19:03:49 by lomont           ###   ########.fr       */
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
		Fixed(int raw_value, bool is_raw);
	public:
		//constructors & destructor
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		~Fixed( void );
		Fixed ( Fixed const & src );

		//operators overload

		Fixed& operator=( Fixed const & other);
		Fixed operator-( Fixed const & other );
		Fixed operator+( Fixed const & other );
		Fixed operator*( Fixed const & other );
		Fixed operator/( Fixed const & other );

		bool operator<( Fixed const & other );
		bool operator<=( Fixed const & other );
		bool operator>( Fixed const & other );
		bool operator>=( Fixed const & other );
		bool operator==( Fixed const & other );
		bool operator!=( Fixed const & other );

		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );

		static Fixed& min( Fixed & fp1, Fixed & fp2);
		const static Fixed& min( Fixed const & fp1, Fixed const & fp2);
		static Fixed& max( Fixed & fp1, Fixed & fp2);
		const static Fixed& max( Fixed const & fp1, Fixed const & fp2);

		float toFloat( void ) const;
		int toInt( void ) const;

		//getter & setter
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
