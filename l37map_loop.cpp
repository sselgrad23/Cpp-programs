#include<iostream>
#include<map>
#include<map>
#include<typeinfo>
//bool su(){return false;}
int main()
{
	const std::map<int,char>my_map{ {0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'} };
	const std::map<double,char>my_map_d{ {0.1,'a'},{0.2,'b'},{0.3,'c'},{0.4,'d'},{0.5,'e'} };
    std::cout<<"first pos\n";
	for(const auto&[key,value]:my_map)std::cout<<'['<<key<<"]= "<<value<<'\n';
    std::cout<<"second pos\n";
    for(auto i : my_map_d) std::cout<<'[' << i.first<<"]= " <<  i.second<<'\n' ;
	auto search = my_map.find(3);/*immer nur das erste*/
	if (search!=my_map.end())std::cout<<"found "<<search->first<<' '<<search->second<<'\n';
	else std::cout<<"not found\n";
//	for(auto ptr{std::begin(my_map)};ptr!=std::end(my_map);ptr++){if(ptr->second=='C')std::cout<<'['<<ptr->first<<"]= "<<ptr->second<<'\n';}
	auto gefunden_ALT{[](auto c,std::map<auto,auto> m){for(auto ptr{std::begin(m)};ptr!=std::end(m);ptr++){if(ptr->second==c)std::cout<<'['<<ptr->first<<"]= "<<ptr->second<<'\n';}}};
	auto gefunden_NEU{[](auto c,std::map<auto,auto> m){for(auto i:m){if(i.second==c)std::cout<<'['<<i.first<<"]= "<<i.second<<'\n';}}};
	gefunden_ALT('D',my_map);
	gefunden_NEU('c',my_map_d);

	return 0;
}

