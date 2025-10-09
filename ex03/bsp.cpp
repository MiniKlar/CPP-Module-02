/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:45:01 by lomont            #+#    #+#             */
/*   Updated: 2025/10/09 02:08:29 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed d1 = (b.getFixedX() - a.getFixedX()) * (point.getFixedY() - a.getFixedY()) - (b.getFixedY() - a.getFixedY()) * (point.getFixedX() - a.getFixedX());
    Fixed d2 = (c.getFixedX() - b.getFixedX()) * (point.getFixedY() - b.getFixedY()) - (c.getFixedY() - b.getFixedY()) * (point.getFixedX() - b.getFixedX());
    Fixed d3 = (a.getFixedX() - c.getFixedX()) * (point.getFixedY() - c.getFixedY()) - (a.getFixedY() - c.getFixedY()) * (point.getFixedX() - c.getFixedX());

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}
