#include<iostream>
class KlasseB;/*foreward declaration*/
class Freund_of_KlasseBbesch
{

	public:void printF(){std::cout<<"class Freund_of_KlasseBbesch"<<'\n';}
};

class KlasseA
{
	private: int m_i;

	public: KlasseA(const int i):m_i{i}{}
		void print(){std::cout<< "m_i: " << m_i <<'\n';}
		friend void reset(KlasseA &klasseA);/*this gives access to private member m_i*/
		friend bool isEqual(const KlasseA& obj1, const KlasseA& obj2);

		friend void reset_A_and_B(KlasseA &klasseA, KlasseB &klasseB );/*this gives access to private member m_i of both Klasse*/
};
class KlasseB
{
	private: int m_i;

	public: KlasseB(const int i):m_i{i}{}
		void print(){std::cout<< "m_i: " << m_i <<'\n';}

		void print_plus_one(){std::cout<< "m_i+1: " << m_i+1 <<'\n';}
	friend void reset_A_and_B(KlasseA &klasseA, KlasseB &klasseB );/*this gives access to private member m_i of both Klasse*/
        friend class Freund_of_KlasseB;


};


void reset(KlasseA &klasseA){klasseA.m_i=0;}
void reset_A_and_B(KlasseA &klasseA, KlasseB &klasseB ){klasseA.m_i=0;klasseB.m_i=0;}
bool isEqual(const KlasseA& obj1, const KlasseA& obj2){return (obj1.m_i==obj2.m_i);} 

class Freund_of_KlasseB
{
	public:void resetB999(KlasseB &klasseB) {	klasseB.m_i=999;}
	

        friend void Freund_of_KlasseBbesch::printF();/*Remove CLASS and DON'T forget RETURN TYPE*/
};







int main()
{
KlasseA oA(9);
oA.print();
reset(oA);/*reset is NOT a member function has no THIS pointer, so it needs an object to work on*/
oA.print();


KlasseA oB(9);
KlasseA oC(9);
std::cout << isEqual(oB,oC) <<'\n';
KlasseB oX(77);
oX.print();
reset_A_and_B(oA,oX);
oA.print();
oX.print();
Freund_of_KlasseB fkb;/*Freund hat NOT access to oX's this pointer, and also KlasseB is NOT a FRIEND of Freund_of_KlasseB*/
fkb.resetB999(oX);
oX.print();


return 0;
}
