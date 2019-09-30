#pragma once

#include "SFML/Graphics.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace MESY {
    class HowToState : public State {
    public:
        HowToState(GameDataRef data);
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _howtoscreen;
    };
}


