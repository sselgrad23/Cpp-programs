//g++-11 -Wall -o p l44_func_fctpointer.cpp -std=c++2a
#include<iostream>
#include<algorithm>
#include<array>
int fkt1(){return 10;}
int fkt2(){return 20;}
int fkt3(int i){return i;}
auto fkt4(auto i){return i;}
void f0(int i){std::cout<<"i: "<<i<<" in fkt0\n";}
void f1(int i){std::cout<<"i: "<<i<<" in fkt1\n";}
void f2(int i){std::cout<<"i: "<<i<<" in fkt2\n";}
void f3(int i){std::cout<<"i: "<<i<<" in fkt3\n";}
int main()
{

 std::cout << "the address of fkt1 is: " << fkt1  << '\n'; /*prints 1*/
 std::cout << "the address of fkt1 is: " << reinterpret_cast<void*>(fkt1)  << '\n'; /*prints address*/

//that is not working because const
//  int (*const fctptr1)()=nullptr;/*better if fkt return is a const*/
// fctptr1=&fkt1;/*fkt1 is pointer to fkt1()*/

int (*const fctptr1)(){&fkt1};/*better if fkt return is a const*/


int (* fctptr2)(){nullptr};/*this will work*/
fctptr2=&fkt2;
fctptr2=&fkt1;
if(fctptr1==fctptr2)std::cout<< "pointing at the same function \n";

int (* fctptr3)(int){nullptr};/*this will work*/
fctptr3=&fkt3;
fctptr3=&fkt4;/*this will compile*/
if(fctptr3){
 std::cout << (*fctptr3)(5) << ' ' << fctptr3(5) << '\n';
 std::cout << fctptr3('a')/*returns 89 type deduction*/ << ' ' << fctptr3(9) << ' ' << fctptr3(8.998)/*returns 8 because type decuction*/ <<'\n';
} 
else std::cout << "NULL \n";
//auto (* fctptr4)(auto NOT ALLOWED){nullptr};/*this will NOT WORK use Template OR:*/

auto fctptr5{&fkt3};
std::cout << fctptr5(99);
// auto       (*fctptr3)(auto)=nullptr;
std::cout<<"array of fktpointer\n";


void (* fktpointer)(int){nullptr};
typedef void (*fn)(int);
static fn funcs[]={f0,f1,f2,f3};
funcs[0](17);
//void(*arr [4])(int)={f0(1),f1(1),f2(2),f3(3)};
 return 0;
} 
