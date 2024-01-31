# C++ Notes

Written in short form as a quick reference.

---
## Modern C++

This term refers to the more recent practices, features, and idioms used in C++ programming that have evolved after the introduction of C++11 and subsequent versions (C++14, C++17, C++20, etc.). It embodies a set of programming styles, techniques, and language features that emphasize safer, more expressive, and efficient code.

| Version | Release date | Compatibility | CLI Param |
|-|-|-|-|
| C++23 | Dec 2023 | `g++` `>=11`  | `-std=c++2b` |
| C++20 | Dec 2020 | `g++` `>=9.1` | `-std=c++20` |
| C++17 | Dec 2017 | `g++` `>=7.1` | `-std=c++17` |
| C++14 | Dec 2014 | `g++` `>=4.9.0` | `-std=c++14` |
| C++11 | Aug 2011 | `g++` `>=4.8.1` | `-std=c++11` |

- Windows compiler: `cl.exe` (Visual Studio C++)
- MacOS compiler: `clang` (XCode)

---
## Common libraries
| Include Header | Provides |
|-|-|
| `<iostream>`| `printf()`, `std::cout`, `std::cin`, `std::endl` |
| `<cstdint>` | fixed-width types `u?int(8\|16\|32\|64)_t` |
| `<string>` | `std::string`, `char(8\|16\|32)_t` |
| `<stdexcept>` | common exception types `std::runtime_error` |

---
## Basic compilation

### On Windows
```bash
C:\> cl.exe /nologo /Zi /EHsc /std:c++17 *.cpp
```

### On Linux

```bash
$ g++ -std=c++1z -O0 -S *.cpp -o 
```

---
## Hello world

```cpp
#include <iostream>

void main()
{
  printf("Hello world!");
}
```

---
## Main function

```cpp
#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << "Hello world!" << std::endl;

  // Print command-line arguments
  std::cout << "Number of arguments: " << argc << std::endl;
  for (int i = 0; i < argc; ++i)
  {
    std::cout << "Argument " << i << ": " << argv[i] << std::endl;
  }

  return 0;
}
```

---
## Data types

### Primitive types

Prefer using only the fixed-width integer types from `<cstdint>`.  
Avoid using the native types and their modifiers, whose actual size/range varies by platform and compiler.  
Floating-point types are standardized in precision but not bit size; find your own library that is able to store them as fixed-size integers.

| Native | Modifier | Fixed-width alternatives| Size / Range | Description |
|-|-|-|-|-|
| `int` | Possible | `u?int(8\|16\|32\|64)_t` | Size: At least 16 bits (2 bytes).<br>Range: -32768 to 32767 | integer number |
| `char` | Possible | `char(8\|16\|32)_t`<br>`wchar_t` | Size: Exactly 8 bits (1 byte)<br> Range (signed): -128 to 127<br>Range (unsigned): 0 to 255 | single character |
| `float` ||| Size: Usually 32 bits (4 bytes)<br>Precision: ~6 decimal digits | floating-point number |
| `double` | Possible || Size: Usually 64 bits (8 bytes)<br>Precision: ~15 decimal digits | floating-point number |
| `bool` ||| Size: Usually 8 bits (1 byte)<br>Range: `true` or `false` | boolean value |
| `void` ||| Size: Considered 8 bits (1 byte),<br>but not relevant | absence of data |

#### Type modifiers

| Native | Fixed-width | Size / Range | Description |
|-|-|-|-|
| `unsigned` or || Range: double the positive side<br>of the signed type. | non-negative integer |
| `signed` || Range: default | positive or negative integer (default) |
| `short` or| `u?int16_t` | Size: at least 16 bits (2 bytes). | smaller int variation |
| `long` | `u?int32_t` | Size: at least 32 bits (4 bytes). | larger int variation |
| `long long` | `u?int64_t` | Size: 64 bits (8 bytes). | equivalent to `long long int`<br>and can be signed or unsigned |
| `long double` | | Size: 96 bits (12 bytes). | larger double variation |

### Standard library types (most common)

Many of these collections feature unbound sizes, and will therefore make use of the heap, particularly as they grow.

Obviously there are too many types to list here. You can search for the rest.

| Type | Header Name | Fixed-Size? | Description |
|-|-|-|-|
| `std::string`         | `<string>`        | No  | String of characters, w/ fns for string manipulation. |
| `std::vector`         | `<vector>`        | No  | Array that can be resized. |
| `std::array`          | `<array>`         | Yes | Safer C-style array, w/ bounds checking. |
| `std::unordered_map`  | `<unordered_map>` | No  | Uses a hash table for fast lookups. |
| `std::map`            | `<map>`           | No  | Uses a binary search tree. |
| `std::tuple`          | `<tuple>`         | Yes | Heterogeneous values. |
| `std::set`            | `<set>`           | No  | Ordered set. |
| `std::queue`          | `<queue>`         | No  | FIFO queue. |
| `std::stack`          | `<stack>`         | No  | LIFO stack. |
| `std::list`           | `<list>`          | No  | Doubly linked list. |
| `std::deque`          | `<deque>`         | No  | Double-ended queue; efficient insertion to both ends. |
| `std::bitset`         | `<bitset>`        | Yes | Fixed-size sequence of bits. |
| `std::pair`           | `<utility>`       | No  | Pair of values. |
| `std::function`       | `<functional>`    | No  | Polymorphic function wrapper. Used for FP and callbacks. |
| `std::bind    `       | `<functional>`    | No  | Function object wrapper with placeholders. Used for FP and callbacks. |
| `std::shared_ptr`     | `<memory>`        | No  | Shared ownership smart pointer; prevent memory leaks.
| `std::unique_ptr`     | `<memory>`        | No  | Exclusive ownership smart pointer; prevent memory leaks.
| `std::optional`       | `<optional>`      | No  | Value container; check if empty, without using null.
| `std::variant`        | `<variant>`       | No  | Type-safe union; assign exactly one of several possible types.
| `std::chrono`         | `<chrono>`        | Yes | Precision time value w/ utility functions.
| `std::regex`          | `<regex>`         | No  | Regular expression. |

#### Initialization

```cpp
int8_t i = 5;
float f = 13.2;
bool b = true;
std::vector<char32_t *> c = {U"😇"};
std::map<int, std::string> myMap = {{1, "One"},{2, "Two"},{3, "Three"}};
```

---
## String prefixes

String literals can have various prefixes indicating different character encodings.

| Prefix | Example | Description |
|-|-|-|
| `L` | `L"wide string"` | wide encoding (platform-dependent; not portable)
| `u8` | `u8"UTF-8 string"` | UTF-8 encoding
| `u` | `u"UTF-16 string"` | UTF-16 encoding
| `U` | `U"UTF-32 string"` | UTF-32 encoding
| `R` | `R"raw string"` | ASCII encoding. May not contain escape sequences.

---
## Loops

```cpp
// for loop
for (int i = 0; i < 5; ++i) { /*...*/ }

// range-based for loop
std::vector<int> vec = {1, 2, 3, 4, 5};
for (int num : vec) { /*...*/ }

// while loop
int i = 0;
while (i < 5) {
    ++i;
}

// do-while loop
int i = 0;
do {
    ++i;
} while (i < 5);
```

---
## If...Else statements

```cpp
if (true)
{
}
else if (false)
{
}
else
{
}
```

---
## Ternary operator

```cpp
  bool cond = false;
  char c = cond ? 'a' : 'b';
```

---
## Switch statement

```cpp
switch (choice) {
  case 1:
    std::cout << "You chose option 1." << std::endl;
    break;
  case 2:
    std::cout << "You chose option 2." << std::endl;
    break;
  case 3:
    std::cout << "You chose option 3." << std::endl;
    break;
  default:
    std::cout << "Invalid choice." << std::endl;
    break;
}
```

---
## Functional programming & Lambdas

```cpp
#include <iostream>
#include <functional>

// (A) Receive function pointer
void PerformOperation1(int a, int b, int (*callback)(int, int))
{

  int result = callback(a, b);
  std::cout << "Result: " << result << std::endl;
}

// (B) Receive std::function
void PerformOperation2(int a, int b, std::function<int(int, int)> callback)
{

  int result = callback(a, b);
  std::cout << "Result: " << result << std::endl;
}

// (C) Receive std::bind
void PerformOperation3(std::function<int()> callback)
{
  int result = callback();
  std::cout << "Result: " << result << std::endl;
}

int Add(int x, int y)
{
  return x + y;
}

int main()
{
  // (A) Pass existing fn pointer
  PerformOperation1(5, 3, Add);

  // (B) Pass lambda fn
  PerformOperation2(5, 3, [](int x, int y) { return x + y; });

  // (C) Pass existing fn with std::bind to encapsulate arguments
  PerformOperation3(std::bind(Add, 5, 3));

  return 0;
}
```

---
## Classes

Here's an example of class inheritance in C++ using a base class Animal, 
and subclasses Bat and Cat that inherit from Animal 
and override the sound field via their constructors:

```cpp
class Animal
{
protected:
  std::string sound;

public:
  Animal(const std::string &animalSound) : sound(animalSound) {}

  void makeSound() const
  {
    std::cout << "Sound: " << sound << std::endl;
  }
};

class Bat : public Animal
{
public:
  Bat() : Animal("Echolocation") {}
};

class Cat : public Animal
{
public:
  Cat() : Animal("Meow") {}
};

int main()
{
  Bat bat;
  Cat cat;

  std::cout << "Bat: ";
  bat.makeSound();

  std::cout << "Cat: ";
  cat.makeSound();

  return 0;
}
```

---
## Exception handling

```cpp
#include <iostream>
#include <stdexcept>

void main()
{
  try
  {
    throw std::runtime_error("Example error");
  }
  catch (const std::exception &ex)
  {
    std::cout << "Exception caught: " << ex.what() << std::endl;
  }
}
```

---
## Preprocessor Directives and Macros

The preprocessor in C++ is a stage of compilation that processes the source code before actual compilation. It handles directives prefixed with `#`, manipulating the code based on these directives before the code is compiled.

- `#define`: Defines macros with a specified name and value or code snippet. Can be written like a function, or a simple string replacement. It is used to replace occurrences of the defined macro with its corresponding value or code during preprocessing. It enhances code readability, enables code reuse, and facilitates conditional compilation.  
  ```cpp
  #define PI 3.14159
  #define SQUARE(x) ((x) * (x))

  int main() {
      double radius = 5.0;
      double area = PI * SQUARE(radius); // Replaced with 3.14159 * ((5.0) * (5.0))
      return 0;
  }
  ```

- `#include`: Inserts contents of other files into the current file. (Literally just string replacement.)  
  ***NOTICE:** This is an important difference from the import systems of other languages, such as CommonJS in Node.JS, or the ClassLoader in Java.*
  - In cpp, the compiler treats all files equally
    - header/source distinctions and matching names are irrelevant/organizational (ie. for IDE, static analysis, etc.)
  - `#include` directives get replaced with file contents, exactly like a string template system.
    - "translation unit" refers to a source file along with all its included header files
    - you get exactly one `.obj` for each file named on the cli, not for the file tree they may `#include`.
  - `#include` can occur anywhere in file, very top is merely for organization.
  - each `#include` causes multiple code injections in final program; use guards (`#pragma once`, `#ifndef`).
    - you can test this with compiler-specific debug features:
      - win `cl.exe`: `#pragma message("compiler stdout will contain this...")`
      - nix `gcc`: `#pragma message "compiler stdout will contain this..."`
      - mac `clang`: `#warning "compiler stdout will contain this..."`
  - Declarations may be repeated (no compiler error).
    - A "forward declaration" is one that allows you to refer to it before it has been defined. 
      - This feature is required to achieve circular dependencies.
  - Definitions may not appear before declarations ("unresolved symbol").
  - Definitions must not be repeated ("already defined").
  - Declarations are not matched to their definitions until the linker phase.
    - By default, all symbols are accessible/linkable outside of their translation unit unless `static` keyword is used. (has this special meaning when used outside of classes)
      - C++20 introduces the `module`, `import`, `export` keywords; these help avoid global namespace pollution.
  - `#include <>` (angle bracket) syntax searches std lib, system dirs, and include paths (intended for third-party/vendored headers).
  - `#include ""` (double-quote) syntax searches current directory, then include path (intended for project or user-authored headers).

---
## Memory management

- How RAII avoids memory leaks
  - Overriding/deleting class methods:
    - default/parameterized/copy/move constructors
    - destructor
    - copy/move assignment operator
- Lifetime/Ownership considerations
  - When to pass a fn parameter as a pointer
  - When and how to return a pointer
  - When and how to use smart pointers
  - My opinionated approach (simplifies choices)

---
## Data Oriented Design/Programming (DOD)

Principles:
1. Separate code from data
   - FP: stateless "pure" functions
2. Everything is a list (lisp) tree
   - optimize for L1+L2+L3 cache (ie. 64B cache lines, prefetcher)
   - design for a target (ie. GPU)
3. Use Immutable data structures
   - FP: no side-effects
   - thread-safe sharing
4. Data schema becomes enforced at runtime vs. compile time

---
## References
- https://en.cppreference.com/w/
