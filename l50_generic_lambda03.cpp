//g++-11 -Wall -o p l50_generic_lambda03.cpp -std=c++2a
#include<algorithm>
#include<vector>
#include<iostream>
#include<string_view>
int main(){
std::cout<<"Programm shows that one generic lambda expression produce more than one function:\n";
std::cout<<"here are three functions one for strings, one for floats and one for integers.\n";
std::cout<<"print is a lambda variable and is initialised with an lambda definition\n";
auto print{[](auto value){static int callcount{0};std::cout<<callcount++<< ": "<<value<<'\n';}};
print("hello ");
print("world ");
print(1.2f);
print(2.3f);
print(2);
print(2);
print(2);
print(2);
std::cout<<print("black");

return 0;
}
