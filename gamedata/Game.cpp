//
// Created by shiva on 08-01-2025.
//

#include "Game.h"
#include "Config.h"

Game::Game() : window(sf::VideoMode(Config::winWidth, Config::winHeight), Config::title)
{
    circle.setRadius(50.f);
    circle.setPosition(100.f,100.f);
    circle.setFillColor(sf::Color::Magenta);
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}


void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                handleMovement(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handleMovement(event.key.code, false);
        }
    }
}

void Game::render() {
    window.clear();
    window.draw(circle);
    window.display();
}

//Main Logic

void Game::handleMovement(sf::Keyboard::Key keyCode, bool movement) {
    if (keyCode == sf::Keyboard::W)
            isMovingUP = movement;
    if (keyCode == sf::Keyboard::A)
            isMovingLEFT = movement;
    if (keyCode == sf::Keyboard::S)
            isMovingDOWN = movement;
    if (keyCode == sf::Keyboard::D)
            isMovingRIGHT = movement;
}



void Game::update(sf::Time dt) {
    sf::Vector2f movement = {0.f,0.f};
    if (isMovingUP)
        movement.y -= 150.f;
    if (isMovingDOWN)
        movement.y += 150.f;
    if (isMovingLEFT)
        movement.x -= 150.f;
    if (isMovingRIGHT)
        movement.x += 150.f;

    circle.move(movement * dt.asSeconds());
}


