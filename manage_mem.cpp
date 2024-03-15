#include<iostream>
#include<typeinfo>
#include<string_view>
struct Comp{double real;double imag;};
template<typename T>
class Mem
{
	private:
		T* ptr{nullptr};
	public:
		Mem(T,long si)
		{
			ptr=new T[si];
			std::cout<<"Mem for "<< si <<" "<< typeid(T).name()<<" retrive\n";
		}
		~Mem()
		{
			delete [] ptr;
			std::cout<<"Mem relive\n";
		}
		T* return_ptr(){return ptr;}
		void print_zero(){std::cout<<"elenent [0]: "<<ptr[0]<<'\n';}
};
int main()
{

	std::cout<<"retutn type of typeid:" <<typeid (typeid("wert").name()).name()<<'\n';
	Mem m1(0,10);
	int* int_ptr{nullptr};
	int_ptr=m1.return_ptr();
	int_ptr[0]=19;
	m1.print_zero();
	Mem m2('c',5);
	char* char_ptr{nullptr};
	char_ptr=m2.return_ptr();
	char_ptr[0]='G';
	m2.print_zero();
	Mem m3(0.0,6);
	double* d_ptr{nullptr};
	d_ptr=m3.return_ptr();
	d_ptr[0]=12.34;
	m3.print_zero();

	std::string_view s{" "};
	Mem m4(s,20);
	std::string_view* str_ptr{nullptr};
	str_ptr=m4.return_ptr();
	str_ptr[0]="hello";
	m4.print_zero();

	Comp comp;
	Mem m5(comp,20);
	Comp* comp_ptr{nullptr};
	comp_ptr=m5.return_ptr();
	comp_ptr[0].real=19.9;
//	m5.print_zero();



}
