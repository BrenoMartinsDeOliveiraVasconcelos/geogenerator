#include <iostream>
#include <stdlib.h>
#include <regex>
#include <vector>

#include "helpers.h"

int main(){

    std::vector<std::string> options = {"T", "Exit"};
    std::string selected_option = select_from_vector(options, "What do you want to do?");

    std::cout << selected_option << std::endl;

    return 0;
}

