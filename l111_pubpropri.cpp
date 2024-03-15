#include<iostream>
class Base
{
	public:int m_pub{1};
		void fktPlusOnePUB(){m_pri++;}/*for main*/
		int retM_priPUB(){return m_pri;}



	protected:int m_pro{1};

		void fktPlusOnePRO(){m_pri++;}/*for friend or public heritance*/
		int retM_priPRO(){return m_pri;}


	private:int m_pri{1};
		friend void ffkt(Base& base);
		friend void ffkt(Base& base,const int i);
};

void ffkt(Base& base){base.m_pub=2;base.m_pro=2;base.m_pri=2;}
void ffkt(Base& base,const int i){base.m_pub=i;base.m_pro=i;base.m_pri=i;std::cout<< "friend calls retM_priPRO: "<< base.retM_priPRO()<<'\n';}
class DerivedPub :public    Base{public:DerivedPub(){m_pub=1;m_pro=1;/*m_pri=1 not allowed*/}};
class DerivedPub2 :public    Base{public:DerivedPub2(Base& base){m_pub=1;m_pro=1;base.m_pub=100;/*base.m_pro=200;m_pri=1 not allowed*/}};
class DerivedPro :protected Base{public:DerivedPro(){m_pub=1;m_pro=1;/*m_pri=1 not allowed*/}};
class DerivedPri :private   Base{public:DerivedPri(){m_pub=1;m_pro=1;/*m_pri=1;*/}};
int main(){
Base b;
b.m_pub=1;
//b.pro=1; not allowed
//b.pri=1; not allowed
std::cout<<"Private inheritance means that all in Base Public declared objects gets private in Derived, so they ar not accessable\n";
	std::cout <<" from main any more.\n"; 
std::cout << b.m_pub <<'\n';
ffkt(b);
std::cout << b.m_pub <<'\n';
ffkt(b,10);
std::cout << b.m_pub <<'\n';
DerivedPub dPub;
std::cout << b.m_pub << ' ' << dPub.m_pub <<'\n';/*there are two!!!! (m_pub one in Main, one in Derived*/
DerivedPro dPro;
std::cout << b.m_pub /*<< ' ' << dPro.m_pub geht nicht mehr*/ <<'\n';
DerivedPri dPri;
std::cout << b.m_pub /*<< ' ' << dPro.m_pub geht nicht mehr*/ <<'\n';
DerivedPub2 dPub2(b);
std::cout << b.m_pub << ' ' << dPub2.m_pub <<'\n';/*there are two!!!! m_pub one in Main, one in Derived*/
std::cout<<b.retM_priPUB()<<'\n';
b.fktPlusOnePUB();
b.fktPlusOnePUB();
b.fktPlusOnePUB();
std::cout<<b.retM_priPUB()<<'\n';
return 0;
}
