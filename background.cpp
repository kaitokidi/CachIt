#include "background.h"

/*Background::Background(){

}*/

Background::Background(sf::RenderWindow &windowg, std::string path) :window(windowg){
    ptex = NULL;
    if(!background.loadFromFile(path)){
        std::cout << "error on loading background" << std::endl;
    }
    windowWidth = windowg.getSize().x;
    windowHeight = windowg.getSize().y;
}

void Background::print(){

    windowWidth = window.getSize().x;
    windowHeight = window.getSize().y;
    ptex = &background;

    int pos_x, pos_y;
    pos_x = pos_y = delay = 0;

    float scalex, scaley;
    if(windowWidth > windowHeight){
        scaley = scalex =  windowWidth/float(ptex->getSize().x);
        delay = windowHeight - ptex->getSize().y*scalex;
        pos_y+=delay/2;
    } else {
        scalex = scaley = windowHeight/float(ptex->getSize().y);
        delay = windowWidth - ptex->getSize().x*scalex;
        pos_x+=delay/2;
    }

    sprite.setTexture(*ptex, true);
    sprite.setScale(scalex, scaley);
    sprite.setPosition(pos_x, pos_y);
    window.draw(sprite);

}
