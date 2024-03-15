#include<iostream>
template<typename T>
struct wrapper{T const& val;};

template<typename T>
constexpr auto operator<(wrapper<T> const& lhs,wrapper<T> const& rhs)
{
	return wrapper<T>{lhs.val<rhs.val?lhs.val : rhs.val};
};
template<typename... Ts>
constexpr auto min(Ts&&...args)
{
	return (wrapper<Ts>{args}<...).val;
};
int main()
{
//	auto min(3,1,2);
	std::cout<<min(3,1,2,6,2,0)<<'\n';
	return 0;
}
