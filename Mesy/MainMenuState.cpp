#include <sstream>
#include <iostream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameStates.hpp"
#include "HowTo.hpp"

//template class std::basic_string<char>;


namespace MESY {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {
        
        music.openFromFile(MAIN_MUSIC);
        music.setVolume(50);
        music.play();
        music.setLoop(true);
        
        this->_data->assets.LoadTexture("Start Game Button", EASY_MAINMENU_FILEPATH);
        this->_data->assets.LoadTexture("How to play button", HOW_TO_PLAY_BUTTON);
        this->_data->assets.LoadTexture("Background", MENU_IMAGE_FILEPATH);
        
        
        _startgame.setTexture(this->_data->assets.GetTexture("Start Game Button"));
        _howto.setTexture(this->_data->assets.GetTexture("How to play button"));
        _background.setTexture(this->_data->assets.GetTexture("Background"));
        
        sf::Vector2f targetSize1((float)(1920.0f / 1.3), (float)(1280.0f / 1.3));
        sf::Vector2f targetSize2((float)(960.0f / 2.5), (float)(480.0f / 2.5));
        sf::Vector2f targetSize3((float)(1070.0f / 5), (float)(444.0f / 3));
        
        _startgame.setScale(targetSize2.x / _startgame.getLocalBounds().width, targetSize2.y / _startgame.getLocalBounds().height);
        _startgame.setPosition(SCREEN_WIDTH / 2 - (_startgame.getGlobalBounds().width / 2), 550);
        
        _background.setScale(targetSize1.x / _background.getLocalBounds().width, targetSize1.y / _background.getLocalBounds().height);
        _background.setPosition(-360, -50);
        
        _howto.setScale(targetSize3.x / _background.getLocalBounds().width, targetSize3.y / _background.getLocalBounds().height);
        _howto.setPosition( 300, 800);
    }
    
    void MainMenuState::HandleInput() {
        sf::Event event;
        
        while(_data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) {
                _data->window.close();
            }
            
            if(this->_data->input.IsSpriteClicked(this->_startgame, sf::Mouse::Left, this->_data->window)) {
                music.stop();
                this->_data->machine.AddState(StateRef(new GameStates(_data)),true);
            }
            if(this->_data->input.IsSpriteClicked(this->_howto, sf::Mouse::Left, this->_data->window)) {
                this->_data->machine.AddState(StateRef(new HowToState(_data)),true);
            }
        }
    }
    
    void MainMenuState::Update(float dt) {
        
    }
    
    void MainMenuState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_howto);
        _data->window.draw(_startgame);
        _data->window.display();
    }
}
