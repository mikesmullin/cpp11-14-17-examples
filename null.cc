#include <iostream>

//#define NULL 0 // defined by default

struct zero_t{};

using nullptr_t = decltype(nullptr);


void doSomethingA(std::nullptr_t b){
    std::cout << "doSomething(nullptr_t)" << std::endl;
}

void doSomethingB(zero_t a) {
    std::cout << "doSomething(zero_t)" << std::endl; 
}

main() {
    // different ways of null
    nullptr; // treated special by C++. It's type is std::nullptr_t

    
    // (void*)0
    //
    
    const std::string str = "bar";
    // str[0] returns const char&
    str[0] = 'B';
    std::cout << str << std::endl;
    
    doSomethingA(nullptr);
    doSomethingB(zero_t{});

}