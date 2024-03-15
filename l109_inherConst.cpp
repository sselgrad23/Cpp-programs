#include<iostream>
class Base
{
	public:int m_id{};
	       Base(int id=0):m_id{id}{};
	       int getId()const{return m_id;}
};
class Derived :public Base
{
	public:double m_cost{};
	       Derived(double cost=0.0):m_cost{cost}{}
	      // Derived(double cost=0.0,int id=0):m_cost{cost,}{m_id=id;}will work but this is better:

	       Derived(double cost=0.0,int id=0):/*new*/Base{id},m_cost{cost}{m_id=id;}
	       double getCost()const{return m_cost;}

};
//improved Base and Derived with private Member
class BaseP
{
	private:int m_id{};
	public: BaseP(int id=0):m_id{id}{};
	       int getId()const{return m_id;}
};
class DerivedP :public BaseP
{
	private:double m_cost{};
	public:DerivedP(double cost=0.0):m_cost{cost}{}


	       DerivedP(double cost=0.0,int id=0):BaseP{id},m_cost{cost}{/*m_id=id; will not compile now private*/}
	       double getCost()const{return m_cost;}

};




int main(){
Base base{5};
/*1memory for Base ist set aside 2Base constructor called.3member initializes Variables.4Body of Constr executed.5Conrol returned to caller*/
Derived derived{1.3,2};
/*Mem for Derived and base to aside 2Derived Const called3 Base object is constructe withBase constuctor 4member initialization */
/*5Body of Derived constructor executed 6 Control is returnt to caller*/
std::cout << derived.getId()<<'\n';


DerivedP derivedP{3.1,9};

std::cout << derivedP.getId()<<'\n';
return 0;
}
