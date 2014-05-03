#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "control.h"


int main() {

    sf::RenderWindow windowGame (sf::VideoMode(800, 600), "CachIt!",
      sf::Style::Resize|sf::Style::Close);

    float deltatime;
    int keyhandler;
    sf::Clock deltaClock;
    Control c (windowGame);
    Stats s (windowGame);

    while(windowGame.isOpen()){

        deltatime = deltaClock.restart().asSeconds();

        windowGame.clear();

        keyhandler = c.handler();
        if(keyhandler == 2)s.addWrongLetters(1);
        else if(keyhandler == 1) s.addOkLetters(1);
        else if(keyhandler == 3) s.addOkWords(1);

        c.updateWordsPosition(deltatime);

        s.addWrongWords(c.checkWords());

        c.readWord();

        c.print();

        s.print();

        windowGame.display();

    }

    return 0;
}

/*
    for(int i = 0; i < ELEMENTS; ++i){
        std::stringstream s;
        s << "PATH/BASE" << i+1 << ".EXTENSION";
        if(!VECTOR_OF_ELEMENTS[i].loadFromFile(s.str())){
        std::cout << EXITmessage << std::endl;
        } else std::cout << ERRORmessage << std::endl;
    }


sf::Sound sound;
sf::SoundBuffer buffer;
buffer.loadFromFile("musicapermumi.ogg");
sound.setBuffer(buffer);
sound.setLoop(true);
sound.play();

sf::Music music;
if (!music.openFromFile("musicapermumi.ogg")) std::cout << " no puc carregar la musica " << std::endl;
music.play();
music.setPitch(1);
music.setLoop(true);*/
