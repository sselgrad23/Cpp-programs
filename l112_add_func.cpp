//g++-11 -Wall -o p l112_add_func.cpp -std=c++2a
#include<iostream>
class Base
{
	protected: int m_v{};
	public:Base(int v):m_v{v}{}
	       void identify()const{std::cout<<"Base::identify\n";print();}
	private:void print()const{std::cout<<"Base::print\n";}

};
class Derived:public Base{public:Derived(int v):Base{v}{}};
class DerivedADD:public Base{public:DerivedADD(int v):Base{v}{}
		         void identify()const{std::cout<<"DerivedAAD::identify \n";/*how to call Base's void identify()*/Base::identify();}
			 void print()const{std::cout<<"DerivedAAD::print NOT taking access specifier of overwriten Base fkt(privat)\n";}
};
int main(){
Base base{5};
base.identify();
//base.print();
Derived deri{5};
deri.identify();
DerivedADD deriADD{5};
deriADD.identify();
	return 0;
}
