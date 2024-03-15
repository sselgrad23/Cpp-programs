#include<iostream>
#include<vector>
#include<map>


std::vector<int> getContens()
{
return std::vector<int>{12,13,15,43,65,77,90};
}

std::map<int,bool> getContens2()
{
return std::map<int,bool>{{12,false},{13,true},{15,false},{43,true},{65,false},{77,true},{90,false}};
}




int main()
{
	auto cont=getContens();
	for(auto c:cont)std::cout<< c <<' ';
	std::cout<<'\n';

	for(auto& c:cont)c*=3;
	for(auto c:cont)std::cout<< c <<' ';
	std::cout<<'\n';
	for(auto&&[c,f]:getContens2())std::cout<< c <<' '<<f<<' ';
	std::cout<<'\n';

//	for(auto&&[c,f]:getContens2())c*=3;/*will not compile*/


	return 0;
}
