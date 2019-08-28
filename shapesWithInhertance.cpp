//
// Created by Ellis on 28/08/2019.
//

#ifndef GEOMETRICSHAPES_SHAPE_H
#define GEOMETRICSHAPES_SHAPE_H
#include <iostream>
#include "screen.h"
//	point     $
//	elliplse  *
//	polygon   #
//	line      -

class shape{
public:
    explicit shape(int x=0,int y=0){
        this->x = x;
        this->y = y;
    }
    int getX(){ return x;};
    int getY(){ return y;};
    char getSymbol(){ return symbol;};
    void setSymbol(char s){ this->symbol = s; }

    virtual void draw(Screen & scr){
        scr.point(x,y,'x');
    }

    virtual void info(){
        std::cout << "("  << getX() << ", " << getY() << ") ";
    }
    //~shape(){ std::cout << "object deleted" << std::endl;}
private:
    int x;
    int y;
    char symbol = '$';

};

class elipse : public shape{
public:
    explicit elipse(int x=0, int y=0, int xRadius=0,int yRadius=0) : shape(x,y){
        this->xRadius = xRadius;
        this->yRadius = yRadius;
        setSymbol('*');
    }
    int getXradius(){ return xRadius; }
    int getYradius(){ return yRadius; }
    void  draw(Screen & scr) override {
        scr.ellipse(getX(),getY(),xRadius,yRadius,'*');
    }

    void info() override {
        std::cout << "(" << getX() << ", " << getY() << ", " << getXradius() << ", " << getYradius() << ") ";
    }
private:
    int xRadius;
    int yRadius;

};

class polygon : public shape{
public:
    explicit polygon(int x=0, int y=0, int n=0, int l=0) : shape(x,y){
        this->n = n;
        this->l = l;
        setSymbol('#');
    }
    int getSides(){ return n; }
    int getLength(){ return l; }
    void  draw(Screen & scr) override {
        scr.polygon(getX(),getY(),n,l,'#');
    }

    void info() override {
        std::cout << "(" << getX() << ", " << getY() << ", " << getSides() << ", " << getLength() << ") ";
    }

private:
    int n;
    int l;
};

class line : public shape{
public:
    explicit line(int x=0, int y=0, int x2=0, int y2=0) : shape(x,y){
        this->x2 = x2;
        this->y2 = y2;
    }
    int getx2(){ return x2; }
    int gety2(){ return y2; }
    void draw(Screen & scr) override {
        scr.line(getX(),getY(),x2,y2,'-');
    }

    void info() override {
        std::cout << "(" << getX() << ", " << getY() << ", " << getx2() << ", " << gety2() << ") ";
    }
private:
    int x2;
    int y2;
};

#endif //GEOMETRICSHAPES_SHAPE_H
