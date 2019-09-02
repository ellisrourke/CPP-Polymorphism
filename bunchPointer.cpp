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

    void push(classType cl){
        items+=1;
        list[items - 1] = cl;
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
        list[items] = classType();
    }

    void addFromFile(std::string const & filename,Bunch<shape *> & bunch){
        std::ifstream infile;
        std::string inLine;
        infile.open("shapeTextFiles/" + filename);

        if (!infile.is_open()) {
            std::cerr << "File does not exist, loading data failed!" << std::endl;
            return;
        }

        while (infile) {
            // Read a Line from File
            getline(infile, inLine, ' ');
            if(inLine == "point"){
                std::cout << "point";
                int x,y;
                infile >> x >> y;
                bunch.push(new shape(x,y));
            } else {
                int x,y,a,b;
                if(inLine == "elipse"){infile >> x >> y >> a >> b; bunch.push(new elipse(x,y,a,b));}
                else if(inLine == "polygon"){infile >> x >> y >> a >> b; bunch.push(new polygon(x,y,a,b));}
                else if(inLine == "line"){infile >> x >> y >> a >> b; bunch.push(new line(x,y,a,b));}
            }
        }
    }

};
