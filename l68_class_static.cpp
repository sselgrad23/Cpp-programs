#include<iostream>
#include<array>
class show{public:static int s_value;};
int show::s_value{1};/*don't forget int, otherwise constructor*/
                                                                      /*initialization of static FORBIDDEN BUT static const ALLOWED*/
class show2{public:static int s_value2;static const int sc_value5{77}; private: static int s_value3/*{90}*/;static const int sc_value4{9};;};
int show2::s_value2{1};
int show2::s_value3{90};/*INITIALIZATION possible, although declared PRIVATE, but std::cout << show2::s_value3 <<'\n'; NOT COMPILING*/
class show3{static constexpr double sc_d {8.9};static constexpr std::array<int,3> s_arr {1,2,3};};

class Count_instanziation{private:static int count;int m_c;public:void fct(){std::cout<<++count<<'\n';}};
int Count_instanziation::count{1};

int main(){
	std::cout << "static member variables are shared between all objects of the class and are not associated with a class" << '\n';
	show a;
	show b;
	a.s_value=2;
	std::cout << "don't access value by: a.s_value "<<  a.s_value  <<'\n';/*2*/
	std::cout << "don't access value by: b.s_value "<<  b.s_value  <<'\n';/*2*/

	std::cout << "better access value by: show::s_value "  <<   show::s_value <<'\n';/*also 2*/
//NO INSTANTIATIO OF CLASS show2 but this compiles:
	show2::s_value2 =20;
	std::cout << show2::s_value2 <<'\n';/* 20 */
//	std::cout << show2::s_value3 <<'\n';/* NOT COMPILING becaus of PRIVATE */

//	std::cout << show2::sc_value4 <<'\n';/* NOT COMPILING becaus of PRIVATE */
	std::cout << show2::sc_value5 <<'\n';/* NOT COMPILING becaus of PRIVATE */
	Count_instanziation ci1;
	ci1.fct();
	Count_instanziation ci2;
	ci2.fct();
	Count_instanziation ci3;
	ci3.fct();
	return 0;
}
