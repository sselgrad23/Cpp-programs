//g++-11 -Wall -o p l50_std_func_obj05.cpp -std=c++2a
#include<algorithm>
#include<iostream>
#include<array>
#include<string>
// bool greater(/*auto not possible*/int  a,int b){return (a>b);}
// bool greater_d(/*auto not possible*/double  a,double b){return (a>b);}
template<typename T>bool smaller(T a,T b){return(a<b);}
template<typename T>bool bigger(T a,T b){return(a>b);}
struct Paar{
std::string word{}; 
int value;
	friend bool operator<(const Paar& p1,const Paar& p2){return  (p1.value<p2.value);};
    friend bool operator>(const Paar& p1,const Paar& p2){return  (p1.value>p2.value);};
};
int main(){

std::array<Paar,5> arr{
{/*don't forget*/
{"die ",5},
{"Welt ",4},
{"ist ",3},
{"so",1},
{"schoen ",2}
}/*don't forget*/
};
/*simple with lambda*/
const auto longest{std::max_element(arr.begin(),arr.end(),[](const auto& a,const auto& b){return (a.value<b.value);})};
std::cout<< longest->word <<" is the longest word\n";
const auto shortest{std::max_element(arr.begin(),arr.end(),[](const auto& a,const auto& b){return (a.value>b.value);})};
std::cout<< shortest->word <<" is the shortest word\n";
/*better with friend function overload < and > and lambda*/
const auto shortest_better{std::max_element(arr.begin(),arr.end(),[](const auto& a,const auto& b){return (a>b);})};
const auto longest_better{std::max_element(arr.begin(),arr.end(),[](const auto& a,const auto& b){return (a<b);})};
std::cout<< shortest_better->word <<" is the shortest word and "<< longest_better->word <<" the longest\n";
/*best with template and friend function overload without lambda*/
const auto longest_best{std::max_element(arr.begin(),arr.end(),smaller<Paar>)};
const auto shortest_best{std::max_element(arr.begin(),arr.end(),bigger<Paar>)};
std::cout<< shortest_best->word <<" is the shortest word and "<< longest_best->word <<" the longest\n";

std::sort(arr.begin(),arr.end(),[](const auto& a,const auto& b){return (a>b);});
for(const auto& arr : arr)std::cout<<arr.word<<'\n';
std::sort(arr.begin(),arr.end(),bigger<Paar>);
for(const auto& arr : arr)std::cout<<arr.word;
std::cout<<'\n';
std::cout<<typeid(Paar).name();
return 0;
}
