//
// Created by shiva on 08-01-2025.
//

#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
private:
    sf::CircleShape ball;
    static float abs(float num);

public:
    float x_vel = 0.f;
    float y_vel = 0.f;
    float ballRadius = 25.f;
    float maxImpulseVelocity = 100.f;
    float mass = 20;

public:
    Ball(sf::Vector2f position, sf::Color color);
    sf::CircleShape &getBall();
    void applyRandomImpulse();
    void checkCollision(Ball &otherBall);
};



#endif //BALL_H
