#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include <cstdlib>


#include "../inc/color.h"
#include "../inc/term_window.h"

int main(){
    system("clear");
    std::srand(time(NULL));
    std::string chars = "abcdefghiklmnopqrstuvwyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int charLen = chars.length();
    TermWindow win;
    std::vector<std::string> colors = {"red", "green", "blue", "yellow", "cyan", "magenta", "white"};
    while (true){
        int colNo = rand() % (win.width - 2); 
        for (int i = 0; i < colNo; i++){
            std::cout << " ";
        }
        std::string color = colors[rand() % 6];
        std::string chr;
        chr.push_back(chars[rand() % charLen]);
        std::cout << colorize(chr, parseColor(color)) << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}