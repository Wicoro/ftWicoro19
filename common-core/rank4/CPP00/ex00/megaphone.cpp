/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:17:10 by norban            #+#    #+#             */
/*   Updated: 2025/05/14 11:17:39 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void to_uppercase(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; i++) {
            std::string arg(argv[i]);
            to_uppercase(arg);
            if (i != argc - 1) {
                std::cout << arg << "\n";
            } else {
                std::cout << arg;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
