#include<iostream>
#include<string>
class Car
{
	private: std::string m_maker;
		 std::string m_model;
	public: Car(const std::string& maker,const std::string& model):m_maker{maker},m_model{model}{}
		friend bool operator==(const Car& c1,const Car& c2);
		friend bool operator!=(const Car& c1,const Car& c2);
};
bool operator==(const Car& c1,const Car& c2){return( c1.m_maker==c2.m_maker && c1.m_model==c2.m_model);}
bool operator!=(const Car& c1,const Car& c2){return( c1.m_maker!=c2.m_maker || c1.m_model!=c2.m_model);}
int main(){
Car cA{"Toyota","Corolla"};
Car cB{"Toyota","Camry"};
if(cA==cB)std::cout << "same car" << '\n';
if(cA!=cB)std::cout << "different car" << '\n';
	return 0;
}
