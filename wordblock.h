#ifndef WORDBLOCK_H
#define WORDBLOCK_H

#include <string>
#include <iostream>
#include <SFML/System.hpp>

class Wordblock {

public:

    Wordblock();
    int getPes();
    int getSpeed();
    void subntext();
    void setPes(int p);
    void setSpeed(int s);
    double steps(int lim);
    void addntext(std::string c);
    sf::Vector2f getpos();
    std::string getotext();
    std::string getntext();
    void setPositionX(int x);
    Wordblock(std::string text);
    void updatePosition(float deltatime);

private:

    int pes;
    sf::Vector2f pos;
    std::string otext;
    std::string ntext;
    double SPEED = 100;
};

#endif // WORDBLOCK_H
