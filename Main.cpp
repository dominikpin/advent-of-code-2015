#include <iostream>
#include <sstream>
#include <iomanip>

void runProblem(int day, int problem) {
    std::ostringstream problemFileName;
    problemFileName << "day" << std::setw(2) << std::setfill('0') << day << "/Problem_" << problem << ".cpp";
    std::string command = "g++ -std=c++20 " + problemFileName.str() + " -o problem && problem";
    system(command.c_str());
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <day_number> <problem_number>" << std::endl;
        return 1;
    }

    int day = std::stoi(argv[1]);
    int problem = std::stoi(argv[2]);

    runProblem(day, problem);

    return 0;
}
