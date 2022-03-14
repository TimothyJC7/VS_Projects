#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Company {
private:
	static int login;
	static std::fstream user_db;
public:
	Company() = delete;
	static void registerUser(const std::string& un, const std::string& p);
	static void loginUser(const std::string& un, const std::string& p);
private:
	static void fileFailCheck(std::fstream& f);
	static bool userExists(const std::string& un);
	static void validateUser(const std::string& un, const std::string& p);
	friend static void clearUsers();
};
