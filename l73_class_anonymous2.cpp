#include<iostream>
class Cents
{
	private:int m_cents{};
	public:Cents(int cents){m_cents=cents;}
	       int getCents()const{return m_cents;}
};
Cents add(const Cents& c1, const Cents& c2)
{
//	Cents sum{c1.getCents() + c2.getCents()};
//	return sum;
//	replace with anonymous object
	return {c1.getCents() + c2.getCents()};
}
int main(){
	Cents cents1{5};
	Cents cents2{9};
//	Cents sum {add (cents1,cents2)};
//	std::cout << sum.getCents() << '\n';
//	replace with anonymous object
	std::cout << add (cents1,cents2).getCents() << '\n';
//	better:
	std::cout << add (Cents{9},Cents{3}).getCents() << '\n';
	int a{};
	int b{};
	std::cin>>a;
	std::cin>>b;
	std::cout << add (Cents{a},Cents{b}).getCents() << '\n';
	return 0;
}
