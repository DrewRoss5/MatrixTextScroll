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

std::string parseColor(const std::string& color_str);
std::string colorize(char str, const std::string &color);

#endif