#ifndef COLOR_H
#define COLOR_H

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GREY "\033[37m"
#define COLOR_WHITE "\033[38m"
#define COLOR_RESET "\033[0m"

#include <string>
#include <iostream>
#include <sstream>

std::string parseColor(const std::string& color_str);



// appends an ansi color code to the beginning of a string and COLOR_RESET to the end, effectively making it a "colored" string when displayed iin a terminal
template <typename T>
std::string colorize(const T& str, const std::string &color){
    std::stringstream out;
    out << color << str << COLOR_RESET;
    return out.str();
}


#endif