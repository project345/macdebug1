#pragma once

#include "SFML/Graphics.hpp"
#include "DEFINITIONS.hpp"

//template class std::basic_string<char>;

namespace MESY {
    class InputManager {
    public:
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}
