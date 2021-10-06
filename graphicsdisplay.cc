#include "graphicsdisplay.h"
#include "subject.h"

GraphicsDisplay::GraphicsDisplay(int RC): RC{RC}{}


void GraphicsDisplay::notify( Subject & whoNotified ){
    int us{500/RC};
    if(whoNotified.getInfo().state == State::Alive){
        //theDisplay.at(whoNotified.getInfo().col).at(whoNotified.getInfo().row) = '+';
        xwindow.fillRectangle(whoNotified.getInfo().col*us,whoNotified.getInfo().row*us,us,us,Xwindow::Blue);
    } else {
        //theDisplay.at(whoNotified.getInfo().col).at(whoNotified.getInfo().row) = '-';
        xwindow.fillRectangle(whoNotified.getInfo().col*us,whoNotified.getInfo().row*us,us,us,Xwindow::White);
    }
}

void GraphicsDisplay::notify(){

}
