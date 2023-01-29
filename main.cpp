//
//  main.cpp
//  ООП ДЗ 17 Множественное наследование
//
//  Created by Павел on 29.01.2023.
//



/*
 При ромбовидном  наследовании  может возникнуть неоднозначность: если объект класса D вызывает
 метод, определенный в классе A (и этот метод не был переопределен в классе D), а классы B и C
 по-своему переопределили этот метод, то от какого класса его наследовать: B или C?
 Чтобы сгенерировать ромбовидную структуру наследования, необходимо воспользоваться виртуальным
 наследованием класса A на нескольких путях наследования: если оба наследования от A к B и от A к C
 помечаются спецификатором virtual ( class B : virtual public A),то C++  проследит
 за созданием только одного подобъекта A, и использование членов A будет работать корректно.
 */
#include <iostream>

class A{
public:
    A(int num):_num(num){
        std::cout<<"Конструктор А"<<std::endl;
    }
    int getNum(){
        return _num;
    }
private:
    int _num;
};



class B : virtual public A{
public:
    B(int num, int X): A(num),_X(X){
        std::cout<<"Конструктор B"<<std::endl;
    }
private:
    int _X;
};



class C : virtual public A{
public:
    C(int num, int Y): A(num),_Y(Y){
        std::cout<<"Конструктор C"<<std::endl;
    }
private:
    int _Y;
};


class D : public B,C{
public:
    D( int num, int X, int Y, int res) : B(num, X),C(num, Y), _res(res), A(num){
       std::cout<<"Конструктор D"<<std::endl;
    }

      private:
      int _res;
    
};



int main(int argc, const char * argv[]) {
    D one(10,1,2,3);
    std::cout<<one.getNum()<<std::endl;
    
    
    
    
    return 0;
}
