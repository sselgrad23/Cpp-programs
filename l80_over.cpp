#include<iostream>
class Cents
{
	private:int m_cents{};
	public:Cents(int cents){m_cents=cents;}
	       int getCents()const{return m_cents;}
	       Cents operator+(int v);/*member function NOT friend*/
//you can not overload << operator with a member function, because the overload opperator must be added as a member
//of the left operand std::ostream and std::ostream is a fixed part of of the stansart library
//we can't modify the class declaration to add the overload as a member function of std::ostream







	       friend Cents operator+(const Cents& c1, const Cents& c2);
	       friend Cents operator-(const Cents& c1, const Cents& c2);
	       friend Cents operator+(int i, const Cents& c){return (i+ c.m_cents);}/*friend in class, but is not a member function*/
//must be friend or normal funktion but can NOT be a member funktion,because the left int i is NOT a class,
//std::ostream is a class but can NOT modified therefore << can NOT be overloade with a member function





};

Cents Cents::operator+(int v){return Cents{m_cents+v};}


Cents operator+(const Cents& c1, const Cents& c2){return (c1.m_cents+c2.m_cents);}/*adding two objects of type Cents*/
Cents operator-(const Cents& c1, const Cents& c2){return (c1.m_cents-c2.m_cents);}/*subtracing two objects of type Cents*/
//This is the best solution normal function to overload *
Cents operator*(const Cents& c1, const Cents& c2){return (c1.getCents()*c2.getCents());}/*NO friend nor member function is multiplying ints*/
int main(){
std::cout << "overload assignment (=),subscipt([]),function call(()), or memberselection(->) as member function\n";
std::cout << "overload unitary operator as member function\n";
std::cout << "overload binary operator as opereator+,whitch does not modify left operand, as a normal function(prefered) or friend\n";
std::cout << "overload binary operator as << and you can NOT add members to the class definition of the left operand normal func or friend\n";
std::cout << "overload binary operator as += that modifies left operand and you can modify the definition of the left op do as member fct\n"; 
	Cents cents1{5};
	Cents cents2{9};
	Cents cents3{3};
//	Cents centsSum{cents1 +  cents2 - cents3+33};
	Cents centsSum{33+cents1 +  cents2 - cents3+10};
	std::cout << centsSum.getCents() << '\n';
	Cents centsMul{cents1 * cents2};
	std::cout << centsMul.getCents() << '\n';
	Cents centsMember{cents1+3000};
	std::cout << centsMember.getCents() << '\n';
	return 0;
}
