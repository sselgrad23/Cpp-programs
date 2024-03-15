#include<iostream>
class Cents
{
	private:int m_cents;
	public:Cents(int cents=0):m_cents{cents}{}/*int( cents ) is converted into object Cents, stored in Cents::m_cents*/
	       int getCents()const{return m_cents;}/*opostie now object Cents converted to int*/
	       void setCents(int cents){m_cents=cents;}
	       operator int() const{return m_cents;}/*operator int() overload NOT to confuse with operator() (parenthesis)*/
	       /*function is called int(), takes NO PARAMETER(you are not able to path arguments), NO RETURN TYPE*/
};

class Dollars
{
	private: int m_dollars;
	public:Dollars(int Dollars=0):m_dollars{Dollars}{}
          //as operator int() operator Cents() is function to overload typecast
	        operator Cents() const {return Cents{m_dollars *100};}

}
;


void printInt(int v)
{
	std::cout << v <<'\n';
}
int main(){
Cents cents{9};
printInt(cents.getCents());/*OLD:printInt takes an INT getCents convert Cents into int*/
//NOW:
printInt(cents);/*prints now objet cents. printInt take an int, compiler looks for a conversion from cent to int-> operator int()*/
Dollars dollars{9};
printInt(Cents(dollars));/*there is no object of typ Cents declared!!!!*/


return 0;
}
