#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>
#include <boost/program_options.hpp>


#include "../inc/color.h"
#include "../inc/term_window.h"
#include "../inc/line.h"

namespace po = boost::program_options;

int main(int argc, char** argv){
    // parse the program arguments
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "displays the help menu")
        ("minlen", po::value<int>(), "the minimum length for each vertical line of text (default = 10)")
        ("maxlen", po::value<int>(), "the maximum length for each vertical line of text (default = 15)")
    ;
    po::variables_map options;
    po::store(po::parse_command_line(argc, argv, desc), options);
    // display the help menu if requested
    if (options.count("help")){
        std::cout << desc << std::endl;
        return 0;
    }
    // parse each option, or set it to its default if not provided
    int sizeMin = (options.count("minlen")) ? options["minlen"].as<int>() : 10; 
    int sizeMax = (options.count("maxlen")) ? options["maxlen"].as<int>() : 15; 
    // validate the options 
    if (sizeMin >= sizeMax){
        std::cerr << colorize("error: ", COLOR_RED) << "The minimum line length must be less than the maximum" << std::endl;
        return 1;
    }
    // in future versions, these will be user-set
    std::string color = COLOR_GREEN;
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int delayMs = 30;
    std::srand(time(nullptr));
    // display the splash text in a random color
    std::vector<std::string> splashColors = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_CYAN, COLOR_MAGENTA, COLOR_WHITE, COLOR_GREY};
    std::string splashColor = splashColors[std::rand() % 8];
    std::cout << colorize("Wake up, neo", splashColor) << std::endl;
  
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
