#ifndef STATS_H
#define STATS_H

#include <string>
#include <sstream>
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"

class Stats
{
public:

    Stats(sf::RenderWindow &windowg);
    void print();
    void addOkWords(int ow);
    void addOkLetters(int ol);
    void addWrongWords(int ww);
    void addWrongLetters(int wl);

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;
    int okLet;
    int okWords;
    int wrongWords;
    int wrongLetters;
    int CharacterSize;
    int windowHeight, windowWidth;
    void printText(std::string s, int x, int y);
};

#endif // STATS_H
