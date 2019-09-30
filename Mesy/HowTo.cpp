#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameStates.hpp"
#include "HowTo.hpp"

#include <iostream>

namespace MESY {
    HowToState::HowToState(GameDataRef data) : _data(data) {
        this->_data->assets.LoadTexture("how to play screen", HOW_TO_PLAY_SCREEN);
        
        
        _howtoscreen.setTexture(this->_data->assets.GetTexture("how to play screen"));
        
        
        sf::Vector2f targetSize((float)(1216.0f/1.63 ), (float)(1600.0f/1.68  ));
        
        
        _howtoscreen.setScale(targetSize.x / _howtoscreen.getLocalBounds().width, targetSize.y / _howtoscreen.getLocalBounds().height);
        
        
        _howtoscreen.setPosition(-10, 0);
    }
    
    void HowToState::HandleInput() {
        sf::Event event;
        
        while(_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) {
                _data->window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
                }
            }
            
        }
    }
    
    void HowToState::Update(float dt) {
        
    }
    
    void HowToState::Draw(float dt) {
        
        _data->window.display();
        _data->window.draw(_howtoscreen);
        
        
    }
}



