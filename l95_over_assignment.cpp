//g++-11 -Wall -o p l95_over_assignment.cpp -std=c++2a
#include<iostream>
#include<cassert>
class Fraction
{
	private:int m_numerator{0};
		int m_denominator{1};
	public:	Fraction(int numerator=0,int denominator=1):m_numerator{numerator},m_denominator{denominator}{assert(denominator!=0);}
		Fraction(const Fraction& copy):m_numerator{copy.m_numerator},m_denominator{copy.m_denominator}{std::cout<<"copy called\n";}
		Fraction& operator=(const Fraction& fraction);
		friend std::ostream& operator<<(std::ostream& out,const Fraction& f1);
};
std::ostream& operator<<(std::ostream& out,const Fraction& f1){out << f1.m_numerator<<"/"<<f1.m_denominator;return out;}
Fraction& Fraction::operator=(const Fraction& fraction)
{
	if(this==&fraction)return* this;
	m_numerator=fraction.m_numerator;m_denominator=fraction.m_denominator;
	return*  this;
}

int main(){
	std::cout <<"assignment operator to copy values from one object to anothe allredy existing object.\n";
	std::cout <<"diffrent copy constructor and assignment operator is copy constructor initialize new object, whereas assignment\n";
	std::cout <<"replace contens of existing object.\n";
	std::cout <<"if a new object has to be created before copying can occur, copyconstructor is needed including passing or returnig\n";
	std::cout <<" by value.\n";
	std::cout <<"if a new object does not have to be created before copying can occure, assignment is needed.\n";
	Fraction fiveThird{5,3};
	Fraction f;
	f=fiveThird;
	std::cout << f << '\n';
	Fraction threefifth{2,5};
	Fraction oneHalve{1,2};
	fiveThird=threefifth=oneHalve;/*possible becaus return * this*/
	std::cout << fiveThird <<'\n';
	Fraction oneThird{1,3};
	oneThird=oneThird;/*self assignwent*/
	return 0;
}
