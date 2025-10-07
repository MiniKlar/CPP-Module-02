/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:12 by lomont            #+#    #+#             */
/*   Updated: 2025/10/07 23:38:10 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed( void );
		~Fixed( void );
		Fixed ( Fixed const & src );
		Fixed& operator=( Fixed const & other);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
