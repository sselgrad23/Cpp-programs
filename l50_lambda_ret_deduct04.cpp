//g++-11 -Wall -o p l50_lambda_ret_deduct04.cpp -std=c++2a
#include<algorithm>
#include<iostream>
int main(){
std::cout<<"\n";
std::cout<<"\n";
//divide Lambda variable initialised with lambda definition
auto divide{[](int x, int y, bool bInteger)->double/*trailing return type otherwise will not compile*/
{if(bInteger)return x/y;else return static_cast<double>(x)/y;}};
std::cout<<divide(3,2,true)<<'\n';
std::cout<<divide(3,2,false)<<'\n';

return 0;
}
