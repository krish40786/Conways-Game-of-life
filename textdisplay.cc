#include "textdisplay.h"
#include "cell.h"


TextDisplay::TextDisplay(size_t n){
    for(size_t i = 0; i < n; ++i){
        std::vector<char> temp;
        for(size_t y = 0; y < n; ++y){
            temp.emplace_back('-');
        }
        theDisplay.emplace_back(temp);
    }
}

void TextDisplay::notify(Subject & whoNotified){
    if(whoNotified.getInfo().state == State::Alive){
        theDisplay.at(whoNotified.getInfo().col).at(whoNotified.getInfo().row) = '+';
    } else {
        theDisplay.at(whoNotified.getInfo().col).at(whoNotified.getInfo().row) = '-';
    }
}

void TextDisplay::notify(){

}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
    for(auto &u: td.theDisplay){
        for(auto &v: u){
            out << v;
        }
        out << std::endl;
    }

}