#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
    int min1 = *std::min_element(intTable.begin(), intTable.end());
    for (int i = 0; i < intTable.size(); i++) {
        if (min1 == intTable[i]) {
            intTable.erase(intTable.begin() + i);
            break;
        }
    }
    int min2 = *std::min_element(intTable.begin(), intTable.end());
    int sum = a*b*c + 2*min1 + 2*min2;
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
}