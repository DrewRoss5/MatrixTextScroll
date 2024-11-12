#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../inc/term_window.h"

// constructor for the terminal window class, initializes the height and width of the window automatically
TermWindow::TermWindow(){
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	this->height = w.ws_row;
    this->width = w.ws_col;
}
