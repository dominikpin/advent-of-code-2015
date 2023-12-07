#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> stringToIntTable(std::string string) {
    std::vector<int> result;
    int start = 0;

    for (int i = 0; i < string.length(); i++) {
        if (string[i] == 'x') {
            result.push_back(std::stoi(string.substr(start, i - start)));
            start = i + 1;
        }
    }
    result.push_back(std::stoi(string.substr(start)));

    return result;
}


int calculateSurface(std::string string) {
    std::vector<int> intTable = stringToIntTable(string);
    int a = intTable[0];
    int b = intTable[1];
    int c = intTable[2];
    int min = std::min(a*b, std::min(a*c, b*c));
    int sum = 2*(a*b + a*c + b*c) + min;
    return sum;
}

int main() {
    std::fstream input;
	input.open("day02\\input.txt");
    std::string text;
    int sum = 0;
    while (getline(input, text)) {
        sum += calculateSurface(text);
    }
    std::cout << sum << std::endl;
    input.close();
    return 0;
}