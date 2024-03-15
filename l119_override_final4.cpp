//l119_override_final5.cpp -std=c++2a
#include<iostream>
#include<string_view>
class A
{
	public:virtual std::string_view getName1(int x){return "a";}
	       virtual std::string_view getName2(int x){return "a";}
	       virtual std::string_view getName3(char x)final{return "x";}
};
class B  final   : public A
{
	public:virtual std::string_view getName1(short int x){return "sb";}/*is not considered as an override of A::getName*/
	       virtual std::string_view getName2(int x)const{return "cb";}/*is not considered as an override of A::getName*/
	       /*virtual std::string_view getName3(char x){return "bx";}compiler error fnal in Base*/
};

/*class C : public B{};compiler error class B final*/


int main(){
std::cout << "This part shows your intention, to override the virt fct in A with B::getName.This intention will not work, because of\n";
std::cout << "diffrent parameter and const and can cause problems. code will compile but not work the way you intended.\n"; 
B b{};
std::cout << b.getName1(1)<<'\n';
std::cout << b.getName3('u')<<'\n';
A& rBase{b};
std::cout << rBase.getName1(1)<<'\n';
std::cout << rBase.getName2(2)<<'\n';
std::cout << "To avoid his use specifier override to make the compiler send a error message.\n";

	return 0;
}
