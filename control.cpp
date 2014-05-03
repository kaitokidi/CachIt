#include "control.h"

/*Control::Control(){
    window = NULL;
}*/

Control::Control(sf::RenderWindow &windowg) :window(windowg), bg(windowg, "pics/background.png"), in("text/text.txt"){

    wb = Wordblock("Start í");
//std::cout <<"wb de start = " << wb.getotext() << std::endl;
    wb.setPositionX(windowHeight/2);
    words.push(wb);
//std::cout << "paraula " << words.front().getotext() << std::endl;
//std::cout << "lets dive into the bucle" << std::endl;
for(int i = 0; i < words.front().getotext().size(); ++i){
    //std::cout << "lletra " << i << " : " << words.front().getotext()[i]  << std::endl;
}
std::string miau = "sí";
wchar_t wc = 'í';
miau += wc;
//std::cout << miau << " " << miau.size() << std::endl;
//std::cout << miau[0] << " " << miau[1] << " " << miau[2] << std::endl;
    srand(time(NULL));
    actLetter = 0;
    windowWidth = window.getSize().x;
    windowHeight = window.getSize().y;
    topLimit = 1*windowHeight/3;
    botLimit = 3*windowHeight/4;
    if(!font.loadFromFile("font/djvu.ttf")){
        std::cout << "Can't find the font file" << std::endl;
    }
    text.setFont(font);
    CharacterSize = ((windowHeight/24+windowWidth/18)/2);
    text.setCharacterSize(CharacterSize);

}

int Control::handler(){
    int ret = 0;
    sf::Event event;
//char a = 'í';
std::string s,e;
    while(window.pollEvent(event)){

        switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:

//            std::cout << a <<" " << event.text.unicode << " " << (char) event.text.unicode  << " " << words.front().getotext()  << " "  << words.front().getotext()[actLetter] << std::endl;
//            s = "s";
  //          s += "í";
       //     std::cout << "esa " << s << std::endl;
                if(event.text.unicode == 9) { /*tab PRESSED */ if(words.size() > 0)words.pop(); actLetter=0; ret = 0;}
                else if(event.text.unicode == 13) { /*RET PRESSED */
                }
                else if(event.text.unicode == words.front().getotext()[actLetter] ){
                    s = e;
                    s += event.text.unicode;
                    words.front().addntext(s);
                    ret = 1;
                    if(words.front().getotext() == words.front().getntext()) {
                        ret = 3; /*RET = 3 MEANS THE WORD HAS BEEN WRITTEN CORRECTLY*/
                        words.pop();
                        actLetter = 0;
                    }
                    else {
                        ++actLetter;
                        words.front().setPes(words.front().getPes()-1);
                    }
                }
                else if((event.text.unicode == 8) and ((words.front().getPes()) > 0)) {
                    words.front().subntext();
                    --actLetter;
                }
                else {
                    if(ret != 1)ret = 2; /*RET = 2 MEANS THERE HAVE failed IN WRITTING*/
                }

                break;
            case  sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::N) {
                }
                break;

            default:
                break;
        }
    }
    return ret;
}

int Control::checkWords(){
    int bad = 0;
    if(!words.empty()){
        Wordblock wbaux;
        wbaux = words.front();
        if(wbaux.getpos().y >= windowHeight-windowHeight/16){
            ++bad;
            words.pop();
            actLetter = 0;
        }
    }
    return bad;
}

void Control::print(){
    bg.print();
    printWords();
}

void Control::printWords(){
    text.setCharacterSize((windowHeight/24+windowWidth/18)/2);
    std::queue<Wordblock> aux = words;

    for(int i = 0; i < (int)words.size(); ++i){

        Wordblock w = aux.front();
        text.setPosition(w.getpos());
        text.setString(w.getotext());
        text.setColor(sf::Color::White);
        window.draw(text);
        text.setString(w.getntext());
        text.setColor(sf::Color::Green);
        window.draw(text);

        aux.pop();
    }

}

void Control::updateWordsPosition(float deltatime){

    std::queue<Wordblock> aux;
    int size = words.size();
    for(int i = 0; i < size; ++i){
        words.front().updatePosition(deltatime);
        aux.push(words.front());
        words.pop();
    }
    for(int i = 0; i < size; ++i){
        words.push(aux.front());
        aux.pop();
    }

}

void Control::readWord(){
    std::string word;
    in >> word;
    if(word.size() > 0){
        if(okToPush(word, words)){
                Wordblock w(word);
                w.setPositionX((rand()%(3*windowWidth/4-word.size()*CharacterSize))+windowWidth/4);
            words.push(w);
        }
        else{
            for(int i = word.size()-1; i >= 0; --i){
                in.putback(word[i]);
            }
        }
    }
}

bool Control::okToPush(Wordblock word, std::queue<Wordblock>& words ){
    std::queue<Wordblock> aux = words;
    while(!aux.empty()){
        if(words.front().getotext() == "Start") return false;
        if( aux.front().steps(botLimit) > word.steps(topLimit)) return false;
        aux.pop();
    }
    return true;
}
