#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer{
    int RC;
    Xwindow xwindow;

 public:
    GraphicsDisplay(int RC);
    virtual void notify( Subject & whoNotified ) override; 
    virtual void notify() override;

};

#endif