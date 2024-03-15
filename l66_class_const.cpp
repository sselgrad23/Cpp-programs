#include<iostream>
class Klasse
{
	public:int m_value{};

	       Klasse();/*bottom :: m_value{0};*/
	       void setValue(int v);
	       int getValue();
	       int getValue2()const;/*const behind ()*/


};

Klasse::Klasse(): m_value{0}{}
void Klasse::setValue(int v){m_value=v;}
int  Klasse::getValue(){return m_value;}
int  Klasse::getValue2()const{return m_value;}


int main(){
	std::cout << "const before Klasse " <<'\n';
	const Klasse c{};
//NOT ALLOWED	c.setValue(9);
//also NOT ALLowed c.getValue(); const is missing
	std::cout << c.getValue2() << '\n';
	return 0;
}
