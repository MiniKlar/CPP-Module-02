/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:15 by lomont            #+#    #+#             */
/*   Updated: 2025/10/08 00:32:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int n ) : value(n << bits) {
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const float f ) : value(roundf(f * (1 << bits))) {
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.value;
	return ;
}

Fixed& Fixed::operator=( Fixed const & other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return ;
}

int Fixed::toInt( void ) const {
	return ( value >> bits );
}

float Fixed::toFloat( void ) const {
	return (static_cast<float> (value) / (1 << bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}
