#include <iostream>
#include <fstream>
#include <string>

//  Ansi color codes   //
const std::string ANSI_RESET = "\x1B[0m";
const std::string ANSI_RED = "\x1B[31m";
const std::string ANSI_YELLOW = "\x1B[33m";
const std::string ANSI_GREEN = "\x1B[32m";
const std::string ANSI_BLUE = "\x1B[34m";
const std::string ANSI_MAGENTA = "\x1B[35m";

const std::string DEFAULT_COLOR = ANSI_YELLOW;  //  Yellow color (Default)   //

int main(int argc, char *argv[]){

    //  Checking arguments  //

    if (argc != 3 && argc != 4) {
        std::cerr << "Correct use: " << argv[0] << " [color] <search_string> <text_file>" << std::endl;
        return 1;
    }

    std::string color = (argc == 4) ? argv[1] : DEFAULT_COLOR;
    std::string search_string = argv[argc - 2];
    std::string file_name = argv[argc - 1];

    //  Opening file    //
    std::ifstream file(file_name);

    //  Checking file has opened correctly  //

    if (!file.is_open()) {
        std::cerr << "File could not be opened " << file_name << std::endl;
        return 1;
    }

    std::string line;

    //    Search loop    //
    
    while (std::getline(file, line)) {
        size_t found = line.find(search_string);
        if (found != std::string::npos) {
            std::string part_a = line.substr(0, found);                         //previous part
            std::string part_d = line.substr(found, search_string.length());    //featured part
            std::string part_p = line.substr(found + search_string.length());   //back part

            std::string color_code;
            if (color == "RED") {
                color_code = ANSI_RED;
            } else if (color == "YELLOW") {
                color_code = ANSI_YELLOW;
            } else if (color == "GREEN") {
                color_code = ANSI_GREEN;
            } else if (color == "BLUE") {
                color_code = ANSI_BLUE;
            } else if (color == "MAGENTA") {
                color_code = ANSI_MAGENTA;
            } else {
                std::cerr << "Invalid color. Options are: RED, YELLOW, GREEN, BLUE, MAGENTA." << std::endl;
                return 1;
            }

            std::cout << part_a << ANSI_RESET << color_code << part_d << ANSI_RESET << part_p << std::endl;
            ;//Here needs to be de counter of coincidences
        } else {
            std::cout << line << std::endl;
        }
    }

    
return 0;
}