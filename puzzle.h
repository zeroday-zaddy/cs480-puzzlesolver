#ifndef PUZZLE_H
#define PUZZLE_H


#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>


class Puzzle{
    size_t blankpos;
public:
    int width;
    int height;
    static const int BLANK = -1;
    enum Move{up, right, down, left};
    
    std::vector<int> slots;

    Puzzle(std::vector<int> _slots)
    : Puzzle(_slots, 3,3) { }

    Puzzle(std::vector<int> _slots, int w, int h){
        width = w;
        height = h;
        for(int i = 0; i < _slots.size(); i++){
            if(_slots[i] == Puzzle::BLANK){
                blankpos = i;
                break;
            }
        }
        slots = _slots;
    }


    Puzzle(const Puzzle& p)
    :blankpos(p.blankpos),slots(p.slots), 
     width(p.width), height(p.height){}

    bool operator==(const Puzzle& right) const {
        return slots == right.slots;
    }
    

    bool canMove(Move m);

    void move(Move m); 
    void moveUp(){ move(up);}; 
    void moveRight(){ move(right);}; 
    void moveDown(){ move(down);}; 
    void moveLeft(){ move(left);}; 


    size_t hash() const;

    int operator[](int i) const {return slots[i];}
    int& operator[](int i) {return slots[i];}

    
};

std::ostream& operator<<(std::ostream& out, const Puzzle& p);

class PuzzleHash{
public:
    /**
     * https://stackoverflow.com/a/72073933
    */
    std::size_t operator() (const Puzzle& p) const {
        std::size_t seed = p.slots.size();
        for(auto x : p.slots) {
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = (x >> 16) ^ x;
            seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

#endif