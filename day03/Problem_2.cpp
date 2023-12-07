#include <iostream>
#include <fstream>
#include <string>
#include <set>

int calculateNumberOfHouses(std::string string) {
    std::set<std::pair<int, int>> visitedHouses;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int counter = 1;
    visitedHouses.insert(std::make_pair(x1, y1));
    for (int i = 0; i < string.length(); i++) {
        char c = string[i];
        switch (i%2) {
            case 0:
                switch (c) {
                    case '^':
                        y1++;
                        break;
                    case '>':
                        x1++;
                        break;
                    case 'v':
                        y1--;
                        break;
                    case '<':
                        x1--;
                        break;
                }
                break;
            case 1:
                switch (c) {
                    case '^':
                        y2++;
                        break;
                    case '>':
                        x2++;
                        break;
                    case 'v':
                        y2--;
                        break;
                    case '<':
                        x2--;
                        break;
                }
                break;
        }
        std::pair<int, int> currentHouse;
        if (i%2 == 0) {
            currentHouse = std::make_pair(x1, y1);
        } else {
            currentHouse = std::make_pair(x2, y2);
        }
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
    return 0;
}