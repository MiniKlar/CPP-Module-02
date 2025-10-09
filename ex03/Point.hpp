/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:10:54 by lomont            #+#    #+#             */
/*   Updated: 2025/10/09 02:16:59 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(Fixed newX, Fixed newY);
		Point(const Point & src);
		Point& operator=(const Point & other);
		~Point();

		//getters
		const Fixed& getFixedX() const;
		const Fixed& getFixedY() const;
};

#endif

