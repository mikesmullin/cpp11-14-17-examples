#include <iostream>


  class Animal
  {
    const char* name();
  };
  
// good use of inheritance: Horse is an animal
  class Horse : public Animal
  {
  };
  
  class Eyes {
      int color();
  };
  
  class IHasOwner {
      int owner();
  };
  
  // bad use of inheritance: Goat is not a parts of a body
  class Goat : public Animal, public Eyes, public LeftLeg, public Ears
  {
  };
  
    // Use composition
  class Goat_Composition : public Animal, public IHasOwner
  {
      Eye eye[2];
      Ear ears[2];
      Leg legs[4];
  };

main() {
    printf("whatup");
    
    Goat goat;
    goat.color(); // Bad usability: what the hell the color is?
    
}