//
// Created by Ellis on 28/08/2019.
//
#include <iostream>
#include "screen.h"
#include "shapesWithInhertance.cpp"
#include "bunchPointer.cpp"

int main(){
    Screen myscreen;
    Bunch<shape*> bunch;

    shape p(1, 2);
    elipse e(5,5,10,10);

    bunch.push(&p);
    bunch.push(&e);

    for(int i=0;i<bunch.items;i++){
        bunch[i]->draw(myscreen);
    }
    myscreen.display();



}