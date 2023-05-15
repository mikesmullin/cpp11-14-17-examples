// see also: https://youtu.be/xnqTKD8uD64?t=961

#include <iostream>
#include <memory>

using namespace std;

struct A
{
    int i = 123;
    
    A()
    {
        cout << "construct" << endl;
    }
    
    A(const A& a)
    {
        cout << "copy construct a.i:" << a.i << endl;
    }
    
    A(A&& a)
    {
        cout << "move construct a.i:" << a.i << endl;
    }
    
    A& operator=(const A& a)
    {
        cout << "copy assign a.i:" << a.i << endl;
        return *this;
    }
    
    A& operator=(A&& a)
    {
        cout << "move assign a.i:" << a.i << endl;
        return a;
    }
};


void FTest(A& a) {
    cout << "FTest a.i:" << a.i << endl;
    a.i = 2;
}

int main() {
    auto a = make_unique<A>();
    FTest(*a);
    cout << "done. " << a->i << endl;
}
