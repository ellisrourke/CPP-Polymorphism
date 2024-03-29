//
// Created by Ellis on 28/08/2019.
//
#include <iostream>
#include "screen.h"
#include "shapesWithInhertance.cpp"
#include "bunchPointer.cpp"

int main(){
    Screen myscreen;
    myscreen.axes('+');
    Bunch<shape *> bunch;

    //bunch.addFromFile("myShapes.txt",bunch);
    //bunch.saveToFile(bunch);

    int select = 0;

    std::cout << "1: draw point\n2: draw elipse \n3: draw polygon\n4: draw line\n5: show info\n6: display shape\n7: clear screen\n8: read shapes from file\n9: save to file\n10: pop shape\n";

    while(select!=-1){
        std::cout << "-> ";
        std::cin >> select;
        switch(select){
            case 1 : { //add a point to bunch
                int x, y;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                bunch.push(new shape(x,y));
                break;
            }
            case 2 : { //add an elipse to bunch
                int x, y, xR, yR;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter X radius:";
                std::cin >> xR;
                std::cout << "enter Y radius:";
                std::cin >> yR;
                bunch.push(new elipse(x,y,xR,yR));
                break;
            }
            case 3 : { // add a polygon to polygon bunch
                int x, y, n, l;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter number of sides:";
                std::cin >> n;
                std::cout << "enter side length:";
                std::cin >> l;
                bunch.push(new polygon(x,y,n,l));
                break;
            }
            case 4 : { //add a line to line bunch
                int x, y, x2, y2;
                std::cout << "enter X:";
                std::cin >> x;
                std::cout << "enter Y:";
                std::cin >> y;
                std::cout << "enter X2:";
                std::cin >> x2;
                std::cout << "enter Y2:";
                std::cin >> y2;

                bunch.push(new line(x,y,x2,y2));
                break;
            }
            case 5 : { //display shape index ,type and parameters
                for(int i=0;i<bunch.items;i++){
                    std::cout << bunch[i]->info();
                    std::cout<< " " <<std::endl;
                }
                break;
            } case 6 :{ //display a shape given bunch index
                int index=0;
                std::cout << "select index (-1 for all)";
                std::cin >> index;
                if(index==-1){
                    for(int i=0;i<bunch.items;i++)
                        bunch[i]->draw(myscreen);
                } else {
                    bunch[index]->draw(myscreen);
                }
                myscreen.display();
                break;
            } case 7 : {//clear screen
                myscreen.clear();
                myscreen.display();
                break;
            } case 8 : {// add shapes from file to bunch
                std::string filepath;
                std::cout << "enter filename: ";
                std::cin >> filepath;
                bunch.addFromFile(filepath,bunch);
                break;
            } case 9 : {//save bunch to file
                bunch.saveToFile(bunch);
                break;
            } case 10 : {
                bunch.remove();
                break;
            }
            default:{break;}
        }
    }







}