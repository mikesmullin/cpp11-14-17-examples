#include <iostream>

//void* Animal_vtable[1] = {&Animal::OnDied};

namespace static_way {
  class Animal
  {
    //void * vtable;
    
    public:
      char* name;
      
      virtual void OnDied() {}
      
      Animal() {
        //vtable = &Animal_vtable;
      }
  };
  
  //void* Horse_vtable[1] = {
  //	&Horse::OnDied
  //}
  
  class Horse : public Animal
  {
    
    public:
    
      Horse () {
        //vtable = &Horse_vtable;
      
      }
      
      void OnDied() override {
        // do something
      }
  };
  
  void run() {
      Animal* animal = new Horse();
      animal->OnDied();
  }

}

namespace dynamic_way {
  
  class Animal
  {
    public:
    std::function<void ()> onDied;
    std::string name;
  };
  
  Animal* makeHorse() {
      Animal* animal = new Animal();
      
      Animal* animal2 = new Animal();
      
      animal->name = "Emm?";
      animal->onDied = [&animal, animal2] () {
         printf("%s has died\n", animal->name.c_str());
      };
      return animal;
  }
  
  void run() {
      Animal* animal = makeHorse();
      animal->onDied();
  }

}

int main()
{
  std::cout << "hey";
  
  dynamic_way::run();
  
  return 0;
}