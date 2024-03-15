//g++-11 -Wall -o p l50_std_func_obj05.cpp -std=c++2a
#include<algorithm>
#include<iostream>
#include<array>
 bool greater(/*auto not possible*/int  a,int b){return (a>b);}
 bool greater_d(/*auto not possible*/double  a,double b){return (a>b);}
template<typename T>bool smaller(T a,T b){return(a<b);}
int main(){
std::cout<<"\n";
std::array arr{22,43,55,65,78,7,9,10};
std::sort(arr.begin(),arr.end(),greater);
//disadvantage function greater is fare away an defined by you
for(auto i:arr)std::cout<< i <<"\n";
std::array arr_d{22.3,43.8,55.9,65.8,78.7,7.1,9.4,10.5};
std::sort(arr_d.begin(),arr_d.end(),greater_d);
for(auto i:arr_d)std::cout<< i <<"\n";
//better use std::greater{} object from standart library
std::sort(arr.begin(),arr.end(),std::greater{});
std::sort(arr_d.begin(),arr_d.end(),std::greater{});
for(auto i:arr)std::cout<< i <<"\n";
for(auto i:arr_d)std::cout<< i <<"\n";
std::sort(arr.begin(),arr.end(),smaller<int>);/*<i> is needed*/
std::sort(arr_d.begin(),arr_d.end(),smaller<double>);
for(auto i:arr)std::cout<< i <<"\n";
for(auto i:arr_d)std::cout<< i <<"\n";
return 0;
}
