#include "stats.h"

Stats::Stats(sf::RenderWindow &windowg) : window(windowg){

    windowWidth = window.getSize().x;
    windowHeight = window.getSize().y;

    if(!font.loadFromFile("font/menu.otf")){
        std::cout << "Can't find the font file" << std::endl;
    }
    text.setFont(font);
    CharacterSize = ((windowHeight/24+windowWidth/18/4));
    text.setCharacterSize(CharacterSize);
    text.setColor(sf::Color::Black);

    wrongLetters = wrongWords = okWords = okLet = 0;

}

void Stats::printText(std::string s, int x, int y){
    std::string aux = s;
    text.setString(aux);
    text.setPosition(x,y);
    window.draw(text);
}

void Stats::print(){
    int distancex, distancey;
    distancex = windowWidth/64;
    distancey = windowHeight/4;
    printText("Punts",distancex,distancey);
    distancey += CharacterSize;

    printText("LLetres:",distancex,distancey);
    distancey += CharacterSize;
    std::stringstream s;
    s << ": ) - " << okLet;
    printText(s.str(),distancex,distancey);
    distancey += CharacterSize;
    std::stringstream s1;
    s1 << ": ( - " << wrongLetters;
    printText(s1.str(),distancex,distancey);
    distancey += CharacterSize;

    printText("Paraules:",distancex,distancey);
    distancey += CharacterSize;
    std::stringstream s2;
    s2 << ": ) - " << okWords;
    printText(s2.str(),distancex,distancey);
    distancey += CharacterSize;
    std::stringstream s3;
    s3 << ": ( - " << wrongWords;
    printText(s3.str(),distancex,distancey);
    distancey += CharacterSize;

}

void Stats::addWrongWords(int ww){
    wrongWords += ww;
}

void Stats::addWrongLetters(int wl){
    wrongLetters += wl;
}

void Stats::addOkWords(int ow){
    okWords += ow;
}

void Stats::addOkLetters(int ol){
    okLet += ol;
}
