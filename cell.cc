#include "cell.h"

Cell::Cell(size_t r, size_t c): info{r, c, State::Dead}, neighboursAlive{0}{}

void Cell::setLiving(){
    info.state = State::Alive;
}

void Cell::reset(){
    neighboursAlive = 0;
}
 
void Cell::recalculate(){
    //std::cout << this->info.col << "  " << this->info.row << "  " << this->neighboursAlive << std::endl;
    if(this->neighboursAlive > 3 || this->neighboursAlive < 2){
        info.state = State::Dead;
    } 
    if(this->getInfo().state == State::Dead && this->neighboursAlive == 3){
        info.state = State::Alive;
    }
    //reset the neigbours alive after calculating the status
    this->reset();
}

// Grid calls this to get me to notify my neighbours if I'm alive.
// Also needs to be called when state is set to be alive so displays are notified.
void Cell::notify(){
    this->notifyObservers();
}

// My neighbours will call this to let me know if they're alive.
void Cell::notify(Subject & whoNotified){
    if(whoNotified.getInfo().state == State::Alive){
        ++this->neighboursAlive;
    }
}

Info Cell::getInfo() const{
    return info;
}

