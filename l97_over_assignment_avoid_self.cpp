//g++-11 -Wall -o p l97_over_assignment_avoid_self.cpp -std=c++2a
#include<iostream>
#include<cassert>
class Fraction
{
	private:int m_numerator{0};
		int m_denominator{1};
	public:	Fraction(int numerator=0,int denominator=1):m_numerator{numerator},m_denominator{denominator}{assert(denominator!=0);}
		Fraction(const Fraction& copy)=delete;/*delete the default copy constructot*/
		Fraction& operator=(const Fraction& fraction)=delete;/*delete the default assignment operator*/
		friend std::ostream& operator<<(std::ostream& out,const Fraction& f1);
};
std::ostream& operator<<(std::ostream& out,const Fraction& f1){out << f1.m_numerator<<"/"<<f1.m_denominator;return out;}
//Fraction& Fraction::operator=(const Fraction& fraction)
//{
//	if(this==&fraction)return* this;
//	m_numerator=fraction.m_numerator;m_denominator=fraction.m_denominator;
//	return*  this;
//}

int main(){
	std::cout <<"if you don't write your own COPY CONSTRUCTOR or your own assignment operator compile provides the TWO for you\n";
	std::cout <<"to avoid this delete them with =delete.\n";
	std::cout <<"the default assignment operator also kown as memberwise copy also known as SHALLOW COPY.\n";

	Fraction fiveThird{5,3};
	Fraction f;
//	will not compile anymore
//	f=fiveThird;
	return 0;
}
