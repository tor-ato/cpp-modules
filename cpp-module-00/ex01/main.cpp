/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:13:01 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/04 21:44:06 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>
#include <cstdlib>

typedef enum {
	CMD_UNKNOWN,
	CMD_ADD,
	CMD_SEARCH,
	CMD_EXIT
} command_t;

static void showAllCommands() {
	std::cout << "Available commands:" << std::endl;
	std::cout << "  ADD: Add a new contact" << std::endl;
	std::cout << "  SEARCH: Search for a contact" << std::endl;
	std::cout << "  EXIT: Exit the program" << std::endl;
}

static std::string getlinePrompt(const std::string &prompt) {
	std::string line;
	std::cout << prompt;
	std::getline(std::cin, line);
	if (std::cin.fail() || std::cin.eof())
		std::exit(1);
	return line;
}

static command_t getCommand() {
	std::string command = getlinePrompt("Enter a command: ");
	if (command == "ADD")
		return CMD_ADD;
	else if (command == "SEARCH")
		return CMD_SEARCH;
	else if (command == "EXIT")
		return CMD_EXIT;
	else
		return CMD_UNKNOWN;
}

static void handleCommandAdd(PhoneBook &phone_book) {
	std::string first_name = getlinePrompt("Enter first name: ");
	std::string last_name = getlinePrompt("Enter last name: ");
	std::string nickname = getlinePrompt("Enter nickname:");
	std::string phone_number = getlinePrompt("Enter phone number: ");
	std::string darkest_secret = getlinePrompt("Enter dakest secret: ");

	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	if (!contact.isFullContact()) {
		std::cout << "Invalid: contact is not full" << std::endl;
		return;
	}
	phone_book.addContact(contact);
}

// static void handleCommandSearch(PhoneBook &phone_book)
// {
// 	if (phone_book.getContactCount() == 0) {
// 		std::cout << "Phone book is empty" << std::endl;
// 		return;
// 	}
//
// 	phone_book.printPhonebook();
// }
//
int main() {
	PhoneBook phone_book;

	showAllCommands();
	while (true) {
		command_t command = getCommand();
		bool exit_flag = false;
		switch (command) {
			case CMD_ADD:
				handleCommandAdd(phone_book);
				break;
			case CMD_SEARCH:
				// handle_command_search(phone_book);
				break;
			case CMD_EXIT:
				exit_flag = true;
				break;
			default:
				break;
		}
		if (exit_flag)
			break;
	}
}
