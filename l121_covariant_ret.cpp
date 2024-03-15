#include<iostream>
#include<string_view>
class Base
{
	public:
virtual Base* getThis(){std::cout<<"called Base::getThis()\n";return this;}
void printType(){std::cout<<"return a Base\n";}
};

class XY: public Base{public: void printType(){std::cout<<"XY\n";}};


class Derived:public Base
{
	public:
Derived* getThis()override{std::cout<<"called Derived::getThis()\n";return this;}/*return type NOT Base* */
void printType(){std::cout<<"return a Derived\n";}
};

class DerivedA:public Base
{
	public:
DerivedA* /*XY or Derived will not compile */ getThis()override{std::cout<<"called DerivedA::getThis()\n";return this;}
void printType(){std::cout<<"return a DerivedA\n";}
void print(){std::cout<<" hello\n";}
};


int main(){
	std::cout<< "usualy return type of Base and class must be the same if overridable, but\n";
	std::cout<< "if in the Base is a pointer to a class, the Derived must NOT have a pointer to the Base class but,\n";
	std::cout<< "to itselfe not an other class!!\n";
Derived d{};
Base* b{&d};
d.getThis()->printType();
b->getThis()->printType();
DerivedA d2{};
d2.print();
	return 0;
}
