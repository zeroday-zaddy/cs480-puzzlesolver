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

    bool operator==(const Point& r){
        return x == r.x && y == r.y;
    }
    bool operator!=(const Point& r){
        return ! (*this == r);
    }
};

#endif