#include<iostream>
template<typename T>
class Pair
{
	private:
		T m_a;
		T m_b;
	public:
		Pair(T a,T b):m_a{a},m_b{b}{};
		T get_m_a()const{return m_a;}
		T get_m_b()const{return m_b;}
	    friend  std::ostream& operator<<(std::ostream& out,Pair p)
		{
			out<<"m_a: "<<p.m_a<<" m_b: "<<p.m_b;
			return out;
		}
};
int main()
{


Pair p{4,9};
auto counter{0};
auto add{[&counter](Pair<int> p){counter++;return p.get_m_a()+p.get_m_b();}};
std::cout<<"counter: "<< counter<<' '	<<' '<<p<<' '<<add(p)<<'\n';
//std::cout<<p;
Pair pd{4.1,9.7};
auto add_d {[&counter](Pair<double> p){counter++;return p.get_m_a()+p.get_m_b();}};
std::cout<<"counter: "<< counter<<' '<<pd<<' '<<add_d(pd)<<'\n';


	return 0;
}
