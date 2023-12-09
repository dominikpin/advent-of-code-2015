#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

struct wire{
    std::string identifier;
    uint16_t signal;

    void wireDetails() {
        std::cout << "Wire id: " << identifier << ", signal: " << signal << "." << std::endl;
    }
};

std::vector<std::string> split(std::string input) {
    std::vector<std::string> output;
    int start = 0;
    for (int i = 0; i < input.length(); i++) {
        if (isspace(input[i])) {
            output.push_back(input.substr(start, i - start));
            start = i + 1;
        }
    }
    output.push_back(input.substr(start, input.length() - start));
    return output;
}

wire* checkIfWireExists(std::vector<wire>& wires, std::string identifier) {
    for (wire& w : wires) {
        if (w.identifier == identifier) {
            return &w;
        }
    }
    return nullptr;
}

void analyzeInstructions(std::vector<std::vector<std::string>>& instructions, std::vector<wire>& wires) {
    while (instructions.size() > 0) {
        std::vector<std::string> instruction = instructions.front();
        instructions.erase(instructions.begin());
        wire* wireOutput = checkIfWireExists(wires, instruction[instruction.size() - 1]);
        if (wireOutput == nullptr) {
            wires.push_back({instruction[instruction.size() - 1], 0});
            wireOutput = &wires.back();
        }
        if (instruction.size() == 3) {
            if (isdigit(instruction[0][0])) {
                wireOutput->signal = std::stoi(instruction[0]);
            } else {
                wire* wire1 = checkIfWireExists(wires, instruction[0]);
                if (wire1 == nullptr) {
                    instructions.push_back(instruction);
                    wires.pop_back();
                    continue;
                }
                wireOutput->signal = wire1->signal;
            }
        } else if (instruction.size() == 4) {
            if (isdigit(instruction[1][0])) {
                wireOutput->signal = std::stoi(instruction[2]);
                continue;
            }
            wire* wire1 = checkIfWireExists(wires, instruction[1]);
            if (wire1 == nullptr) {
                instructions.push_back(instruction);
                wires.pop_back();
                continue;
            }
            wireOutput->signal = ~wire1->signal;
        } else if (instruction.size() == 5) {
            int signal1 = 0;
            if (isdigit(instruction[0][0])) {
                signal1 = std::stoi(instruction[0]);
            } else {
                wire* wire1 = checkIfWireExists(wires, instruction[0]);
                if (wire1 == nullptr) {
                    instructions.push_back(instruction);
                    wires.pop_back();
                    continue;
                }
                signal1 = wire1->signal;
            }
            if (instruction[1] == "AND" || instruction[1] == "OR") {
                int signal2 = 0;
                if (isdigit(instruction[2][0])) {
                    signal2 = std::stoi(instruction[2]);
                } else {
                    wire* wire2 = checkIfWireExists(wires, instruction[2]);
                    if (wire2 == nullptr) {
                        instructions.push_back(instruction);
                        wires.pop_back();
                        continue;
                    }
                    signal2 = wire2->signal;
                }
                if (instruction[1] == "AND") {
                    wireOutput->signal = signal1 & signal2;
                } else {
                    wireOutput->signal = signal1 | signal2;
                }
            } else if (instruction[1] == "RSHIFT") {
                wireOutput->signal = signal1 >> std::stoi(instruction[2]);
            } else if (instruction[1] == "LSHIFT") {
                wireOutput->signal = signal1 << std::stoi(instruction[2]);
            }
        }
    }
}

int main() {
    std::fstream input;
	input.open("day07\\input.txt");
    std::string text;
    std::vector<std::vector<std::string>> instructions;
    while (getline(input, text)) {
        instructions.push_back(split(text));
    }
    std::vector<wire> wires;
    analyzeInstructions(instructions, wires);
    for (wire wire : wires) {
        if (wire.identifier == "a") {
            std::cout << wire.signal << std::endl;
        }
    }
    input.close();
    return 0;
}