/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:15 by lomont            #+#    #+#             */
/*   Updated: 2025/10/08 19:00:38 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0) {
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int raw_value, bool is_raw ) : value(raw_value) {
	//std::cout << "Raw value constructor called" << std::endl;
	(void)is_raw;
	return ;
}

Fixed::Fixed( const int n ) : value(n << bits) {
	//std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const float f ) : value(roundf(f * (1 << bits))) {
	//std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed( void ) {
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src) {
	//std::cout << "Copy constructor called" << std::endl;
	this->value = src.value;
	return ;
}

Fixed& Fixed::operator=( Fixed const & other ) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return (*this);
}

Fixed Fixed::operator-( Fixed const & other ) {
	//std::cout << "Substraction operator called" << std::endl;
	return Fixed( this->value - other.value, true);
}

Fixed Fixed::operator*( Fixed const & other ) {
	//std::cout << "Multiplication operator called" << std::endl;
	return Fixed((this->value * other.value) >> 8, true);
}

Fixed Fixed::operator/( Fixed const & other ) {
	//std::cout << "Division operator called" << std::endl;
	return Fixed((this->value * (1 << bits)) / other.value, true);
}

Fixed Fixed::operator+( Fixed const & other ) {
	//std::cout << "Addition operator called" << std::endl;
	return Fixed(this->value + other.value, true);
}

bool Fixed::operator<( Fixed const & other ) {
	//std::cout << "Less than operator called" << std::endl;
	return (this->value < other.value);
}

bool Fixed::operator<=( Fixed const & other ) {
	//std::cout << "Less than or equal to operator called" << std::endl;
	return (this->value <= other.value);
}

bool Fixed::operator>( Fixed const & other ) {
	//std::cout << "Greater than operator called" << std::endl;
	return (this->value > other.value);
}

bool Fixed::operator>=( Fixed const & other ) {
	//std::cout << "Greater than or equal to operator called" << std::endl;
	return (this->value >= other.value);
}

bool Fixed::operator==( Fixed const & other ) {
	//std::cout << "Equal to operator called" << std::endl;
	return (this->value == other.value);
}

bool Fixed::operator!=( Fixed const & other ) {
	//std::cout << "Not equal to operator called" << std::endl;
	return (this->value != other.value);
}

Fixed& Fixed::operator++( void ) {
	//std::cout << "Pre-incrementation operator called" << std::endl;
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	//std::cout << "Post-incrementation operator called" << std::endl;
	Fixed dst (*this);
	this->value += 1;
	return (dst);
}

Fixed& Fixed::operator--( void ) {
	//std::cout << "Pre-decrementation operator called" << std::endl;
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	//std::cout << "Post-decrementation operator called" << std::endl;
	Fixed dst (*this);
	this->value -= 1;
	return (dst);
}

Fixed& Fixed::min( Fixed & fp1, Fixed & fp2) {
	if (fp1.value > fp2.value)
		return (fp2);
	else
		return (fp1);
}

const Fixed& Fixed::min( Fixed const & fp1, Fixed const & fp2) {
	if (fp1.value > fp2.value)
		return (fp2);
	else
		return (fp1);
}

Fixed& Fixed::max( Fixed & fp1, Fixed & fp2) {
	if (fp1.value < fp2.value)
		return (fp2);
	else
		return (fp1);
}

const Fixed& Fixed::max( Fixed const & fp1, Fixed const & fp2) {
	if (fp1.value < fp2.value)
		return (fp2);
	else
		return (fp1);
}

int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
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
