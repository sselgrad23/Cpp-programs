//c++-11 -Wall -o p make_unique01.cpp -std=c++2a
#include<iostream>
#include<memory>
//make_unique<>() is NOT a protection against a class with memory leak
//only use to get quick a pointer on an instance of a class and delete the class but not the allocated memory
//which here is already a wraper around memory
class C
{
	int  m_i{0};
    int* m_ptr{nullptr};
	public:
		C(int i):m_i{i}{std::cout<<"C(auto i) with m_i: "<<m_i<<'\n';m_ptr = new int [m_i];}
		void func(){std::cout<<"func() with m_i: "<<m_i<<"cont [0] "<< m_ptr[0]<<'\n';}
		~C(){std::cout<<"~C() with m_i: "<<m_i<<'\n';/*delete[] m_ptr;*/}//useless make_unique still memory leak if you forget this
};

class Warp/*a wrapper around warped memory*/
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


	
//	Warp w{888};
//	w.get_ptr()->func();/*namless Object or:*/
//	auto access{w.get_ptr()};/*now name and type deduction*/
//	access->func();
	
/*std::make_unique: class Warp and function warp_in_ptr is done by compiler from a template*/
	auto acc{std::make_unique<C>(14)};/*Creates an object and warp it in a  pointer AND DELETE it for you*/
	acc->func();

	return 0;
}
