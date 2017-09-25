#include <iostream>
#include <algorithm>

using namespace std;

// $ g++-7 -std=c++1z -o cpp17 cpp17.cc
// $ ./cpp17
// 2 uppercase letters in: Hello World!


// these two begin() and end() functions are already provided by cpp
// but we explain how they work here; they are compile-time template expressions
// which benefit from knowing the constant length of an array at compile time
template<typename T, int N>
constexpr const T* end(const T (&t)[N]) {
    return &t[N];
}

template<typename T, int N>
constexpr const T* begin(const T (&t)[N]) {
    return &t;
}

int main()
{
    char s[] = "Hello World!"; // this version preserves the length of the array with the type
    //char * s = "Hello World!"; // this version loses the context on the left-hand side about the constant length/upper-bound of the array

    // the issue with the original example is that sizeof(some_array)
    // is not equal to the count of the elements in the arrray
    wchar_t s_wide[] = L"Hello World!"; // sizeof (s_wide) is (2 bytes * amount of chars) and != lenght of the array

    int count = 0; // modified by the lambda
    for_each(begin(s), end(s), [&count] (auto c) {
        if (isupper(c))
            count++;
    });
    cout << count << " uppercase letters in: " << s << endl;
}