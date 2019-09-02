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
    elipse e;
    shape p(1, 2);


    bunch.push(&p);
    bunch.push(&e);

    for(int i=0;i<bunch.items;i++){
        bunch[i]->info();
    }
    myscreen.display();



}