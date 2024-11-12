#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>


#include "../inc/color.h"
#include "../inc/term_window.h"
#include "../inc/line.h"

int main(){
    // in future versions, these will be user-set
    std::string color = COLOR_GREEN;
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int sizeMin = 10;
    int sizeMax = 15;
    int delayMs = 30;
    // initialize the window and the line array
    TermWindow win;
    std::vector<Line> lines;
    for (int i = 0; i < (win.width - 1); i++){
        int size = std::rand() % (sizeMax - sizeMin) + sizeMin;
        lines.push_back(Line(size, charset, color));
    }
    // run the display
    while (true){
        // determine where the line should go
        Line* newLine = nullptr;
        do {
            int lineIndex = rand() % (win.width - 1);
            newLine = &lines[lineIndex];
        }
        while (newLine->active());
        newLine->activate();
        // display each active line 
        for (int i = 0; i < (win.width - 1); i++){
            if (lines[i].active())
                std::cout << lines[i];
            else
                std::cout << " ";
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }


}
