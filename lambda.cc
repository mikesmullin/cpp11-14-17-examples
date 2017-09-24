#include <iostream>
#include <functional>
#include <string>

class Animal
{
  public:
    std::function<void()> onDied;
    std::string name;
};
  
Animal* makeHorse() {
  Animal* animal = new Animal();
  
  std::string hi = "hi";
  
  animal->name = "Emm?";
  animal->onDied = [animal /*pointer to an animal will be copied*/, &hi /*will be stored as a reference to a stack variable, which is dangerous, since the lifetime of the hi-string is way too short in comparison to the lifetime of the closure*/] () {
     printf("%s has died\n", animal->name.c_str());
  };
  return animal;
}


int main()
{
  // see also: http://en.cppreference.com/w/cpp/language/string_literal
  const char* t = R"===(
    Лорем ипсум долор сит амет, ут вис омнис демоцритум сцрипсерит, вим ут сонет граеце, еам ех дицат фиерент репрехендунт.
    Дуо деленит сапиентем те. Путант ассентиор при те, вертерем улламцорпер еам ет, ан еос ассум примис цотидиеяуе. Нострум 
    еффициенди меи те, еррор вулпутате ид иус. Ин яуи еррор долоре иисяуе, нонумес инцидеринт еа хас, вис партем фабулас ан.
  )===";
  
  Animal* animal = makeHorse();
  animal->onDied();
  
  delete animal; // old cpp
  
  return 0;
}