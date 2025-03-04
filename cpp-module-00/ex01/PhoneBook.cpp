/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:19:53 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/04 21:53:25 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook() : contact_count(0), overwrite_index(0) {}

void PhoneBook::addContact(const Contact &contact) {
	if (this->overwrite_index >= PhoneBook::maxContacts)
		this->overwrite_index = 0;
	this->contacts[this->overwrite_index] = contact;
	++this->overwrite_index;
	if (this->contact_count < PhoneBook::maxContacts)
		++this->contact_count;
}

// void PhoneBook::printPhonebook() const {
//
// }

int PhoneBook::getContactCount() const {
	return this->contact_count;
}
