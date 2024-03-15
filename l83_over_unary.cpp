#include<iostream>
class Cents
{
	private:int m_cents;
	public: Cents (int cents):m_cents{cents}{}
		Cents operator-()const;/*member function: Cent is our own class and we are able to add a member function and should do so*/
		//operator-() takes no parameter because it has access to m_cent. it operate on *this object
		bool operator!()const;
		int getCents()const{return m_cents;}
};

Cents Cents::operator-()const{return(-m_cents);}/*-m_cent is of type INT BUT RETURN TYPE is of type Cents,*/
//so there is an implicite conversion from int to Cent using the Constructor Cents (int cents):m_cents{cents}{} .
bool Cents::operator!()const{return (m_cents==0);}/*if m_cent is 0 return is true*/
int main(){
	std::cout << "unary operator logic not! positiv+ negativ- operate only on one operand typicaly as member function" << '\n';
	std::cout << "negativ operator(-)ONE PARAMETER not to confuse with minus(-)operator TWO PARAMETER" << '\n';  
	const Cents nickel{5};
	std::cout << "const Cents nickel{5}; const means the object nickel does NOT change value, nickel is always 5" << '\n';
	std::cout << "but the return value of '-operator(nickel)' is -(5)" << '\n';
	std::cout << "A nickel of debt is worth " << -nickel.getCents() << " Cents."<< '\n';
	std::cout << "A nickel of debt is worth " << (-nickel)/*easer to read().*/.getCents() << " Cents."<< '\n';
	Cents nickel2{2};
	if(!nickel2)std::cout << "is 0 " << '\n';else std::cout << "is not 0 " << '\n';
	Cents nickel3{0};
	if(!nickel3)std::cout << "is 0 " << '\n';else std::cout << "is not 0 " << '\n';
	return 0;
}
