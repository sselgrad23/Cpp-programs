#include<iostream>
#include<vector>
class foo
{
int m_a;
int m_b;
std::vector<int> v;
public:
foo():m_a{0},m_b{0}{std::cout<<"foo()\n";}
foo(int a=0,int b=0):m_a{0},m_b{0}{std::cout<<"foo(int a=0,int b=0)\n";}             
foo(std::initializer_list<int>l):v{l}{std::cout<<"foo(std::initializer_list<int>l)\n";}/*avoid elipsis*/
std::vector<int> get(){return v;}
};
int main(){
foo i(1,2);
foo f{1,2};
foo g{1,2,3,4,5,6,7,8,9};
for(auto i:g.get())std::cout <<"g.v "<< i << ' ';
	return 0;
}
