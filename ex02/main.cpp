/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:30:02 by lomont            #+#    #+#             */
/*   Updated: 2025/10/08 19:02:29 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    std::cout << "=== Test constructeurs ===" << std::endl;
    Fixed a;                    // 0
    Fixed b(42);               // 42
    Fixed c(42.42f);           // 42.42
    Fixed d(b);                // copie de b

    std::cout << "\n=== Test affichage ===" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n=== Test opérateurs arithmétiques ===" << std::endl;
    std::cout << "b + c = " << (b + c) << std::endl;       // 42 + 42.42
    std::cout << "c - b = " << (c - b) << std::endl;       // 42.42 - 42
    std::cout << "b * 2 = " << (b * Fixed(2)) << std::endl; // 42 * 2
    std::cout << "c / 2 = " << (c / Fixed(2)) << std::endl; // 42.42 / 2

    std::cout << "\n=== Test comparaisons ===" << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > a: " << (b > a) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;

    std::cout << "\n=== Test incrémentation ===" << std::endl;
    std::cout << "a avant: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a après: " << a << std::endl;

    std::cout << "\n=== Test min/max ===" << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    return 0;
}
