#include <vector>
#include "puzzle.h"
#include <iostream>
#include <iomanip>
#include "point.h"

bool Puzzle::canMove(Move m){
    Point p (blankpos, width);
    switch(m){
        case up:
            return p.y > 0;
        break;
        case right:
            return p.x < width-1;
        break;
        case down:
            return p.y < height-1;
        break;
        case left:
            return p.x > 0;
        break;
    }
}

void Puzzle::move(Puzzle::Move m){
    Point p (blankpos, width);
    int i = p.flatten(width);

    Point p2 (p);
    int i2 = i;

    int dx = 0, dy = 0;
    switch(m){
        case up:
            dy = -1;
            break;
        case right:
            dx = 1;
            break;
        case down:
            dy = 1;
            break;
        case left:
            dx = -1;
            break;
    }
    p2.x += dx;
    p2.y += dy;
    i2 = p2.flatten(width);

    std::swap(slots[i], slots[i2]);
    blankpos=i2;
}

std::ostream& operator<<(std::ostream& out, const Puzzle& p){
    out << std::right;
    int i = 0;
    for(int x = 0; x < p.width; x++){
        for(int y = 0; y < p.height; y++){
            out << std::setw(3);
            if(p.slots[i] == Puzzle::BLANK)
                out << "";
            else
                out <<  (std::to_string(p.slots[i]) + " ");
            i++;
        }
        out << std::endl;
    }
    return out;
} 



