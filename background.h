#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
public:
   void print();
  // Background();
   Background(sf::RenderWindow &windowg, std::string path);

private:
   sf::Sprite sprite;
   sf::Texture* ptex;
   sf::Texture background;
   sf::RenderWindow& window;
   int delay, windowHeight, windowWidth;
};

#endif // BACKGROUND_H
