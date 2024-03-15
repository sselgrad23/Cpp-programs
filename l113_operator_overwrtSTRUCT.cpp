#include<iostream>
class Base
{
	private: int m_i;
	public:Base(int i):m_i{i}{}
	 friend std::ostream& operator<<(std::ostream& out, const Base& b)
	       {out << "in Base\n";out << b.m_i+1 << '\n';return out;}
};
class Derived : public Base
{
	public:Derived(int i):Base{i}{}
	 friend std::ostream& operator<<(std::ostream& out, const Derived& d)
	       {out << "in Derived\n";out << static_cast<const Base&>(d) << '\n';return out;}/*overwrite << of Base*/

};
int main(){
Derived d{9};
std::cout << d <<'\n';
	return 0;
}
