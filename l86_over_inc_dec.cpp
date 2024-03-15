#include<iostream>
class Digit
{
	private:int g{0};
	       	int m_digit;
	public: Digit(int digit=0):m_digit{digit}{}
		Digit& operator++();/*++d prefix unary operatot changing operand -> member function always prefered than friend than normal*/
		Digit& operator--();
		//Digit& fkt(int,double);/*dummy parameter*/
		Digit operator++(int);/*e++ postfix has an dummy int as parameter, given no name because will not be used and if there*/
		Digit operator--(int);/*is no name there is no warning,compiler treats it as a placeholder*/
		friend std::ostream& operator<<(std::ostream& out,const Digit& d);
};
//Prefix operator incremet member and return *this 
Digit& Digit::operator++(){if(m_digit==9)m_digit=0;else++m_digit;return *this;}
Digit& Digit::operator--(){if(m_digit==0)m_digit=9;else--m_digit;return *this;}
//Postfix operator return is before increment the object
Digit Digit::operator++(int)/*Dummy parameter never used*/
{
	Digit temp{*this};/*create temp var mit contense of non changed m_digit*/
	++(*this);/*use prefix  ++()non int to increase m_digit by 1 THIS makes code easier to maintain*/
	return temp;/*return saved state for output with non changed m_digit*/
}
Digit Digit::operator--(int)
{
	Digit temp{*this};/*create temp var mit contense of non changed m_digit*/
	--(*this);/*use prefix  --()non int to decrease m_digit by 1 */
	return temp;/*return saved state for output with non changed m_digit*/
}





std::ostream& operator<<(std::ostream& out,const Digit& d){ out << d.m_digit << ' '; return out;}
int main(){
Digit digit{8};
//<< overload left side not accessible -> friend function or normal function (prefered but not possible because of d.m_digit
// and m_digit is PRIVAT otherwise write a function with a return of typ int to get m_digit)
std::cout << digit;
std::cout << --digit;
std::cout << --digit;
std::cout << --digit;
std::cout << ++digit;
std::cout << ++digit;
std::cout << ++digit;
std::cout << '\n';
std::cout << digit;
std::cout << digit++;
std::cout << digit++;
std::cout << digit;
	return 0;
}
