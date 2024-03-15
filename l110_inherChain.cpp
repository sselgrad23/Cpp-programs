#include<iostream>
class A         {public:A(int a){std::cout<<"A: "<< a <<'\n';}};
class B:public A{public:B(int a,double b):A{a}{std::cout<<"B: "<< b <<'\n';}};
class C:public B{public:C(int a,double b,char c):B{a,b}{std::cout<<"C: "<< c <<'\n';}};
int main(){
C c{9,5.6,'G'};
	return 0;
}
