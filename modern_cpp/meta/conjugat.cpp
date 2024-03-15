#include<iostream>
#include<type_traits>
#include<cstdarg>/*elipsis*/
template<typename T, typename... Ts>
std::enable_if_t<std::conjunction_v<std::is_same<T,Ts>...>>func(T, Ts...){std::cout<<"alle sind T\n";}
template<typename T, typename... Ts>
std::enable_if_t<!std::conjunction_v<std::is_same<T,Ts>...>>func(T, Ts...){std::cout<<"alle sind NICHT T\n";}

class A{};

template<typename T>
void print(T){
std::cout<<std::is_array<T>::value<<'\n';
}
int main()
{
    int s[]{1,2,3,4,5};
    int t[]{5,4,3,2,1};
std::cout<<sizeof(s)/sizeof(s[0])<<'\n';
	func(1,2,3,4,5,6,7,8,9,0,11,2,3,4,5,6,7,8,9,0);
	func(1,2,"Hello",9);
	func(s,5);
	func(s,t);
	func(s,t);

//std::cout<<std::is_array<A>::value<<'\n';
//std::cout<<std::is_array<A[5]>::value<<'\n';
A a;
print(a);
A b[3];
print(b);
	return 0;

}




