#include <stdlib.h>

// these C++ templates are similar to Haskell
// this compiles down to just the main() function with an integer literal in ASM
template<unsigned int n>
struct Factorial {
    enum { value = n * Factorial<n-1>::value};
    static int b;
};

template<unsigned int n>
int Factorial<n>::b = rand();

template<>
struct Factorial<0> {
    enum {value = 1};
};

int main() {
    return Factorial<5>::value + Factorial<5>::b;
}