//
// Created by shiva on 08-01-2025.
//


#include "Ball.h"


#include <cmath>

#include "Config.h"


Ball::Ball(sf::Vector2f position, sf::Color color){
    ball.setPosition(position);
    ball.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    ball.setRadius(ballRadius);
}

sf::CircleShape &Ball::getBall() {
    return ball;
}

void Ball::applyRandomImpulse() {


    double angle = (rand() % 180) * 0.01745;
    double vx = maxImpulseVelocity*cos(angle);
    double vy = -maxImpulseVelocity*sin(angle);

    this->x_vel = vx;
    this->y_vel = vy;
    std::cout << vx << " " << vy << std::endl;


}

float Ball::abs(float num) {
    return ((num >= 0) ? num : -num);
}


void Ball::checkCollision(Ball &otherBall) {
    sf::Vector2f thisCenterRef = {this->getBall().getPosition().x - this->ballRadius,
                                 this->getBall().getPosition().y - this->ballRadius};
    sf::Vector2f otherCenterRef = {otherBall.getBall().getPosition().x - otherBall.ballRadius,
                                  otherBall.getBall().getPosition().y - otherBall.ballRadius};

    float relativeDistanceX = Ball::abs(thisCenterRef.x - otherCenterRef.x);
    float relativeDistanceY = Ball::abs(thisCenterRef.y - otherCenterRef.y);

    float distance = sqrtf((relativeDistanceX*relativeDistanceX) + (relativeDistanceY*relativeDistanceY));
    if (distance <= (this->ballRadius + otherBall.ballRadius)) {
        // Calculate normal vector of collision
        sf::Vector2f normal = {
            (otherCenterRef.x - thisCenterRef.x) / distance,
            (otherCenterRef.y - thisCenterRef.y) / distance
        };

        // Calculate relative velocity
        sf::Vector2f relativeVel = {
            otherBall.x_vel - this->x_vel,
            otherBall.y_vel - this->y_vel
        };

        // Calculate velocity along the normal
        float velAlongNormal = relativeVel.x * normal.x + relativeVel.y * normal.y;

        // Only proceed if objects are moving toward each other
        if (velAlongNormal > 0) {
            return;
        }

        // Calculate impulse scalar
        float restitution = Config::restituition;
        float j = -(1.0f + restitution) * velAlongNormal;
        j /= 2.0f; // Assuming equal masses

        // Apply impulse
        sf::Vector2f impulse = {j * normal.x, j * normal.y};

        this->x_vel -= impulse.x;
        this->y_vel -= impulse.y;
        otherBall.x_vel += impulse.x;
        otherBall.y_vel += impulse.y;

        // Resolve overlap
        float overlap = (this->ballRadius + otherBall.ballRadius) - distance;
        sf::Vector2f correction = (overlap * 0.5f) * normal;



        this->getBall().move(-correction.x, -correction.y);
        otherBall.getBall().move(correction.x, correction.y);
    }
}


