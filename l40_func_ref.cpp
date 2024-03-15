#include<iostream>
#include<cmath>
void add_two(int& ref){ref +=2;}
void ret_sin_cos(double angle, double& ret_sin, double& ret_cos)
{
	constexpr double pi{3.14159};
	double radi { angle * pi /180.0};
	ret_sin=std::sin(radi);
	ret_cos=std::cos(radi);
}
void ptr_to_NULL(int*& ptr){ptr=nullptr;}/*type int*  address & */
void prEl(int (&arr)[4])
{
	int num{sizeof(arr)/sizeof(arr[0])};
	for(int i{0};i<num;++i)std::cout<< arr[i]<<' ';
	std::cout<< '\n';
}

int main()
{
 std::cout << "cal by ref no copy of argument so quicker, ret for multiple values \n";
 int i{3};
 std::cout << i  << '\n';
 add_two( i);
 std::cout << i  << '\n';
 double sin{};
 double cos{};
 ret_sin_cos(60.0,sin,cos);
 std::cout << "sin: " << sin << " cos: " << cos << '\n';

 int* ptr{&i};
 std::cout << "ptr is: " << (ptr ? "non null " : "null") << '\n';
 ptr_to_NULL(ptr);
 std::cout << "ptr is: " << (ptr ? "non null " : "null") << '\n';

 int a[]{67,5,7,2};
 prEl(a);


 return 0;
} 
