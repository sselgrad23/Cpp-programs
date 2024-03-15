//g++-11 -Wall -o p l50_lambda01.cpp -std=c++2a
#include<iostream>
#include<algorithm>
#include<array>
#include<string_view>
//static bool containsNuts(std::string_view str){return (str.find("nut") != std::string_view::npos);}

template<typename T>T/*auto instead of T cannot be used because type deduction of lambda return type NOT possible*/(*addition)(T,T){ /*lambda*/   [](T a,T b){return(a+b);}  /*lambda*/};

void loop(int cycles,const std::function<void(int)>&fct){for(auto c{0};c<cycles;++c){fct(c);}}
int main()
{

std::cout<<"a lambda expression or lambda or closure allows to DEFINE an anonymous function inside another function (normal function not possible)\n";
std::cout<<"it avoids namespace polution and define the function close to where it is needed\n";
std::cout<<"lambdas are NOT functions, they are functors. A functor is a OBJECT with an overloaded ()operator that makes them callable like a fkt\n";
std::cout<<"lambdas have a return type we can not explicitly use. compiler generate a unique returntype with we cannot use\n";
std::cout<<'\n';
std::cout<<"function pointer initialization with lambda works only with empty capture[]:\n";
/*fctptr for fct with two arguments of type double and return type double */double (*addDoubles)(double,double)/*fctptr*/{ /*lambda*/   [](double a, double b){return(a+b);}  /*lambda*/};
std::cout<<addDoubles(1.2,2.2)<<' '<<addDoubles(100.5,2.7)<<'\n';

std::cout<<"FUNCTION POINTER initialization with template and lambda empyt capture, but template argument MUST BE PROVIDED because\n";
std::cout<<"return type CANNOT be deduced from of lambda return type:\n"; 
std::cout<<addition<double>(10.4,7.7)<<'\n';
std::cout<<addition<int>(10,7)<<'\n';
std::cout<<"initialization of an OBJECT of type deduced from lambda return type, this time NO function pointer\n";
auto /*type deduction for addIntegers of lamda's return type */result_of_add{ /*lambda*/   [](int a, int b){return(a+b);}  /*lambda*/};
std::cout<<result_of_add(12,22)<<' '<<result_of_add(100,27)<<'\n';
std::cout<<"std::function and lambda:\n";
std::function/*<double(double,double)> needed before c++17*/ addi{  /*lambda*/[]/*capture need NOT be empty*/(double a,double b){return a+b;}  /*lambda*/ };  
std::cout<<addi(10.0,20.2)<<'\n';
std::cout<<"another nice example:\n";
loop(5,/*lambda*/[](int i){std::cout<<i<<'\n';}/*lambda*/);

 constexpr std::array<std::string_view, 4> arr{"apple","peach","walnut","cherry"};
// const auto found{ std::find_if(arr.begin(),arr.end(),containsNuts) };
 const auto found{ std::find_if(arr.begin(),arr.end(),[] (std::string_view str){return (str.find("nut") != std::string_view::npos);})};
 if(found == arr.end()) std::cout << "no nuts\n";
 else std::cout << "found " << *found << '\n';
 return 0;
} 
