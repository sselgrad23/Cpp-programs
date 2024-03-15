#include<iostream>
class pair {
	int m_a;
	int m_b;
	public: pair (int a, int b):m_a{a},m_b{b}{}
         int get_m_a(){return m_a;}
         int get_m_b(){return m_b;}
friend std::ostream& operator<<(std::ostream& out, pair& p);
};
std::ostream& operator<<(std::ostream& out, pair& p){
out<<"a: "<<p.m_a<<" b: "<<p.m_b;return out;}
int main(){
auto add{[](auto a,auto b){return a+b;}};
std::cout<<add(4,5)<<'\n';
auto counter{0};
auto sub{[&counter](auto a,auto b){counter++;return a-b;}};
std::cout<<"counter: "<<counter<<' '<<sub(9,5)<<'\n';
std::cout<<"counter: "<<counter<<' '<<sub(9,7)<<'\n';
std::cout<<"counter: "<<counter<<' '<<sub(9,1)<<'\n';
counter=0;
auto mul{[&counter](pair& p){counter++;return p.get_m_a()*p.get_m_b();}};
pair p{2,8};
std::cout<<"counter: "<<counter<<' '<<p<<' ' <<mul(p)<<'\n';

	return 0;
}
