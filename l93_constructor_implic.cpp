#include<iostream>
#include<cassert>
class Fraction
{
	private:int m_numerator{};int m_denominator{};
	public: Fraction(int numerator, int denominator=1):m_numerator{numerator},m_denominator{denominator}
	       {assert(denominator!=0);/*das gegeteil von dem was schlecht ist*/}
	       //OWN Copy consrtuctor
	       Fraction(const Fraction& fraction):m_numerator{fraction.m_numerator},m_denominator{fraction.m_denominator}
	       {/*assert not neede tested before*/std::cout << "copy constructor called " << '\n';}

	       friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	       int getNumerator(){return m_numerator;}
	       void setNumerator(int numerator){m_numerator=numerator;}
};
std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
out << f1.m_numerator << '/' << f1.m_denominator; return out;
}
Fraction makeNegative(Fraction f){f.setNumerator(-f.getNumerator());return f;}

void printFraction(const Fraction& f){std::cout << f;}




int main(){
	std::cout<< "" << '\n';
	printFraction(6);/*compiler first sees a literal 6,then takes constructor Fraction (int int), this is a IMPLICIT Conversion t make*/
	/*a object Fraction*/
return 0;
}
