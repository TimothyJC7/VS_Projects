#include <iostream>
#include <fstream>
#include <string>

#include "company.h"

void clearUsers();

int main()
{
    int userInput_i;
    char userInput_c;
    std::string username;
    std::string password;

    while (1) {
        std::cout << "\nEnter 0 to Login or 1 to Register, 2 to exit" << std::endl;
        std::cin >> userInput_i;
        if (userInput_i == 2) break;
        std::cout << "\nEnter Username: " << std::endl;
        std::cin >> username;
        std::cout << "\nEnter Password: " << std::endl;
        std::cin >> password;

        if (userInput_i) {
            Company::registerUser(username, password);
        }
        else {
            Company::loginUser(username, password);
        }
    }
    std::cout << "\nClear Users?" << std::endl;
    std::cin >> userInput_c;
    if (userInput_c == 'y') clearUsers();

    return 0;

}

void clearUsers() {
    Company::user_db.open("user_db.txt", std::ios::out | std::ios::trunc);
    Company::user_db.close();
}

