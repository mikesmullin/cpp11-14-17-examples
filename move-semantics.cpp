//
// |                     |            | user-defined op    |                |                 |                |                                                                                       |
// |---------------------|------------|--------------------|----------------|-----------------|----------------|---------------------------------------------------------------------------------------|
// | syntax              | default op | Y move, N copy     | N move, Y copy | Y move, Y copy  | N move, N copy | notes                                                                                 |
// |---------------------|------------|--------------------|----------------|-----------------|----------------|---------------------------------------------------------------------------------------|
// | b = a               | copy       | user move, or      |                |                 |                |                                                                                       |
// |                     |            | gcc compiler error | user copy      | user copy       | default copy   | you cannot accidentally get a move when you intended a copy (would be lossy)          |
// | b = std::move(a)    | move       | user move          | user copy      | user move       | default move   | you can accidentally get a copy when you intended a move (inefficient, but not lossy) |
// | b = A()             | move       | user move          | user copy      | user move       | default move   | you can accidentally get a copy when you intended a move (inefficient, but not lossy) |
// 
// conclusion:                                                                         
// - explicit move/copy behavior can behave unexpectedly if user-defined ops are present.
//

#include <iostream>

using namespace std;

class A
{
public:
   int i = 123;

    //A() = default;
    A()
    {
        cout << "constructor called." << endl;
    }
    
    A(const A& a) // copy constructor
    {
        cout << "copy constructor called." << endl;
    }
    
    A(A&& a) // move constructor
    {
        cout << "move constructor called." << endl;
    }
    
    A& operator=(const A& a)
    {
        cout << "copy assignment operator called." << endl;
        return *this;
    }
    
    // A& operator=(A&& a)
    // {
    //     cout << "move assignment operator called." << endl;
    //     return a;
    // }
    
    ~A()
    {
        cout << "destructor called." << endl;
    }

};

A MakeA() {
    cout << "d" << endl;
    A a;
    cout << "e a.i:" << a.i << endl;
    return a; // RVO (Return Value Optimization; a is actually allocated in caller, so no move/copy/destructor is necessary here)
}

int main() {
    cout << "a" << endl;
    auto a = MakeA();
    cout << "b a.i:" << a.i << endl;
    //A b = a;
    A b;
    //b = a; // copy assign
    b = std::move(a); // move assign
    // b = A(); // move assign
    
    cout << "c b.i:" << b.i << " a.i:" << a.i << endl;
    cout << "done." << endl;
}
