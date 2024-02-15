#include <iostream>
#include "Balle.hpp"
using namespace std;

Balle::Balle(int x, int y): x{x}, y{y}, oX{x}, oY{y}, dir{STOP}
{}

void Balle::Reset(){
    x = oX, y = oY;
    dir = STOP;
}

void Balle::ChangerDirection(Direction d ){
    dir = d;
}

void Balle::randomDirection(){
    dir = (Direction)((rand() % 6) + 1);
}

void Balle::Bouger(){
    switch (dir)
    {
    case STOP:
        break;

    case LEFT:
        x--;
        break;
    case UPLEFT:
        x--;
        y--;
        break;
    case DOWNLEFT:
        x--;
        y++;

    case RIGHT:
        x++;
        break;        
    case UPRIGHT:
        x++;
        y--;
        break;
    case DOWNRIGHT:
        x++;
        y++;
        break;
    
    default:
        break;
    }
}