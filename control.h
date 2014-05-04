#ifndef CONTROL_H
#define CONTROL_H

#include <queue>
#include <vector>
#include "stats.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "wordblock.h"
#include "background.h"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"

class Control
{
public:
   // Control();
    void print();
    int  handler();
    void readWord();
    int  checkWords();
    void printWords();
    void updateWordsPosition(float deltatime);
    Control(sf::RenderWindow &windowg);

private:
    bool accent;
    Wordblock wb;
    sf::Font font;
    sf::Text text;
    Background bg;
    std::ifstream in;
    sf::RenderWindow& window;
    std::queue<Wordblock> words;
    std::wstring utf8_to_utf16(const std::string& utf8);
    int topLimit, botLimit, windowHeight, windowWidth, actLetter, CharacterSize;

    bool okToPush(Wordblock word, std::queue<Wordblock>& words);
};

#endif // CONTROL_H
