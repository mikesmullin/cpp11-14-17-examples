#include <iostream>
#include <functional>
#include <string>
#include <memory>


// see also: Boost 
// http://www.boost.org/doc/libs/1_52_0/boost/smart_ptr/intrusive_ptr.hpp

// beware reading MSFT STL implementation; its difficult to read
// easier to read Boost or GNU STL (standard template library) code  

class Animal
{
  public:
    std::function<void()> onDied;
    std::string name;
};

void assign(std::shared_ptr<Animal>& ptr, const std::shared_ptr<Animal>& right) {
  ptr.decrement(); 
  ptr.raw_assign(right.get_raw());
  ptr.increment();
}
  
std::shared_ptr<Animal> makeHorse() {
  
  std::shared_ptr<Animal> animal = std::make_shared<Animal>(); // +1
  
  auto c = animal; // +2
  c = animal; 
  
  // +2
  // 2 - 1
  // 1 + 1
  
  
  std::shared_ptr<Animal> animal2 = animal; // +2
  std::shared_ptr<Animal> animal3 = animal; // +3
  
  std::string hi = "hi";
  
  animal->name = "Emm?";
  animal->onDied = [animal /*pointer to an animal will be copied*/, &hi /*will be stored as a reference to a stack variable, which is dangerous, since the lifetime of the hi-string is way too short in comparison to the lifetime of the closure*/] () {
     printf("%s has died\n", animal->name.c_str());
  };
  return animal;
}

int main()
{
  std::shared_ptr<Animal> animal = makeHorse();
  animal->onDied();
  
  
  return 0;
}