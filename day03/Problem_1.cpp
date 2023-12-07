#include <iostream>
#include <fstream>
#include <string>
#include <set>

int calculateNumberOfHouses(std::string string) {
    std::set<std::pair<int, int>> visitedHouses;
    int x = 0;
    int y = 0;
    int counter = 1;
    visitedHouses.insert(std::make_pair(x, y));
    for (int i = 0; i < string.length(); i++) {
        char c = string[i];
        switch (c) {
            case '^':
                y++;
                break;
            case '>':
                x++;
                break;
            case 'v':
                y--;
                break;
            case '<':
                x--;
                break;
        }
        std::pair<int, int> currentHouse = std::make_pair(x, y);
        auto it = visitedHouses.find(currentHouse);
        if (it == visitedHouses.end()) {
            visitedHouses.insert(currentHouse);
            counter++;
        }
    }
    return counter;
}

int main() {
    std::fstream input;
	input.open("day03\\input.txt");
    std::string text;
    getline(input, text);
    int sum = calculateNumberOfHouses(text);
    std::cout << sum << std::endl;
    input.close(); 
}