#include <iostream>
#include <string>
#include <fstream>

int lights[1000][1000] = {0};

void turnOnLights(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            lights[i][j]++;
        }
    }
}

void turnOffLights(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (lights[i][j] > 0) {
                lights[i][j]--;
            }
        }
    }
}

void toggleLights(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            lights[i][j] += 2;
        }
    }
}

int* getNumbers(std::string string) {
    int* numbers = new int[4];
    int counter = 0;
    for (int i = 0; i < string.length(); i++) {
        if (isdigit(string[i])) {
            std::string number = "";
            while (true) {
                number += string[i];
                i++;
                if (!isdigit(string[i])) {
                    break;
                }
            }
            numbers[counter] = std::stoi(number);
            counter++;
        }
    }
    return numbers;
}

void analyzeString(std::string string) {
    int* numbers = getNumbers(string);
    if (string[1] == 'o') {
        toggleLights(numbers[0], numbers[1], numbers[2], numbers[3]);
    } else {
        if (string[6] == 'n') {
            turnOnLights(numbers[0], numbers[1], numbers[2], numbers[3]);
        } else {
            turnOffLights(numbers[0], numbers[1], numbers[2], numbers[3]);
        }
    }
}

int countLights() {
    int counter = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            counter += lights[i][j];
        }
    }
    return counter;
}

int main() {
    std::fstream input;
	input.open("day06\\input.txt");
    std::string text;
    while (getline(input, text)) {
        analyzeString(text);
    }
    int sum = countLights();
    input.close();
    std::cout << sum << std::endl;
    return 0;
}