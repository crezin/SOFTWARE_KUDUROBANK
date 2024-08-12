#include "Criptografia.h"
#include <iostream>
#ifdef _WIN32
#include <conio.h>  // Necessário para _getch() em Windows
#else
#include <termios.h>
#include <unistd.h>
#endif

std::string getsenha() {
    std::string senha;
    char ch;

#ifdef _WIN32
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!senha.empty()) {
                std::cout << "\b \b";
                senha.pop_back();
            }
        } else {
            senha.push_back(ch);
            std::cout << '*';
        }
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n') {
        if (ch == 127) {  // ASCII para Backspace
            if (!senha.empty()) {
                std::cout << "\b \b";
                senha.pop_back();
            }
        } else {
            senha.push_back(ch);
            std::cout << '*';
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    std::cout << std::endl;
    return senha;
}