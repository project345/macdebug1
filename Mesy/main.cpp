#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

template class std::basic_string<char>;

int main() {
    
    
    MESY::Game(SCREEN_WIDTH,SCREEN_HEIGHT,"Debug Release");

    
    return EXIT_SUCCESS;
}
