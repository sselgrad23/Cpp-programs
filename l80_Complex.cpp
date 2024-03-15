#include<iostream>
class ComplexNum
{
	private:double m_r{},m_i{};
	public:ComplexNum(double r,double i):m_r{r},m_i{i}{}
//	       ComplexNum operator-()const;
//	       bool       operator!()const;
	       friend ComplexNum    operator+ (const ComplexNum& c1, const ComplexNum& c2);
	       friend ComplexNum    operator* (const ComplexNum& c1, const ComplexNum& c2);
	       friend bool          operator==(const ComplexNum& c1, const ComplexNum& c2);
	       friend bool          operator!=(const ComplexNum& c1, const ComplexNum& c2);
	       friend std::ostream& operator<<(std::ostream& out,const ComplexNum& c);
	       friend std::istream &operator>>(std::istream& in , ComplexNum& c)
	       {
		       std::cout<<"Real? ";
		       in>>c.m_r;
		       std::cout<<"Imag? ";
		       in>>c.m_i;
		       return in;
	       }
};
//ComplexNum ComplexNum::operator-()const{return (m_r,m_i)};//, operator overload missing
ComplexNum operator+(const ComplexNum& c1, const ComplexNum& c2)
{
	ComplexNum c_return(c1.m_r+c2.m_r,c1.m_i+c2.m_i);
	//return (c1.m_r+c2.m_r,c1.m_i+c2.m_i);Later overload ,operator
	return c_return;
}
ComplexNum operator*(const ComplexNum& c1, const ComplexNum& c2)
{
	ComplexNum c_return(c1.m_r * c2.m_r - c1.m_i * c2.m_i, c1.m_r * c2.m_i + c1.m_i * c2.m_r);
	//return (c1.m_r+c2.m_r,c1.m_i+c2.m_i);Later overload ,operator
	return c_return;
}
bool operator==(const ComplexNum& c1, const ComplexNum& c2)
{
	return(c1.m_r == c2.m_r && c1.m_i == c2.m_i);
}
bool operator!=(const ComplexNum& c1, const ComplexNum& c2)
{
	return(c1.m_r != c2.m_r || c1.m_i != c2.m_i);
}
std::ostream& operator<<(std::ostream& out,const ComplexNum& c)
{
out<<c.m_r<<" + "<<c.m_i<<"i "; return out;
}
//std::istream& operator<<(std::istream& in, ComplexNum& c)
//{
//in>>c.m_r>>c.m_i; return in;
//}



int main(){
ComplexNum c_a(9.7,8.1),c_b(12.3,5.6),c_c(0.0,0.0);
std::cout<< c_a << " + " << c_b << " = " << (c_a+c_b) <<'\n';
std::cout<<"enter Complex number "<<'\n';

std::cin>>c_c;
std::cout<<c_c<<'\n';
return 0;
}
