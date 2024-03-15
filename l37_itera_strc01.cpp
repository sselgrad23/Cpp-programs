#include<iostream>
#include<array>
#include<vector>
//std::vector<s3> s  {}
//std::vector<s3*> ptr_s{};
struct s{
int x;
int y;
//		void operator()(int xx,int yy)
//		{x=xx;y=yy;}



};
void fkt(std::vector<int> &/*DO NOT forget this otherwise you don't erase in main*/ v){
std::cout<<"vector";
for(auto i : v)std::cout << i << ' ';
std::cout << '\n'; 
auto ptr{v.begin()};
 ++ptr;++ptr;
 v.erase(ptr);/*erase only here not in main if & forgotten*/
}
void fkt2(std::vector<s> &/*DO NOT forget this otherwise you don't erase in main*/ v){
std::cout<<"vector";
std::for_each(v.begin(),v.end(),[](const auto& a){std::cout<<a.x<<' '<<a.y<<",";});
 std::cout << '\n';
auto ptr{v.begin()};
 ++ptr;++ptr;
 v.erase(ptr);
for (auto i{0};i<5;i++){s sp{100+i,550+2*i};v.push_back(sp);}
}



int main()
{

 std::cout << "an iterator is an object to traverse through a container providing access to element along the way"  << '\n';
 std::cout << "example a pointer:"  << '\n';
 std::array a{3,4,5,1,8};
 auto start(&a[0]);/*or array.a()*/
 auto end{start + std::size(a)};/*end pointer behind th array DON'T use int end{&a[std::size(a)] because it is a pointer accessing outside of a  */		 

 for(auto i :a)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';


 for(auto ptr {a.begin()};ptr!=end;++ptr)std::cout << *ptr << ' ';/*auto ptr you don't need to declare because of TYPEDDUCTION*/
 std::cout << '\n';



 std::vector v{1,3,2,4,6,7};
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer get it with typeof*/
 std::cout << '\n';

  auto startV{v.begin()};
  auto endV{startV + std::size(v)};
 for(auto ptr{startV};ptr!=endV;++ptr)std::cout << *ptr << ' ';
 std::cout << '\n';



 auto ptr{v.begin()};
 ++ptr;++ptr;
 v.erase(ptr);
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 fkt(v);
for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n'; 


std::vector<s>s_arr {{1,9},{2,23},{3,12},{4,41}};
 std::for_each(s_arr.begin(),s_arr.end(),[](const auto& a){std::cout<<a.x<<' '<<a.y<<",";});
 std::cout << '\n';
fkt2(s_arr);
std::for_each(s_arr.begin(),s_arr.end(),[](const auto& a){std::cout<<a.x<<' '<<a.y<<",";});
 std::cout << '\n';
s sp{2,55};
s_arr.push_back(sp);
std::sort(s_arr.begin(),s_arr.end(),[](const auto& a,const auto& b){return (a.y>b.y);});
std::for_each(s_arr.begin(),s_arr.end(),[](const auto& a){std::cout<<a.x<<' '<<a.y<<",";});
 std::cout << '\n'; 
 return 0;
} 
