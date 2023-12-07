#include <iostream>
#include <string>
#include <fstream>

bool isWordNice(std::string string) {
    bool hasPairOfTwoLatters = false;
    bool hasRepeatingLetter = false;
    for (int i = 0; i < string.length(); i++) {
        if (!hasPairOfTwoLatters) {
            for (int j = i + 2; j < string.length() - 1; j++) {
                if (string.substr(i, 2) == string.substr(j, 2)) {
                    hasPairOfTwoLatters = true;
                }
            }
        }
        if (!hasRepeatingLetter && string.length() - i > 2 && string[i] == string[i+2]) {
            hasRepeatingLetter = true;
        }
    }
    if (hasRepeatingLetter && hasPairOfTwoLatters) {
        return true;
    }
    return false;
}

int main() {
    std::fstream input;
	input.open("day05\\input.txt");
    std::string text;
    int counter = 0;
    while (getline(input, text)) {
        if (isWordNice(text)) {
            counter++;
        }
    }
    input.close();
    std::cout << counter << std::endl;
    return 0;
}