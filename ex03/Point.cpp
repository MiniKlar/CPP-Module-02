/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:14:06 by lomont            #+#    #+#             */
/*   Updated: 2025/10/09 02:18:21 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Point::Point( Fixed newX, Fixed newY ) : x(newX), y(newY) {
	//std::cout << "Constructor called" << std::endl;
	return;
}

Point::Point(const Point & src) : x(src.x), y(src.y) {
	//std::cout << "Copy constructor called" << std::endl;
	return ;
}

Point& Point::operator=(const Point & other) {
	//std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

Point::~Point( void ) {
	//std::cout << "Destructor called" << std::endl;
	return;
}

const Fixed& Point::getFixedY( void ) const {
	return (this->y);
}

const Fixed& Point::getFixedX( void ) const {
	return (this->x);
}
