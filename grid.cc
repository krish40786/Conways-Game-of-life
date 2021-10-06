#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "window.h"
#include "graphicsdisplay.h"

void Grid::init(size_t n){
    for(size_t y = 0; y < n; ++y){
        std::vector<Cell> tmp;
        for(size_t x = 0; x < n; ++x){
            tmp.emplace_back(Cell{x, y});
        }
        grid.emplace_back(tmp);
    }

    delete td;
    td = new TextDisplay(n);
    delete ob;
    ob = new GraphicsDisplay(n);
    //the relationship between cells is more relevant in the grid rather 
    //than attaching the neighbours in the cell class or else where imo

    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            for(int k = -1; k < 2; ++k){
                for(int z = -1; z < 2; ++z){
                    if(((x + k) >= 0) && ((y + z) >= 0) && (k != 0 || z != 0) && ((x + k) < (int)n) && ((y + z) < (int)n)){
                        //std::cout << x + k << "   " << y + z << std::endl;
                        //std::cout << x << "               " << y << "      "<< std::endl; 
                        grid.at(x).at(y).attach(&grid.at(x + k).at(y + z));
                    }
                }
            }
            //attaching the text dispaly to every cell
            grid.at(x).at(y).attach(td);
            grid.at(x).at(y).attach(ob);
        }
    }

}

void Grid::turnOn( size_t r, size_t c ){
    grid.at(c).at(r).setLiving();
    td->notify(grid.at(c).at(r));
    ob->notify(grid.at(c).at(r));
}

void Grid::tick(){
//Happens in 2 steps
//First step
    for(auto &u: grid){
        for(auto &v: u){
            v.notify();
        }
    }
//Second step
    for(auto &u: grid){
        for(auto &v: u){
            v.recalculate();
        }
    }

    for(auto &u: grid){
        for(auto &v: u){
            td->notify(v);
            ob->notify(v);
        }
    }
}

Grid::~Grid(){
    delete td;
    delete ob;
}

std::ostream &operator<<( std::ostream & out, const Grid & g ){
    out << *(g.td);
}