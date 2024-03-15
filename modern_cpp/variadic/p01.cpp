#include<iostream>
template<typename T>
T add(T value)
{
	return value;
};
template<typename T,typename... Ts>
T add(T head,Ts... rest)
{
	return head + add(rest...);
};

int main()
{
	auto s1= add(1,2,3,4,5);
	std::cout<<s1<<'\n';
	return 0;
}
