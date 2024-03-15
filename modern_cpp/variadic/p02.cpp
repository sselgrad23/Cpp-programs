#include<iostream>
struct D
{
	int a;
	friend D operator+(D d1,D d2){
		D ret;
		ret.a=d1.a+d2.a;
		return ret;}
       friend std::ostream& operator<<(std::ostream& out,const D& d){out<<d.a;return out;}	
};

template<typename... Ts>
auto add(Ts... args)
{
	return (... + args);
};

template<typename... Ts>
void fill(Ts... args)
{
	(... + args);
};




int main()
{
	auto s1= add(1,2,3,4,5);
	std::cout<<s1<<'\n';

//	auto s2= fill(1,2,3,4,5);

	class D d1,d2,d3,d4;
	d1.a=1;
//	d1.b=2;
	d2.a=2;
//	d2.b=3;
	d3.a=3;
//	d3.b=4;
	d4.a=4;
//	d4.b=5;
	D arr=add(d1,d2,d3,d4);
	std::cout<<arr<<'\n';
	return 0;
}
