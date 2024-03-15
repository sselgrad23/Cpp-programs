//#include<iostream>
#include<string_view>
class A{public:virtual std::string_view getName(){return "a";}};
class B             final                 : public A{public:virtual std::string_view getName(){return "b";}};
//class C : public B{public:virtual std::string_view getName(){return "a";}} will not compile class B final
int main(){

	return 0;
}
