#include "wordblock.h"

Wordblock::Wordblock(){

}

Wordblock::Wordblock(std::string txt){
    otext = txt;
    pes = otext.size();
    pos.y = 1;
    setSpeed(SPEED+rand()%80);
}

std::string Wordblock::getotext(){
    return otext;
}

std::string Wordblock::getntext(){
    return ntext;
}

void Wordblock::addntext(std::string c){
    ntext += c;
}

void Wordblock::subntext(){
    if(ntext.size() > 0) ntext.erase(ntext.size()-1, ntext.size());
}

sf::Vector2f Wordblock::getpos(){
    return pos;
}

int Wordblock::getPes(){
    return pes;
}
void Wordblock::setPes(int p){
    pes = p;
}

void Wordblock::updatePosition(float deltatime){
    pos.y += ((SPEED-pes)*deltatime);
}

int Wordblock::getSpeed(){
    return SPEED;
}

double Wordblock::steps(int lim){
    return ((lim - pos.y)/(SPEED-pes));
}

void Wordblock::setPositionX(int x){
    pos.x = x;
}

void Wordblock::setSpeed(int s){
    SPEED = s;
}
