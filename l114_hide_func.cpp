//g++-11 -Wall -o p l114_hide_func.cpp -std=c++2a
#include<iostream>
class Base
{
	private:int m_i;
	public:Base(int i):m_i{i}{}
	protected: void print()const{std::cout << m_i << '\n';} /*only member friend or derived with Base::print*/
	public: int getM_i(){return m_i;} 

};
class Derived :public Base
{
	public:Derived(int i):Base{i}{}
	       using Base::print;/*NO () if print isprotected write Base::print, public is always accessible les*/
		int getM_i()=delete;
};
int main(){
Derived d{9};
d.print();
std::cout <<  static_cast<Base&>(d).getM_i();/*!!!!!!although getM_i() is delete in derived*/
	return 0;
}
