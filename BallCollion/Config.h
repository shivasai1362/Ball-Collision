//
// Created by shiva on 08-01-2025.
//

#ifndef CONFIG_H
#define CONFIG_H
namespace Config {
    //Engine
    const int winWidth = 1366;
    const int winHeight = 768;
    const int frameRate = 60;
    const sf::String title = "Engine";
    const sf::Color engineTheme = sf::Color(23,23,23);
    //Engine Environment
    const float gravity = 0.8f;//0.8
    const float restituition = 0.7f;//0.7
    const float groundFriction = 0.99f;//0.95
}


#endif //CONFIG_H
