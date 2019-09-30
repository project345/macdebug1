#pragma once


//template class std::basic_string<char>;

namespace MESY {
    
    class Player {
    public:
        Player(GameDataRef data);
        void MovePlayer(int newX, int newY, int spriteShown);
        void Draw();
        void Move(float dt);
        void setPos(int x);
        sf::Vector2i GetPos();
        void Explode(int newX, int newY, bool life_is_zero);
        bool PlayerMoving();
        bool PlayerChosen();
        void MoveOff(int x);
        
    private:
        GameDataRef _data;
        sf::Sprite playerSprite, explosionSprite;
        sf::Vector2f originalPosition;
        int offsetX, offsetY, spriteShown, xPosition, yPosition;
        float counterWalking = 0, explosionTexture = 0, explosionTextureVertical = 0;
        bool isMoving, chosenStart, isExplosion, isDead = false;
        int dtModifier;
    };
}
