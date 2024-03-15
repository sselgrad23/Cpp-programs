#include<iostream>
class Klasse{
	public:Klasse()=default;
	public:Klasse(int n=0, double d=2.7){};
	       Klasse(double d=2.7){};
};
class Kern{public:Kern(){std::cout << "Kern" << '\n';}};
class Huelle{
	public:Kern k;
	public:Huelle(){std::cout << "Huelle" << '\n';};
};
class Initialization_list{
 private:int m_i{};
	double m_d{};
 public:Initialization_list(): m_i{0},m_d{0.0}{}
	void print(){std::cout << "Initialization_list::print " << m_i << " " << m_d << '\n';}
};
class Initialization_list2{
 private:int m_i{};/*order starts here for initilizer list*/
	double m_d{};
	char m_c{};
	const int m_v;                                                          /*m_v{7} is allowed but m_v=7 NOT*/
	const int m_arr[5];
	const int m_arr2[5];
 public:Initialization_list2(int i, double d, char c='l'): m_i{i},m_d{d}, m_c{c},m_v{7},m_arr{},m_arr2{1,2,3,4,5} {/*m_v=9;*/}/*directly initialize member*/
	void print(){std::cout << "Initialization_list2::print " << m_i << " " << m_d << ' ' << m_c << '\n';}
};
class A{public:A(int i=0){std::cout << "A:: " << i << '\n';}};
class B{private:A m_a{}; 
	public:B(int y): m_a{y-2}{std::cout << "B:: " << y << '\n';};
};
int main(){
	std::cout << "constructors, initilizer lists are not initialized as in list but as they are delared in class" << '\n';
	Klasse k1{1,7.7};
	Klasse k2{6.7};
	Huelle h;
	Initialization_list l{};/*braces*/
	l.print();
	Initialization_list2 l2{1,1,1};/*braces*/
	l2.print();
	B b{10};
	return 0;
}
