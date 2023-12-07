#include <iostream>
#include <fstream>

int main() {
    std::fstream input;
	input.open("day01\\input.txt");
    std::string text;
    getline(input, text);
    int counter = 0;
	for (int i = 0; i < text.length(); i++) {
        if (text[i] == '(') {
            counter++;
        }
        if (text[i] == ')') {
            counter--;
        }
    }
    std::cout << counter << std::endl;
    input.close(); 
}