/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:32:38 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/04 21:45:59 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MODULES_PHONEBOOK_H
#define CPP_MODULES_PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
	const static int maxContacts = 8;
	const static int maxFieldWidth = 10;
	const static char tableDelimiter = '|';
	Contact contacts[maxContacts];
	int contact_count;
	int overwrite_index;

public:
	PhoneBook();

	int getContactCount() const;

	void addContact(const Contact &);
	void printPhonebook() const;
};
#endif
