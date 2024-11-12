#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>

#include "../inc/color.h"

// returns a color-code from the name of a color, raises an error if the color isn't found
std::string parseColor(const std::string& colorStr){
    std::string colorNames[8] = {"red", "green", "yellow", "blue", "magenta", "cyan", "grey", "white"};
    //determine the ansi color code
    std::string lower = colorStr;
    int colorNo {0};
    for (int i = 0; i < 8; i++){
        if (colorStr == colorNames[i]){
            colorNo = i + 1;
            break;
        }
    }
    if (!colorNo)
        throw std::invalid_argument("unrecognized color");
    // construct the color code from the found number
    std::stringstream ss;
    ss << "\033[3" << colorNo << "m";
    return ss.str();
}

// appends an ansi color code to the beginning of a string and COLOR_RESET to the end, effectively making it a "colored" string when displayed iin a terminal
std::string colorize(const std::string& str, const std::string &color){
    std::stringstream out;
    out << color << str << COLOR_RESET;
    return out.str();
}
