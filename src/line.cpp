#include <string>
#include <iostream>
#include <random>

#include "../inc/line.h"
#include "../inc/color.h"

Line::Line(int length, const std::string& charset, const std::string& color){
    this->length_ = length;
    this->charset_ = charset;
    this->color_ = color;
}

std::ostream& operator<<(std::ostream& out, Line& line){
    // display a random character from the character set
    int charIndex = std::rand() % line.charset_.length();
    out << colorize(line.charset_[charIndex], line.color_);
    // update the position, and mark this line inactive if it has reached the end
    line.position_++;
    if (line.position_ == line.length_)
        line.active_ = false;
    return out;
}

void Line::activate(){
    this->active_ = true;
    this->position_ = 0;
}