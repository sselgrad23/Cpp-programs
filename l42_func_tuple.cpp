//g++-11 -Wall -o p l42_func_tuple.cpp -std=c++2a
#include<iostream>
#include<tuple>
std::tuple<int,double,char>fkt(){return {2,66.88,'c'};}
int main()
{
 std::cout << "reduce work with struct. better use a struct, or best call by ref\n";
 auto[i,d,c]{fkt()};
 std::cout << i << ' ' << d << ' ' << c << ' ' << '\n';
 int x{};
 double y{};
 char z{};
 std::tie(x,y,z)=fkt();

 std::cout << --x << ' ' << y*2 << ' ' << ++z << ' ' << '\n';
 return 0;
} 
