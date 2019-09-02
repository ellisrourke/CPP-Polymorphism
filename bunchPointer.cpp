#include <iostream>
#include <fstream>
#include "shapesWithInhertance.cpp"
template <class classType> class Bunch{
public:
    //classType list;
    int items;
    const int cap = 32;
    classType *list;

    Bunch(){
        items = 0;
        list = new classType[cap];
    }

    classType &operator[](int i){return list[i];}

    void push(classType x){
        items+=1;
        list[items - 1] = x;
        //std::cout << this->items << std::endl;
    };

    classType nextPop(){
        return list[items-1];
    }

    void display(){
        for(int i=0;i<items;i++){
            list[i].info();
        }
        std::cout << std::endl;
    }

    //not working
    void remove(){
        items-=1;
        items[list] = classType();
    }

    void addFromFile(std::string const& infile){
        std::ifstream fin;
        std::string line;
        fin.open(infile);
        std::cout << "test" << std::endl;

        while (fin) {
            // Read a Line from File
            getline(fin, line);
            // Print line in Console
            std::cout << line << std::endl;
        }

    }

};
