#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::string INTEGER_REGEX = "^(-|){0,1}([0-9]){1,}([.]([0-9]){1,}$|){1}$";

std::string select_from_vector(std::vector<std::string> options, std::string menu_desc) {
    int vector_size = options.size();
    
    std::cout << menu_desc << std::endl;
    std::regex integer_pattern(INTEGER_REGEX);

    for (int i = 0; i < vector_size; i++) {
        std::cout << "[" << i << "] " << options[i] << std::endl;
    }

    while (true){
        std::cout << "Select an option: ";
        std::string option;
        std::getline(std::cin, option);
        std::string selected_option = "";

        // validate if menu input is integer
        if (std::regex_match(option, integer_pattern)) {
            int option_int = std::stoi(option);
            if (option_int >= 0 && option_int < vector_size) {
                selected_option = options[option_int];
            }else{
                std::cout << "Number is not valid" << std::endl;
            };
        }else{
            std::cout << "Invalid input!" << std::endl;
        };

        if (selected_option != "") {
            return selected_option;
        }
    }


}

#endif // HELPERS_H
