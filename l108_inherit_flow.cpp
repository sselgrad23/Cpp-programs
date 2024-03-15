//g++-11 -Wall -o p l108_inherit_flow.cpp -std=c++2a
#include<iostream>
class A{public:A(){std::cout<<" A::A ";} ~A(){std::cout<<" A::~A ";}};
class B:public A{public:B(){std::cout<<" B::B ";} ~B(){std::cout<<" B::~B ";}};
class C:public B{public:C(){std::cout<<" C::C ";} ~C(){std::cout<<" C::~C ";}};
class D:public C{public:D(){std::cout<<" D::D ";} ~D(){std::cout<<" D::~D ";}};
int main(){
	std::cout<< "Constructing A\n";
	A a;
	std::cout<< "Constructing B\n";
	B b;
        std::cout<< "Constructing C\n";
	C c;
	std::cout<< "Constructing D\n";
	D d;




	return 0;
}
