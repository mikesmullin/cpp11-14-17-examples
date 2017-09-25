#include <iostream>

// the A is like an interface here
// also like an abstract class in Java
// it cannot be instantiated; only its base
// class may be instantiated.
// and the sub classes are required to implement
// the pure virtual functions of the base class.

class A {
    virtual int area() = 0;
    
    // if you are going to have pure virtual interfaces
    // (even if the area function is implemented, in most cases you have to also provide
    // a virtual destructor)
    // in a base class, then you need to also provide
    // a virtual destructor, or the sub class destructor
    // will not be invoked in all cases.
    public:
    virtual ~A() = 0;
};

// see also: http://en.cppreference.com/w/cpp/language/destructor
A::~A() {} // pretty tricky

class B : public A {
    int area () override {
        return 1;
    }
    public:
    ~B() override {};
};


main (){
  B b;
  
  b.A::~A();
}