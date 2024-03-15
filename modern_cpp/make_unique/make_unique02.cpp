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


class D/*second class with same type of initializer*/
{
	int  m_i{0};
	public:
		D(int i):m_i{i}{std::cout<<"D(auto i) with m_i: "<<m_i<<'\n';}
		void func(){std::cout<<"func() with m_i: "<<m_i<<'\n';}
		~D(){std::cout<<"~D() with m_i: "<<m_i<<'\n';}
};



// Warp creates the object for you and DELETE it
// you handle the object with a pointer
// for EVERY class its own class Warp is bad therefore make _unique it takes the type and the arguments
// As TEMPLATE no possible because of type
class Warp
{
    private:
	    class C* m_ptr;
	    class C* warp_in_ptr(int a)
	    {
		    class C* ret{new C(a)}; 
		    return ret;
	    }
	public:
		Warp(int i):m_ptr{warp_in_ptr(i)}{}
		class C* get_ptr(){return m_ptr;}
		~Warp(){delete m_ptr;}
};


int main()
{

//	class C* p{warp_in_ptr(999)};/*not possible warp_in_pointer private*/
//	delete p;/*still possible to forget therefore:*/


	
	Warp w{888};
	w.get_ptr()->func();/*namless Object or:*/
	auto access{w.get_ptr()};/*now name and type deduction*/
	access->func();
	
/*std::make_unique: class Warp and function warp_in_ptr is done by compiler from a template*/
	auto acc{std::make_unique<C>(14)};/*Creates an object and warp it in a  pointer AND DELETE it for you*/
	acc->func();

	int* ptrA=new int[5];
    std::unique_ptr<int*> p = std::make_unique<int*>(ptrA);/*You DO NOT pass the array but only the pointer on it, so the pointer only is deleted NOT the array*/
    std::cout<<*(*p+1)<<'\n';


	return 0;
}
