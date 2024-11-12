#include <iostream>
#include <string>

#include "../inc/color.h"

int main(){
    std::string color = parseColor("cyan");
    std::cout << colorize("Hello, world", color) << std::endl;
}