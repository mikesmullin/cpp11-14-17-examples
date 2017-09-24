#include <iostream>

class A {
    private:
        int d;
        friend class B;
};

class B {
    public:
        void accessToA() {
            A a;
            a.d = 10;
        }
};

class C {
    private:
        friend void e();
        void memberFn() {}
};


void e() {
    C c;
    c.memberFn();
}

main () {
    e();
    B b;
    b.accessToA();
}
