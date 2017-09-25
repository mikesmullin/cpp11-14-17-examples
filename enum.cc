#include <iostream>

enum {
  X,
  Y,
  Z
};


// old enum
// can be casted to integer
enum Enum1 {
  A,
  B,
  C
};

// new enum
// cannot be cast
enum class Enum2 {
  A,
  B,
  C
};

main() {
    
    std::cout << Z << std::endl;
    
    // can we use pattern matching?
    
    Enum1 e1 = A;
    switch (e1) {
        case 0: // can be compared by an int or another enum
            printf("e1 case A\n");
            break;
        // i'm expecting an exception to be thrown
        // because we didn't provide cases
        // for B and C here and if there is no default
        default:
            printf("default case\n");
            break;
    }
    
    Enum2 e2 = Enum2::A;
    switch (e2) {
        //case 0: // can only be compared to its own type
        case Enum2::A:
            printf("e2 case A\n");
            break;
    }
    
    std::cout << "hello";
}