//c++-11 -Wall -o p make_unique01.cpp -std=c++2a
#include<iostream>
#include<memory>
//to avoid to write a wrapper for every type of class use Class template for wrapper
//but typename muss uebergeben werden, also muss eine instanz der class erzeugt werden und dann ins templat
//gegeben werden was ill formed ist wege new T90 kann kein pointer las Typename uebergeben werden
// am besten make_unique<C>(123) <C> type (123) argument
class C
{
	int  m_i{0};
	public:
		C(int i):m_i{i}{std::cout<<"C(auto i) with m_i: "<<m_i<<'\n';}
		void func(){std::cout<<"func() with m_i: "<<m_i<<'\n';}
		~C(){std::cout<<"~C() with m_i: "<<m_i<<'\n';}
};

class D/*second class with same type of initializer*/
{
	int  m_i{0};
	public:
		D(int i):m_i{i}{std::cout<<"D(auto i) with m_i: "<<m_i<<'\n';}
		void func(){std::cout<<"func() with m_i: "<<m_i<<'\n';}
		~D(){std::cout<<"~D() with m_i: "<<m_i<<'\n';}
};

class E/*third class with different type of initializer*/
{
	double  m_d{0.0};
	public:
		E(double d):m_d{d}{std::cout<<"E(auto i) with m_d: "<<m_d<<'\n';}
		void func(){std::cout<<"func() with m_d: "<<m_d<<'\n';}
		~E(){std::cout<<"~E() with m_d: "<<m_d<<'\n';}
};



template <typename T>
class Warp
{
    private:
	    T* m_ptr;
	    T* warp_in_ptr(auto a)
	    {
		    T* ret{new T(a)};/*it must be T so typename T cannot be a pointer*/ 
		    return ret;
	    }
	public:
		Warp(T t,auto i):m_ptr{warp_in_ptr(i)}{}
		T* get_ptr(){return m_ptr;}
		~Warp(){delete m_ptr;}
};


int main()
{

//	class C* p{warp_in_ptr(999)};/*not possible warp_in_pointer private*/
//	delete p;/*still possible to forget therefore:*/

{
    class C c(0);/*ill formed but working*/	
	Warp w{c,888};
	w.get_ptr()->func();/*namless Object or:*/
	auto access{w.get_ptr()};/*now name and type deduction*/
	access->func();
}
{
    class D d(0);/*ill formed but working*/	
	Warp v{d,999};
	v.get_ptr()->func();/*namless Object or:*/
	auto access{v.get_ptr()};/*now name and type deduction*/
	access->func();
}
{
    class E e(0.0);/*ill formed but working*/	
	Warp u{e,999.78};
	u.get_ptr()->func();/*namless Object or:*/
	auto access{u.get_ptr()};/*now name and type deduction*/
	access->func();
}	
/*std::make_unique: class Warp and function warp_in_ptr is done by compiler from a template*/
//	auto acc{std::make_unique<C>(14)};/*Creates an object after <C> and warp it in a  pointer AND DELETE it for you*/
//	acc->func();

	return 0;
}
