//
// Created by shiva on 08-01-2025.
//

#ifndef ENGINE_H
#define ENGINE_H
#include<SFML/Graphics.hpp>
#include "Ball.h"
#include "Config.h"


class Engine {
private:
    sf::RenderWindow window;
    sf::Event event;
    std::vector<Ball> balls;

    float x_pos, y_pos;
private:
    void processEvents();
    void update();
    void render();
    void addBall();
public:
    Engine();
    void run();
};



#endif //ENGINE_H
