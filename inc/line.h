#ifndef LINE_H
#define LINE_H

#include <iostream>

// represents a single line in the display
class Line{
    public:
        Line(int length, const std::string& charset, const std::string& color);
        bool active() {return active_;}
        void activate();
        friend std::ostream& operator<<(std::ostream& out, Line& line);
    private: 
        bool active_ {false};
        int length_ {0};
        int position_ {0};
        std::string charset_;
        std::string color_;
};

#endif