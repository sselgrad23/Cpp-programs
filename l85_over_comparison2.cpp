#include<iostream>
class Cents
{
	private:int m_cents;
	public: Cents(int cents):m_cents{cents}{}

	friend bool operator==(const Cents& c1,const Cents& c2);
	friend bool operator!=(const Cents& c1,const Cents& c2);
	friend bool operator< (const Cents& c1,const Cents& c2);
	friend bool operator> (const Cents& c1,const Cents& c2);
	friend bool operator<=(const Cents& c1,const Cents& c2);
	friend bool operator>=(const Cents& c1,const Cents& c2);

};
bool operator==(const Cents& c1,const Cents& c2){return c1.m_cents==c2.m_cents;}
bool operator!=(const Cents& c1,const Cents& c2){return/* c1.m_cents!=c2.m_cents;*/ !(operator==(c1,c2));}
bool operator< (const Cents& c1,const Cents& c2){return  c1.m_cents< c2.m_cents;}
bool operator> (const Cents& c1,const Cents& c2){return/*  c1.m_cents> c2.m_cents;*/!(operator< (c1,c2));}
bool operator<=(const Cents& c1,const Cents& c2){return/*  c1.m_cents<=c2.m_cents;*/!(operator> (c1,c2));}
bool operator>=(const Cents& c1,const Cents& c2){return/*  c1.m_cents>=c2.m_cents;*/!(operator< (c1,c2));}
int main(){
	Cents nickel{5};
	Cents dime{10};
	if(nickel<dime)std::cout << "nickel is less than dime" << '\n';
	return 0;
}
