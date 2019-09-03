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
        if(items > 0) {
            items -= 1;
            list[items] = classType();
        }
    }

    void addFromFile(std::string const & filename,Bunch<shape *> & bunch){
        std::ifstream infile;
        std::string inLine;
        infile.open("shapeTextFiles/" + filename);

        if (!infile.is_open()) {
            std::cerr << "File does not exist, loading data failed!" << std::endl;
            return;
        }

        while (!infile.eof()) {
            // Read a Line from File
            getline(infile, inLine, ' ');
            //std::cout << inLine << std::endl;

            if(inLine.find("point") != std::string::npos){
                //std::cout << "point";
                int x,y;
                infile >> x >> y;
                bunch.push(new shape(x,y));
            } else {
                int x,y,a,b;
                if(inLine.find("elipse") != std::string::npos){infile >> x >> y >> a >> b; bunch.push(new elipse(x,y,a,b));}
                else if(inLine.find("polygon") != std::string::npos){infile >> x >> y >> a >> b; bunch.push(new polygon(x,y,a,b));}
                else if(inLine.find("line") != std::string::npos){infile >> x >> y >> a >> b; bunch.push(new line(x,y,a,b));}
            }
        }
        infile.close();
    }

    void saveToFile(Bunch<shape *> & bunch){
        std::ofstream outFile;
        std::string filename;
        std::cout << "input file name: ";
        std::cin >> filename;
        outFile.open("shapeTextFiles/" + filename);
        for(int i=0;i<bunch.items;i++){
                outFile << bunch[i]->info() << std::endl;
        }
        outFile.close();
    }
};
