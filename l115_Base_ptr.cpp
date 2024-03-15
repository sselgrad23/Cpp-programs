#include<iostream>
class Base
{
	protected:int m_v{};
	public:Base(int v):m_v{v}{}
	       std::string_view getName()const{return "Base ";}
	       int getV()const{return m_v;}
};
class Derived:public Base
{
	public:Derived(int v):Base{v}{}
	       std::string_view getName()const{return "Derived ";}
	       int getVdoubled()const{return m_v*2;}
};
int main(){
Derived d{5};
std::cout<<" d is a "<<d.getName() << " and has v " << d.getV() << '\n';
Derived& rd{d};
std::cout<<"rd is a "<<rd.getName() << " and has v " << rd.getV() << '\n';/*Derived::getName is called*/
Derived* pd{&d};
std::cout<<"pd is a "<<pd->getName() << " and has v " << pd->getV() << '\n';

Base& rb{d};
std::cout<<"rb is a "<<rb.getName() << " and has v " << rb.getV() << '\n';/*Base::getName is called*/
Base* pb{&d};
std::cout<<"pb is a "<<pb->getName() << " and has v " << pb->getV() << '\n';
//rb.getVdoubled();Not Possible




return 0;
}
