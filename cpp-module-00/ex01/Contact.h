/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:14:39 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/04 20:52:41 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MODULES_CONTACT_H
#define CPP_MODULES_CONTACT_H

#include <string>

class Contact {
private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	Contact(const std::string &first_name, const std::string &last_name,
			const std::string &nickname, const std::string &phone_number,
			const std::string &darkest_secret);
	
	Contact &operator=(const Contact &new_contact);
	bool isFullContact() const;
};

#endif
