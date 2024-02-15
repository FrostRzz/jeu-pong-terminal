#include"Plateau.hpp"
#include <iostream>
using namespace std;

Plateau::Plateau():x{0}, y{0}
{}

Plateau::Plateau(int X, int Y):x{X}, y{Y}, oX{X}, oY{Y}
{}

void Plateau::Reset(){
    x = oX;
    y = oY;
}