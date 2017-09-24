#include <iostream>
#include <functional>
#include <string>
#include <memory>

class Animal
{
    public:
    
        Animal(int age) {
            printf("Animal constructor\n");
        }
        
        void deleteMe() {
            // invoke something before that
            
            try {
                delete this;
            }
            catch(void* e /*some exception*/) {
                
            }
        }
        
        virtual ~Animal() {  printf("Animal destructor\n"); }
        
        std::function<void()> onDied;
        std::string name;
            
        virtual void eat() {
            printf("i like to eat nothing\n");
        }
            
};

// virtual table (per type)
//          | Animal |   ?   |
// ---------------------------
// |  ()    |        |   *   |
// | eat()  |   *    |       |
// | ~()    |        |   *   |
//   ...
//

//class Cacher {
//    public:
//    
//      MixIn(const std::string& keyToCacheData);
//    
//      const std::string& cachedData();
//    
// };

class Horse : public Animal //, protected Cacher
{
    public:
        std::string second_name;
    
    Horse() : Animal(20)/*, Cacher("")*/ {
    }
    
    Horse(int age) : Animal(age) {
        printf("Horse constructor\n");
    }
    
    //const std::string& getname() {
    //    return cachedData();
    //}
    
    void eat() {
        printf("i like to eat oats and carrots\n");
    }
        
    ~Horse() override { printf("Horse destructor\n"); }
};


struct X {
    public:
        void a() {}
        virtual void b() {}
        virtual void c() {}
        
        static void a_alternative(X* z) {
            
        }
};


int main() {
    Animal* animal = new Horse();
    
    X* x = new X();
    X& xlink = *x;
    //const X* xlink = *x; // allowed to change pointer address but not value
    //X * const xlink = *x; // not allowed to change pointer, but can change value
    //X& xlink = *x; // not allowed to change pointer
    //const X * const xlink = *x; // not allowed to change pointer and value
    //const X& xlink = *x; // not allowed to change pointer and value
    
    //X ** xlink = &x;
    //(*xlink)->method();
    //(**xlink).method();
    std::cout << "sizeof new X " << sizeof(xlink) << std::endl;
    
    animal->eat();
    
    delete animal; // ~Horse() or ~Animal() ?? 

    return 0;
}