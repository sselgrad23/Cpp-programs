#include<iostream>
#include<type_traits>
#include<typeinfo>
template<typename T, typename U>
T same (T i,U j){
//std::cout<<std::is_same<T,U>::value<<'\n';
if( typeid(T)==typeid(0))std::cout<<"is integer\n";
if( typeid(T)==typeid(0.0))std::cout<<"is double\n";


if(std::is_same<T,U>::value){std::cout<<"same\n";return i+j;}
else {std::cout<<"not same\n";return i;}
}
class A{};
class B{};

template<typename T>
void which(T i){
if(std::is_same<T,int>::value){std::cout<<"int\n";}
if(std::is_same<T,double>::value){std::cout<<"double\n";}
if(std::is_same<T,char>::value){std::cout<<"char\n";}
}



int main()
{
//std::cout<<std::is_same<int,int>::value<<'\n';
same(1,9);
same(1.1,9);
//A a;
//B b;
//same(a,b);
int i{9},j{8};
double d{10};
std::cout <<same(i,j)<<'\n';
std::cout <<same(i,d)<<'\n';

std::cout<<"neu\n";
which(9);
which(9.9);
which('9');

	return 0;

}
