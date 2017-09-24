#include <iostream>
#include <typeinfo>
#include <array>
//using namespace std;


std::string doSomething( std::string& data) {

    std::string newLargeData;
    
    
    return newLargeData;
}

main() {
    
    // what are all the ways to define a string?
    
        // single character (1 byte)
    char a = 'c';
    std::cout << a << std::endl;
    
    // array or 'string' of char
    // pointer to a constant array of characters
    // points to first character in the array
    // lives as static in vtable in memory
    const char* b = "def"; // implicitly appended with \0
    // const char* is not as safe; preferred to use std::string
    // the string may be optimized out of the final binary if no references to it
    std::cout << b << std::endl;
    
    // pointer to array of string
    //const char** argv = {"cheese"};
    
    
    
    // makes copy and allocates new memory
    std::string str_b = b; // utf8
    // str_b[N] is safer than b[N] because std::string is overloaded with index 
    // access operator to test whether index is in bounds or not; will throw oob
    // error/exception
    
    // literal string; constant/immutable, static in memory
    // the custom delimiter is required; ===( in this case
    const char* f = R"===(ghshs)===";
    
    /* wide character (2 bytes) literal, e.g. L'β' or L'貓'.
    Such literal has type wchar_t and the value equal to the value of c-char in the execution wide character set.
    If c-char is not representable in the execution character set 
    (e.g. a non-BMP value on Windows where wchar_t is 16-bit), the value of the literal is implementation-defined.
    */
    const wchar_t* c = L"早上好"; // equivalent to utf-16 (not big enough for utf-32)
    // sizeof(wchar_t) is 2 bytes
    // Windows uses wide characters everywhere. Linux uses more utf8.
    // it's best to use utf8 as it's ASCII compatible, 
    
    
    std::cout << "早上好" << " " << c << " " << typeid(c).name() << std::endl;
    
    // nowdays people don't dare to use C arrays like this one
    int c_array[] = {0,2,3};
    // its much safer to use std::array for oob checking
    std::array<int, 3> std_array = {1,3,2};
    
    std::string utf_eight = u8"早上好";
    //utf_eight[1] won't a second symbol
    
    // all std::string are mutable unless they are const
    // they are not complicated; just an array of characters
    const std::string* bar = "hi";
    
    
    
    std::cout << "hello";
}