#ifndef POINT_H
#define POINT_H

struct Point{
    int x;
    int y;

    Point(int i, int w)
    : x(i%w),y(i/w){}
    
    Point(Point& p)
    : x(p.x), y(p.y){}

    int flatten(int w){
        return (y*w) + x;
    }
};

#endif