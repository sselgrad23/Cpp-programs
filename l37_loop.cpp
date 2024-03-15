#include<vector>
#include<map>
#include<iostream>
std::vector<int> getRates(){return std::vector<int>{1,2,1,3,1,4,6};}
/*mulimap is sorting*/
std::multimap<int,bool> getRatesP(){return std::multimap<int,bool>{{1,false},{2,false},{1,true},{3,false},{1,true},{4,false},{6,false}};}
/*a map s sortin and erasing doubles and takes the last for 1 as false all 1 true overwrittem*/
std::map<int,bool> getRatesM(){return std::map<int,bool>{{1,true},{2,false},{1,true},{3,false},{1,false},{4,false},{6,false}};}
int main(){
auto rates=getRates();
for(int rate:rates)std::cout<<rate<<'\n';
auto ratesP=getRatesP();
for(auto [key,value]:ratesP)std::cout<<"["<<key<<"]"<<value<<'\n';
auto ratesM=getRatesM();
for(/*std::pair*/auto [key,value]:ratesM)std::cout<<"["<<key<<"]"<<value<<'\n';


	return 0;
}
