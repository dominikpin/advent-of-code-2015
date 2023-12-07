#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"

int main() {
    std::fstream input;
	input.open("day04\\input.txt");
    std::string text;
    getline(input, text);
    int i = 1;
    while (true) {
        std::string newString = text + std::to_string(i);
        if (GetMD5String(newString).substr(0, 6) == "000000") {
            std::cout << i << std::endl;
            break;
        }
        i++;
    }
    input.close();
    return 0;
}