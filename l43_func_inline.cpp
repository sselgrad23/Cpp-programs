#include<iostream>
//#include"l43_func_inline.h"
inline auto min(auto x, auto y){return x>y ? y:x;}

int main()
{

 std::cout << "call of a function is bad because of certain amount of performance overhead that is to do. cpu has to store address of current instruction it is executing, contens of register, copy all parameters if called by value and program has to branch to new location against this: inline function: good readable and just copied to monolitic program, code written in place is significantly quicker but longer \n";

 std::cout << min(3,9) <<'\n';

 return 0;
} 
