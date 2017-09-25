#include <iostream>

// multiple ways to dereference a string/array/P.O.D. pointer!
// ""[0] == *a
//const char * a = "some string";


void trace(const char & msg = *"") {
    std::cout << __FILE__ << ':' << __LINE__ << ": " << &msg << std::endl;
}

main() {
  trace();
  trace(("hello friends")[0]); // works
  trace(*"hello friends again"); // also works
}