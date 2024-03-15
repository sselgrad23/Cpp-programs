//c++-11 -Wall -o p make_unique01.cpp -std=c++2a
#include<iostream>
#include<memory>

class C
{
	int  m_i{0};
	public:
		C(int i):m_i{i}{std::cout<<"C(auto i) with m_i: "<<m_i<<'\n';}
		void func(){std::cout<<"func() with m_i: "<<m_i<<'\n';}
		~C(){std::cout<<"~C() with m_i: "<<m_i<<'\n';}
};
/*function shoud not be member so that can be reused*/
class C* warp_in_ptr(int a)
{
	class C* ret{new C(a)}; 
	return ret;
}
/*function shoud not be member*/
class Warp
{
	class C* m_ptr;
	public:
		Warp(int i):m_ptr{warp_in_ptr(i)}{}
		class C* get_ptr(){return m_ptr;}
		~Warp(){delete m_ptr;}
};


int main()
{
	{
		C c1{3};
		c1.func();
	}
	C* c_ptr{new C(9)};
	c_ptr->func();
	delete c_ptr;/*because this is often forgotten and causes a memory leak: */
	


	class C* p{warp_in_ptr(999)};
	delete p;/*still possible to forget therefore:*/


	{
	Warp w{888};
	w.get_ptr()->func();/*namless Object or:*/
//	class C* access{w.get_ptr()};/*now name*/
	auto access{w.get_ptr()};/*now name and type deduction*/
	access->func();
	}
/*std::make_unique: class Warp and function warp_in_ptr is done by compiler from a template*/
	auto acc{std::make_unique<C>(14)};/*Creates an object and warp it in a  pointer AND DELETE it for you*/
	acc->func();

	return 0;
}
