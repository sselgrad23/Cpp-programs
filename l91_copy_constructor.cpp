#include<iostream>
#include<cassert>
class Fraction
{
	private:int m_numerator{};int m_denominator{};
	public:Fraction(int numerator, int denominator=1):m_numerator{numerator},m_denominator{denominator}
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






int main(){
	std::cout<< "" << '\n';
Fraction fiveThird{5,3};/*direct initializatio{} calls constructor Fraction(int,int)*/
Fraction fcopy{ fiveThird};/*direct initialisation calls default COPY CONSTRUCTOR(like default constructor, if not given by programmer */
std::cout << fcopy << '\n';
Fraction efcopy{Fraction{6,7}};/*nitialization with anonymous object NO copy constructor call, done by compiler:  */
//compiler opt out and replace against Fraction efcopy{6,7} for better performance
//elision is the Process of omitting certain copy steps for performance purpose
std::cout << efcopy << '\n';
//DON'T DO THIS:
Fraction six = Fraction(6);/*like int x=15 this is a copy initialization*/
std::cout << six << '\n';
//OR:
Fraction seven(Fraction(7));/*Dont do this. This can make calls to both Fraction(int,int) and Fraction( copy constructor whitch may be*/
/*elided*/

//two times Copy constructor called
std::cout << makeNegative(fiveThird) <<'\n';
// first call happens when fiveThird is passed as an argument to makeNegative 
// second call when returned to main from makeNegativ
// this is a wast!! tho compiler cannot opt to elide the copy constructor
return 0;
}
