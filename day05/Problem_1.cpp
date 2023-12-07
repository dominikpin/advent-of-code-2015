#include <iostream>
#include <string>
#include <fstream>

bool isWordNice(std::string string) {
    int vowelsCounter = 0;
    char previousLetter = ' ';
    bool hasDoubleLetter = false;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    std::string illegalString[] = {"ab", "cd", "pq", "xy"};
    for (int i = 0; i < string.length(); i++) {
        for (int j = 0; j < 4; j++) {
            if (previousLetter == illegalString[j][0] && string[i] == illegalString[j][1]) {
                return false;
            }
        }
        if (!hasDoubleLetter && previousLetter == string[i]) {
            hasDoubleLetter = true;
        }
        for (int j = 0; j < 5; j++) {
            if (string[i] == vowels[j]) {
                vowelsCounter++;
            }
        }
        previousLetter = string[i];
    }
    if (vowelsCounter >= 3 && hasDoubleLetter) {
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
}