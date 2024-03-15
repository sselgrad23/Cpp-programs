#include<iostream>
class Accumulator{
	private: int m_counter{0};/*to store Value if only a function m_counter has to be global,so possibility to avoid global variales*/
	public:int operator()(int i){return m_counter+=i;}
};
int main(){
	std::cout << "operator () is overloaded to implement a functor, which are classes that operates like functions" << '\n';
	std::cout << "a functoris a Class which act like a function, BUT can STORE MEMBER VARIABLES " << '\n';
Accumulator acc{};
std::cout << acc(10) <<'\n';/*acc(10) looks like a function, but Accumulator is a class acc is an instantiation*/
std::cout << acc(20) <<'\n';/*() is overloaded*/
std::cout << acc(1) <<'\n';/*() is overloaded*/



	return 0;
}
