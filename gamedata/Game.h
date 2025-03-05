//
// Created by shiva on 08-01-2025.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time);
    void render();
    void handleMovement(sf::Keyboard::Key keyCode,  bool movement);
private:
    sf::RenderWindow window;
    sf::CircleShape circle;
    bool isMovingUP = false;
    bool isMovingDOWN = false;
    bool isMovingLEFT = false;
    bool isMovingRIGHT = false;
};



#endif //GAME_H
