#include <iostream>
#include <fstream>
#include <string>

#include "company.h"

std::fstream Company::user_db;

void Company::registerUser(const std::string& un,const std::string& p) {
	user_db.open("user_db.txt", std::ios::in || std::ios::app);
	fileFailCheck(user_db);
	if (!userExists(un)) {
		user_db << un + ' ' + p << std::endl;
		std::cout << "\nUser Registered\n" << std::endl;
	}
	else std::cout << "\nUser already registered\n" << std::endl;
	user_db.close();
}
void Company::loginUser(const std::string& un, const std::string& p) {
	user_db.open("user_db.txt", std::ios::in || std::ios::app);
	fileFailCheck(user_db);
	if (Company::user_db.eof()) std::cout << "\nUser doesn't Exist\n" << std::endl;
	else validateUser(un, p);;
	user_db.close();
}

void Company::fileFailCheck(std::fstream& f) {
	if (f.fail()) {
		std::cout << "Failed to Register User";
		exit(EXIT_FAILURE);
	}
	return;
}

bool Company::userExists(const std::string& un) {
	std::string cred;
	while (getline(user_db, cred)) {
		if (cred.substr(0, un.length()) == un) return true;
	}
	return false;
}
void Company::validateUser(const std::string& un, const std::string& p) {
	std::string cred;
	while (getline(user_db, cred)) {
		if (cred.substr(0, un.length()) == un) {
			if (cred.substr(un.length() + 1, p.length()) == p) {
				std::cout << "\nUser Valid, Login Successful\n" << std::endl;
				return;
			}
			else {
				std::cout << "\nIncorrect Password\n" << std::endl;
				return;
			}
		}
	}
	std::cout << "\nUsername and Password are incorrect\n" << std::endl;
}

