#include<iostream>
#include<map>
#include<array>

struct Key{
char c;
};
struct Value{
int i;
std::string st;
int j;
};
struct Key_plus_Value{
Key k;
Value v;
};

int main(){
	using my_tuple=std::tuple<int,std::string,int>;
	std::map<char,my_tuple> mappe1{{'A',{1,"zehn",10} },  {'B',{2,"zwanzig",20} } ,{'C',{3,"dreizig",30}   }       };
//	for(const auto& [key,value]:mappe1){std::cout<<'['<<key<<']'<<": "<<value<<'\n';}





	std::map<std::string,int>m{ {"cpu",10},{"GPU",15},{"ram",20}};
    for(const auto& [key,value]:m){std::cout<<'['<<key<<']'<<": "<<value<<'\n';}



Key k0,k1,k2;
k0.c='A';
k1.c='B';
k2.c='C';

Value v0,v1,v2;
v0.i=1;
v0.st="zehn";
v0.j=10;

v1.i=2;
v1.st="zwanzig";
v1.j=20;

v2.i=3;
v2.st="dreizig";
v2.j=30;

Key_plus_Value k_p_v[3];
k_p_v[0].k=k0;
k_p_v[1].v=k1;
//k_p_v[2].v=k2;



	std::map<char,Value> mappe2{{'A',v0},{ 'B',v1},{'C',v2}};
    for(const auto& [key,value]:mappe2){std::cout<<'['<<key<<']'<<": "<<value.i<<' '<<value.st<<' '<<value.j<<'\n';}








	return 0;
}
