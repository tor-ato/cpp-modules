/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:14:12 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/04 20:54:32 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact() {}

Contact::Contact(const std::string &first_name, 
				 const std::string &last_name, 
				 const std::string &nickname,
				 const std::string &phone_number, 
				 const std::string &darkest_secret)
				:first_name(first_name),
				 last_name(last_name),
				 nickname(nickname),
				 phone_number(phone_number), 
				 darkest_secret(darkest_secret) {}

Contact &Contact::operator=(const Contact &new_contact) {
	if (this == &new_contact)
		return *this;
	this->first_name = new_contact.first_name;
	this->last_name = new_contact.last_name;
	this->nickname = new_contact.nickname;
	this->phone_number = new_contact.phone_number;
	this->darkest_secret = new_contact.darkest_secret;
	return *this;
}


bool Contact::isFullContact() const {
	return  !this->first_name.empty() && !this->last_name.empty() &&
			!this->phone_number.empty() && !this->nickname.empty() &&
			!this->darkest_secret.empty();
}

