/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:36:24 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/05 16:37:26 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MODULES_TEMPLATE_H
#define CPP_MODULES_TEMPLATE_H

#include <sstream>

template<typename T>
std::string toString(const T &value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

#endif
