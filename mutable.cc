#include <iostream>

int d = 4;

class A {
    public:
        int a = 4;
        
        // mutable here means that
        // any const functions 
        // are allowed to mutate this
        // instance variable, as 
        // an exception to the rule
        mutable int b = 0;
        
        // const here means that 
        // this function may not mutate
        // any instance variable;
        // it can however mutate local
        // and global variables
        int getData() const {
            int c = 2;
            d = 5;
            if (b == 0) {
                b = a * a; // retrieve and cache the data: like DB::getData(this)
            }
            
            return b;
        }
        
        static const int ConstCompileTimeGlobalVar = 3;
        // mutable global var
        static int globalVar;
        
        // static func
        static A& singleton() {
            // instantiated on first pass only
            // preserved between passes.
            // in threading applications, the first
            // thread instantiates, and the other threads
            // are blocked until it is complete,
            // then they share the same space in memory.
            // in old cpp standard and old vsstudio (like 2013) impl
            // the use of this case is not thread safe.
            static A instance;
            return instance;
        }
};

int A::globalVar = 3;

// `static` keyword has unconventional meaning 
// in global context; it means
// visible in mutable.cc only, cannot be exported via extern
static int LocalVar4;


struct PODExample {
    int a;
    float b;
};

struct PODExample2 {
    PODExample a;
    bool t;
};

main() {
   // P.O.D. Plain old data?
   // pointer, float, bool, int, enum, static struct/class
   // new instance? no
   // std::string? no. its complex class; cuz it has constructor + destructor
   // 
   
   std::vector<A> list;
   for (var i=0;i<Math.random();i++) {
       A b; // how is this allocated on stack
       list.push_back(b); // b will be copied into the list
   }
   
   
   //A* a = new A(); // allocate space in heap, and instantiate
   //A a_stack; // allocate space in stack, and instantiate
   int var; // 4 bytes on stack allocated but value is unknown
   //int var;
   //a.getData();
   
   PODExample var2[] = {
       {0xA, 1.2f},
       {0xAB, 3.14156f}
   };
   
   std::cout << var2[0].b;
}