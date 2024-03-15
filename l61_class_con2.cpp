#include<iostream>
#include<string>

class Complex
{
	private:double m_re{};
		double m_cp{};
	public:Complex(double re=0.0,const double cp=0.0):m_re{re},m_cp{cp}
	       {std::cout << m_re << " + " << m_cp << "i"<<'\n';}
	       Complex(const double cp): Complex{0,cp}{}
};


class Employee
{
	private:int m_id{};
		std::string m_name{};
	public:Employee(int id=0,const std::string & name=""):m_id{id},m_name{name}
	       {std::cout << " emp " << m_name << '\n';}
	       Employee(const std::string &name): Employee{0,name}{}
};
int main(){
Employee n{"ben"};
Complex a{1.1,4.4};
Complex b{};
//Complex c{9.9};NOT WorKING
	return 0;
}
