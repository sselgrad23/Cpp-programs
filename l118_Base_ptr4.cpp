//g++-11 -Wall -o p l118_Base_ptr4.cpp -std=c++2a
#include<iostream>
#include<string_view>
class A{public:virtual std::string_view getName()const{return " a ";}};
class B:public A{public:virtual std::string_view getName()const{return " b ";}};
class C:public B{public:virtual std::string_view getName()const{return " c ";}};
class D:public C{public:virtual std::string_view getName()const{return " d ";}};

class A1{public:/*virtual*/ std::string_view getName()const{return " a1 ";}};
class B1:public A1{public:virtual std::string_view getName()const{return " b1 ";}};
class C1:public B1{public:virtual std::string_view getName()const{return " c1 ";}};
class D1:public C1{public:virtual std::string_view getName()const{return " d1 ";}};

class A2{public:virtual std::string_view getName()const{return " a2 ";}};
class B2:public A2{public:virtual std::string_view getName()const{return " b2 ";}};
class C2:public B2{/*public:virtual std::string_view getName()const{return " c2 ";}*/};
class D2:public C2{public:virtual std::string_view getName()const{return " d2 ";}};

class A3{public:virtual std::string_view getName()const{return " a3 ";}};
class B3:public A3{public:/*virtual*/ std::string_view getName()const{return " b3 ";}};
class C3:public B3{public:/*virtual*/ std::string_view getName()const{return " c3 ";}};
class D3:public C3{public:/*virtual*/ std::string_view getName()const{return " d3 ";}};

class A4{public:virtual std::string_view getName()const{return " a4 ";}};
class B4:public A4{public:virtual std::string_view getName()/*const*/{return " b4 ";}};
class C4:public B4{public:virtual std::string_view getName()/*const*/{return " c4 ";}};
class D4:public C4{public:virtual std::string_view getName()/*const*/{return " d4 ";}};

class A5{
	public: A5(){std::cout<<getName();}
		virtual std::string_view getName()const{return " a5 ";}
};
class B5:public A5{public:virtual std::string_view getName()const{return " b5 ";}};
class C5:public B5{public:virtual std::string_view getName()const{return " c5 ";}};
class D5:public C5{public:virtual std::string_view getName()const{return " d5 ";}};


//class AA{public:virtual AA(){ std::string_view getName()const{return " aa ";}}};
//class AA{public: AA(){virtual std::string_view getName()const{return "AA";}}};
//class BB : public AA{
//	public:/*virtual*NOT Working*/ BB(){std::string_view getName const{};}
//};

int main(){
	std::cout<< "rBase is a reference to the base class A.When initializes with c, the compiler will call the best match of getName\n";
	std::cout<< "between a and c, since with c initialized he takes C::getName.\n";
	std::cout<< "Do not call virtual function from Constructors and Destructors, because when the derived Class is created,\n";
	std::cout<< "the Base portion is created first, the derived don't exist so allways the Base's function is called\n";
	/*Problem to call out of a constructor a virtual function*/
C c;
A& rBase{c};
std::cout << "rbase is a " << rBase.getName() << '\n';
//BB bb;
//AA& rBBase{bb};
std::cout << "virtual removed in Base, so Base::getName is executed.\n";
C1 c1;
A1& rBase1{c1};
std::cout << "rbase1 is a " << rBase1.getName() << '\n';/**/

std::cout << "virtual removed in C, so B::getName is executed.\n";
C2 c2;
A2& rBase2{c2};
std::cout << "rbase2 is a " << rBase2.getName() << '\n';/**/

std::cout << "virtual removed in B,C,D so C::getName is executed. compiler considers B,C,D IMPLICITLY getName as virtual, because Base is virtual.C::getName is executed\n";
C3 c3;
A3& rBase3{c3};
std::cout << "rbase3 is a " << rBase3.getName() << '\n';/**/

std::cout << "const removed in B,C,D so A::getName is executed. compiler considers B,C,D NOt as OVERRIDERS because of const in Base, so A::getName is executed\n";
C4 c4;
A4& rBase4{c4};
std::cout << "rbase4 is a " << rBase4.getName() << '\n';/**/

std::cout << " a5 from constructor and than c5. Do NOT call virtual out of Constructor or Destructor\n";
C5 c5;
A5& rBase5{c5};
std::cout << "rbase5 is a " << rBase5.getName() << '\n';/**/

std::cout << "when object c is created, A part is done first, when constructor of A is called, B,C getName do not exist so compiler calls A::getName. so first a5 \n";
C5 c6;
//std::cout << "rBBase is a " << rBBase.getName() << '\n';
	return 0;
}
