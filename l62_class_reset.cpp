#include<iostream>
class Foo{
	private:int m_a{9};
		int m_b{7};
	public:Foo(){}
	       Foo(int a,int b):m_a{a},m_b{b}{}
	       void print(){std::cout << m_a << ' ' << m_b << '\n';}
	       void reset(){*this = Foo();}/*create new Foo object and use assignment to override ouer implicit object*/
};
int main(){
Foo a{1,2};
a.print();
a.reset();
a.print();
	return 0;
}
