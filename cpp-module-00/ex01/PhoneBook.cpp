/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:19:53 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/05 16:53:29 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "template.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contact_count(0), overwrite_index(0) {}

void PhoneBook::addContact(const Contact &contact) {
	if (this->overwrite_index >= PhoneBook::maxContacts)
		this->overwrite_index = 0;
	this->contacts[this->overwrite_index] = contact;
	++this->overwrite_index;
	if (this->contact_count < PhoneBook::maxContacts)
		++this->contact_count;
}

std::string PhoneBook::truncateString(const std::string &str) const {
	if (str.length() <= PhoneBook::maxFieldWidth)
		return str;

	std::string truncated = str.substr(0, PhoneBook::maxFieldWidth - 1);
	truncated.append(".");
	return truncated;
}

void PhoneBook::printPhonebookRow(int row) const {
	Contact contact = this->contacts[row];
	const std::string fields[] = {
		toString(row),
		contact.getFirstName(),
		contact.getLastName(),
		contact.getNickName(),
	};

	for (int i = 0; i < 4; i++) {
		std::cout << std::setw(PhoneBook::maxFieldWidth)
			<< PhoneBook::truncateString(fields[i]);
		if (i < 3)
			std::cout << PhoneBook::tableDelimiter;
	}
	std::cout << std::endl;
}

void PhoneBook::printHeader() const {
	const std::string columns[] = {
		"index",
		"first name",
		"last name",
		"nickname"
	};
	for (int i = 0; i < 4; i++) {
		std::cout << std::setw(PhoneBook::maxFieldWidth)
			<< PhoneBook::truncateString(columns[i]);
		if (i < 3)
			std::cout << PhoneBook::tableDelimiter;
	}
	std::cout << std::endl;
}


void PhoneBook::printPhoneBook() const {
	this->printHeader();
	for (int row = 0; row < this->contact_count; row++) {
		this->printPhonebookRow(row);
	}
}

int PhoneBook::getContactCount() const {
	return this->contact_count;
}

void PhoneBook::printContact(int i) {
	if (i < 0 || i>= PhoneBook::maxContacts || i >= this->contact_count) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	this->contacts[i].printContact();
}
