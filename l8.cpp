// g++ -Wall -o q l8.cpp -std=c++11
#include<iostream>
#include<cstdint>/*for fixed width*/
#include<cmath>/*abs*/
#include<algorithm>/*max*/
bool approximatelyEqual(double a, double b, double epsilon)
{
 return(std::abs(a-b)<=(std::max(std::abs(a),std::abs(b))*epsilon));
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
 double diff{std::abs(a-b)};
 if( diff<= absEpsilon)return true;



 return(std::abs(a-b)<=(std::max(std::abs(a),std::abs(b))*relEpsilon));
}

int main(){
double a{0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1};
std::cout << approximatelyEqual(a, 1.0,1e-8) <<'\n';/*compare almost 1.0 to 1.0*/
std::cout << approximatelyEqual(a-1.0, 0.0,1e-8) <<'\n';/*compare almost 0.0 to 0.0*/
std::cout << approximatelyEqualAbsRel(a-1.0, 0.0,1e-12,1e-8) <<'\n';/*compare almost 0.0 to 0.0*/
int x{5};
int y{6};
if(!(x>y))std::cout << x << "is not greater than " << y <<'\n';
// or immer true ausser false + false  and immer false ausser true + true
if(x>10 && x<20 && x!=15)
{
std::cout << " all three are true " <<'\n';
}
else
{
std::cout << " at least one is false " <<'\n';
}
// de Morgan Law !(x&&y) is equal to !x || !y   !(x||y) is equal to !x && !y

//scope a compount statement or block stement is a group of zero or more statements that is treated by the compiler
//as fi it were a single statement {begin }end




return 0;
}
