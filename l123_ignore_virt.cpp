#include<iostream>
class A{public:void printA(){std::cout<<"in A\n";}};

class B:public A{
	public:void printB(){std::cout<<"in B\n";}

};


int main(){
A a{};
B b{};
a.printA();
b.printB();
b.printA();
	return 0;
}
