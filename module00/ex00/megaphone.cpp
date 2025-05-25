/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:46:47 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/02 19:04:16 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
    std::string str;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        str = argv[i];
        for (std::string::iterator c = str.begin(); c != str.end(); c++) *c = std::toupper(*c);
        std::cout << str;
    }
    std::cout << std::endl;
    return (0);
}
