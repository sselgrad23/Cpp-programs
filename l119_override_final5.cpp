//l119_override_final5.cpp -std=c++2a
#include<iostream>
#include<string_view>
class A
{
	public:virtual std::string_view getName1(int x){return "a";}
	       virtual std::string_view getName2(int x){return "a";}
};
class B: public A
{
	public:virtual std::string_view getName1(short int x){return "b";}/*is not considered as an override of A::getName*/
	       virtual std::string_view getName2(int x)const{return "b";}/*is not considered as an override of A::getName*/
};

class A1
{
	public:virtual std::string_view getName1(int x){return "a1";}
	       virtual std::string_view getName2(int x){return "a1";}
	       virtual std::string_view getName3(int x){return "a1";}
};
class B1: public A1
{
	public:
	//	virtual std::string_view getName1(short int x)override{return "b1";} will not compile
	//      virtual std::string_view getName2(int x)const override{return "b1";} will not compile

		virtual std::string_view getName1(/*short*/ int x)override{return "b1";}
	        virtual std::string_view getName2(int x)/*const*/ override{return "b2";}
	        virtual std::string_view getName3(int x)/*const*/ override final{return "b3";}

	                std::string_view getName4(int x){return "b4";}/*will compile but can NOT be called*/

};
class C1: public B1
{
	public:
	//	virtual std::string_view getName1(short int x)override{return "b1";} will not compile
	//      virtual std::string_view getName2(int x)const override{return "b1";} will not compile

		virtual std::string_view getName1(/*short*/ int x)override{return "c1";}
	        virtual std::string_view getName2(int x)/*const*/ override{return "c2";}

	//	virtual std::string_view getName3(int x)/*const*/ override{return "c1";} you can not override final
	//
	                std::string_view getName3(int x)const{return "c3";}/*Will compile but NOT work*/

};



int main(){
std::cout << "This part shows your intention, to override the virt fct in A with B::getName.This intention will not work, because of\n";
std::cout << "diffrent parameter and const and can cause problems. code will compile but not work the way you intended.\n"; 
B b{};
A& rBase{b};
std::cout << rBase.getName1(1)<<'\n';
std::cout << rBase.getName2(2)<<'\n';
std::cout << "To avoid his use specifier override to make the compiler send a error message.\n";
B1 b1{};
A1& rBase1{b1};
std::cout << rBase1.getName1(1)<<'\n';
std::cout << rBase1.getName2(2)<<'\n';

//std::cout << rBase1.getName4(2)<<'\n'; will not compile
std::cout << "To avoid his use specifier final to make the compiler send a error message.\n";
C1 c1{};
A1& rBase2{c1};
const int co{7};
std::cout << rBase2.getName1(1)<<'\n';
std::cout << rBase2.getName2(2)<<'\n';
std::cout << rBase2.getName3(2)<<'\n';

std::cout << rBase2.getName3(co)<<'\n';/*will call B::getName3*/

	return 0;
}
