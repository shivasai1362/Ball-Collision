//
// Created by shiva on 08-01-2025.
//

#include "Engine.h"

#include <iostream>

Engine::Engine() : window(sf::VideoMode(Config::winWidth,Config::winHeight), Config::title) {
    window.setFramerateLimit(Config::frameRate);

}
void Engine::processEvents() {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
            break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto [x,y] = sf::Mouse::getPosition(window);
                    x_pos = static_cast<float>(x) - 15.5f;
                    y_pos = static_cast<float>(y) - 15.5f;
                    addBall();
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    for (auto &ball : balls) {
                        ball.applyRandomImpulse();
                    }
                }
            break;



        }
    }
}

void Engine::update() {
    for (Ball &ball : balls) {
        sf::CircleShape &shape = ball.getBall();
        // std::cout << win_height << std::endl;
        ball.y_vel += Config::gravity;
        shape.move(ball.x_vel, ball.y_vel);
        if (shape.getPosition().y + shape.getRadius()*2 > Config::winHeight ) {
            shape.setPosition(shape.getPosition().x, Config::winHeight - 2 * ball.ballRadius);
            ball.y_vel = -ball.y_vel * Config::restituition;
            ball.x_vel = ball.x_vel*Config::groundFriction;
        }

        if (shape.getPosition().y < 0) {
            shape.setPosition(shape.getPosition().x, 0);
            ball.y_vel = -ball.y_vel * Config::restituition;
        }

        if (shape.getPosition().x + 2*ball.ballRadius > Config::winWidth) {
            shape.setPosition(Config::winWidth - 2*ball.ballRadius, shape.getPosition().y);
            ball.x_vel = -ball.x_vel * Config::restituition;
        }
        if (shape.getPosition().x < 0) {
            shape.setPosition(0, shape.getPosition().y);
            ball.x_vel = -ball.x_vel * Config::restituition;
        }
    }
    for (int i = 0; i < balls.size(); i++) {
        for (int j = 0; j < balls.size(); j++) {
            if (i != j)
                balls[i].checkCollision(balls[j]);
        }
    }
}

void Engine::render() {
    window.clear(Config::engineTheme);
    for (auto &ball : balls) {
        window.draw(ball.getBall());
    }
    window.display();

}

void Engine::addBall() {
    Ball ball({x_pos, y_pos}, sf::Color::Magenta);
    balls.push_back(ball);
}


void Engine::run() {
    while (window.isOpen()) {
        this->processEvents();
        this->update();
        this->render();
    }
}
