//g++-11 -Wall -o p l65_class_this_chaining.cpp -std=c++2a
#include<iostream>
class Cal
{
	private: int m_value{0};
	public: Cal& add(int value){ m_value+=value;return *this;}/*Cal ha the same address as on what this is pointing to*/
		Cal& sub(int value){ m_value-=value;return *this;}
		Cal& mul(int value){ m_value*=value;return *this;}
		int showValue(){return m_value;}
		void showValue2(){std::cout << m_value << " this is pointing at" << this << '\n';}
};
int main(){
	std::cout << " one use of this pointer is chaining of functions" << '\n'; 
Cal c{};
c.add(5).sub(8).mul(3).showValue2();
//std::cout << c.showValue() <<'\n';
std::cout <<" object c starts at " <<& c <<'\n';
	return 0;
}
