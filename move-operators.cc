#include <iostream>
#include <string>

#pragma GCC push_options
#pragma GCC optimize ("no-elide-constructors")

class copyable {
      
public:
  std::string _a;
  
//public:

  copyable(const std::string& a) : _a(a) {
      std::cout << "creating a copyable" << _a << std::endl;
  }

  copyable(const copyable& other) : _a(other._a) {
    std::cout << "copying a copyable" << _a << std::endl;
  }
   
  
  copyable& operator = (const copyable& other) {
    _a = other._a;
    std::cout << "copying a copyable" << _a << std::endl;
    return *this;
  }
  
  // this part is new c++
   
copyable( copyable&& other) : _a(std::move(other._a)) {
    std::cout << "moving a copyable" << _a << std::endl;
  }
   
  copyable& operator = ( copyable&& other) {
    _a = std::move(other._a);
    std::cout << "moving a copyable" << _a << std::endl;
    return *this;
  }
};

copyable returnACopy() {
  
  copyable object ("1");
  //auto other = object;
  return object;
}

int main() {
  //auto copy = returnACopy();
  
  //std::cout << "returnACopy has return" << copy._a;
  
  //std::string a;
  NULL 0 (void*)0
}

