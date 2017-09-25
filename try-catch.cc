#include <iostream>

struct MyError {
private:
    const char * description;
    const int32_t lineNo;
public:
    MyError(const char * description, int32_t lineNo)
        : description(description)
        , lineNo(lineNo)
    {
    }
    const char * get_description() const {
        return this->description;
    }
};

class A {char& a; char& b;};

main () {
    const char a = 'h';
    const char & b = a;
    std::cout << "64 bit arch? " << (sizeof(void*) == 8) << std::endl;
    std::cout << "size is " << sizeof(A) << std::endl;
    
    //instead of int or unsigned int - int32_t or uint32_t 4 bytes size guaranteed
    //instead of long - int64_t or uint64_t 4 bytes size guaranteed
    
    try {
        //throw MyError("some description", 20);
        throw 33u;
        throw "hello";
    }
    catch (const MyError & e) {
        std::cout << "exception caught (MyError): " << e.get_description() << std::endl;
    }
    catch (const int e) {
        std::cout << "exception caught (int): " << e << std::endl;
    }
    catch (const char e) {
        std::cout << "exception caught (string): " << e << std::endl;
    }
    // only std exceptions are catch-all here; 
    // there is no catch-all for primitives or custom types
    catch (const std::exception & e) {
        std::cout << "exception caught (std::exception): " << std::endl;
    }
    catch (const unsigned int e) {
        std::cout << "exception caught (unsigned int): " << e << std::endl;
    }
    catch (...) {
        std::cout << "exception caught (unknown type)." << std::endl;
    }
}
