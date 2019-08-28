#include <iostream>
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

    void push(classType &x){
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

};
