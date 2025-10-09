/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:43:49 by lomont            #+#    #+#             */
/*   Updated: 2025/10/09 02:17:07 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

void testPoint(const Point& a, const Point& b, const Point& c, const Point& point, const std::string& description) {
    bool result = bsp(a, b, c, point);
    std::cout << description << ": " << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    std::cout << "=== Test BSP Function ===" << std::endl;

    // Triangle de référence : (0,0), (4,0), (2,3)
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(4), Fixed(0));
    Point c(Fixed(2), Fixed(3));

    std::cout << "\nTriangle vertices: A(0,0), B(4,0), C(2,3)" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // Points qui DOIVENT être à l'intérieur
    testPoint(a, b, c, Point(Fixed(2), Fixed(1)), "Point (2,1) - Center");
    testPoint(a, b, c, Point(Fixed(1.5f), Fixed(0.5f)), "Point (1.5,0.5) - Inside");
    testPoint(a, b, c, Point(Fixed(2.5f), Fixed(1.5f)), "Point (2.5,1.5) - Inside");

    // Points qui DOIVENT être à l'extérieur
    testPoint(a, b, c, Point(Fixed(-1), Fixed(1)), "Point (-1,1) - Outside left");
    testPoint(a, b, c, Point(Fixed(5), Fixed(1)), "Point (5,1) - Outside right");
    testPoint(a, b, c, Point(Fixed(2), Fixed(4)), "Point (2,4) - Outside top");
    testPoint(a, b, c, Point(Fixed(2), Fixed(-1)), "Point (2,-1) - Outside bottom");

    // Points sur les arêtes (DOIVENT être OUTSIDE car has_zero = true)
    testPoint(a, b, c, Point(Fixed(2), Fixed(0)), "Point (2,0) - On edge AB");
    testPoint(a, b, c, Point(Fixed(1), Fixed(1.5f)), "Point (1,1.5) - On edge AC");
    testPoint(a, b, c, Point(Fixed(3), Fixed(1.5f)), "Point (3,1.5) - On edge BC");

    // Points aux sommets (DOIVENT être OUTSIDE)
    testPoint(a, b, c, Point(Fixed(0), Fixed(0)), "Point (0,0) - Vertex A");
    testPoint(a, b, c, Point(Fixed(4), Fixed(0)), "Point (4,0) - Vertex B");
    testPoint(a, b, c, Point(Fixed(2), Fixed(3)), "Point (2,3) - Vertex C");

    std::cout << "\n=== Additional Triangle Test ===" << std::endl;

    // Triangle différent pour plus de tests
    Point a2(Fixed(-2), Fixed(-1));
    Point b2(Fixed(2), Fixed(-1));
    Point c2(Fixed(0), Fixed(2));

    std::cout << "\nTriangle vertices: A(-2,-1), B(2,-1), C(0,2)" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    testPoint(a2, b2, c2, Point(Fixed(0), Fixed(0)), "Point (0,0) - Center");
    testPoint(a2, b2, c2, Point(Fixed(-1), Fixed(0)), "Point (-1,0) - Inside left");
    testPoint(a2, b2, c2, Point(Fixed(1), Fixed(0)), "Point (1,0) - Inside right");
    testPoint(a2, b2, c2, Point(Fixed(0), Fixed(3)), "Point (0,3) - Outside top");
    testPoint(a2, b2, c2, Point(Fixed(3), Fixed(0)), "Point (3,0) - Outside right");

    return 0;
}
