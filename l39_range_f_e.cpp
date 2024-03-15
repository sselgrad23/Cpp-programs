//g++-11 -Wall -o p l39_range_f_e.cpp -std=c++2a


#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

bool greater(int a, int b){return (a>b);}
void times_four(int& i){i*=4;}
int main()
{

 std::cout << "std::find returns an iterator "  << '\n';
 std::cout << "example a pointer:"  << '\n';


using pair = std::pair<std::string,float>;
std::vector<pair> pairs{
{"Begin Ausschnitt",16.0f},
{"Ende Ausschnitt",15.0f}, 
{"PFL mV mK mN MW Ve Ka nW Me",27.0f},
{"Lsp mV mK mN MW Ve Ka nW Me",27.0f},
{"Linie loeschen",14.0f},
{"Auswahl 1n 5n An 1s 5s As",25.0f},
{"Zurueck Programmende",20.0f},
{"Firma aus E",11.0f},
{"Firma aus W",11.0f},
{"l0",2.0f},
{"l1",2.0f},
{"l2",2.0f}
};
auto print=[](const auto& n){std::cout<<' '<<n<<'\n';};
//std::ranges::for_each(pairs,print,[](const pair& p){return p.first;});
//std::ranges::for_each(pairs,print,&pair::second);

using my_tuple=std::tuple<int,std::string,float>;
 std::vector<my_tuple> my_tuples{
{0,"Begin Ausschnitt",16.0f},
{1,"Ende Ausschnitt",15.0f}, 
{2,"PFL mV mK mN MW Ve Ka nW Me",27.0f},
{3,"Lsp mV mK mN MW Ve Ka nW Me",27.0f},
{4,"Linie loeschen",14.0f},
{5,"Auswahl 1n 5n An 1s 5s As",25.0f},
{6,"Zurueck Programmende",20.0f},
{7,"Firma aus E",11.0f},
{8,"Firma aus W",11.0f},
{9,"l0",2.0f},
{10,"l1",2.0f},
{11,"l2",2.0f}
};
int my_int;
std::string my_string;
float my_float;
for(auto i:my_tuples){
std::tie(my_int,my_string,my_float)=i;
std::cout<<my_int<<' '<<my_string<<' '<<my_string<<' '<<my_float<<'\n';
}
//std::ranges::for_each(my_tuples,print,&my_tuple::second);
std::ranges::for_each(my_tuples,print,[](const my_tuple& p){
int my_int;/*auto not working, you need int*/
std::string my_string;
float my_float;
std::tie(my_int,my_string,my_float)=p;
return my_string;
		});
//std::ranges::for_each(my_tuples,print,[](const my_tuple& p){auto my;std::tie(std::ignore,my,std::ignore)=p;return my;});
std::ranges::for_each(my_tuples,print,[](const my_tuple& p){
int my_int;
//std::string my_string;
//float my_float;
std::tie(my_int,std::ignore,std::ignore)=p;
return my_int;
		});


std::ranges::for_each(my_tuples,print,[](const my_tuple& p){
//int my_int;
std::string my_string;
//float my_float;
std::tie(std::ignore,my_string,std::ignore)=p;
return my_string;
		});


my_tuples.push_back(std::make_tuple(12,"let",3));
std::ranges::for_each(my_tuples,print,[](const my_tuple& p){
//int my_int;
std::string my_string;
//float my_float;
std::tie(std::ignore,my_string,std::ignore)=p;
return my_string;
		});



return 0;
} 
