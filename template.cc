#include <iostream> 
//#include <type_traits>

// template<bool B, class T = void>
// struct F {
// };
 
// template<class T>
// class F<true, T> {
// public:
//     using z = T;
    
//     struct C {
        
//     };
// };



//template <typename T, class = typename std::enable_if< std::is_integral<T>::value, void >::type>
//template <int t>
template <int T>
void a() {
     std::cout << "you gave me any integer " << T << std::endl;
}

template <>
void a<2>() {
     std::cout << "you gave me two" << std::endl;
}

int main() {
    // F<false> f;
    
    //F<false>::z z;
    // F<true>::C c;
    
    a<2>();
    a<33>();
    
    // a<0>();
    
    // a('c');
    // a('d');
    // std::cout << "hello" << std::endl;
    return 0;
}