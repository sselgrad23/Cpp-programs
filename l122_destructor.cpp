//g++-11 -Wall -o p l122_destructor.cpp -std=c++2a
#include<iostream>

class Base
{
	public:virtual ~Base(){std::cout<<"~Base()\n";}
	     //  virtual ~Base()=default;
	     //

};
class DerivedA: public Base
{
	private:int* m_array;
	public:DerivedA(int length):m_array{new int[length]}{std::cout<<"array in A done\n";}
	       virtual~DerivedA(){std::cout<<"~DerivedA()\n";delete[] m_array;}
};

class DerivedB: public Base
{
	private:int* m_array;
	public:DerivedB(int length):m_array{new int[length]}{std::cout<<"array in B done\n";}
	       virtual~DerivedB(){std::cout<<"~DerivedB()\n";delete[] m_array;}



};


int main(){
	std::cout<<"Always make explicit destructor virtual, when inheritance\n";
int i{1};
if(i==0){DerivedA* dA{new DerivedA(5)};Base *baseA{dA};delete baseA;}
if(i==1){DerivedB* dB{new DerivedB(5)};Base *baseB{dB};delete baseB;}


	return 0;
}
