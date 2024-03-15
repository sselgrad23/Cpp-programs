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
	    T m_ptr;
	    T warp_in_ptr(auto a)
	    {
		    T ret{nullptr};
            ret=new sizeof(class D)(a);        /*GEHT NICHT Type muss uebergeben werden nicht pointer auf es*/ 
		    return ret;
	    }
	public:
		Warp(T t,auto i):m_ptr{warp_in_ptr(i)}{}
		T get_ptr(){return m_ptr;}
		~Warp(){delete m_ptr;}
};


int main()
{

//	class C* p{warp_in_ptr(999)};/*not possible warp_in_pointer private*/
//	delete p;/*still possible to forget therefore:*/

{
    class C* c{nullptr};/*also ill formed but working and only a pointer not a class*/	
	Warp w{c,888};
	w.get_ptr()->func();/*namless Object or:*/
	auto access{w.get_ptr()};/*now name and type deduction*/
	access->func();
}

/*std::make_unique: class Warp and function warp_in_ptr is done by compiler from a template*/
//	auto acc{std::make_unique<C>(14)};/*Creates an object and warp it in a  pointer AND DELETE it for you*/
//	acc->func();

	return 0;
}
