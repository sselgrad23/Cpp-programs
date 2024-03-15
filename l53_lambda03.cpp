#include<iostream>
#include<array>
#include<string>
#include<algorithm>
struct Car { std::string maker{};std::string model{};};
int main()
{
 std::array <Car,4>cars{{{"Mitsubishi","Lancer"},{"VW","Lupo"},{"Toyota","Jaris"},{"Honda","Prelude"}}};/*{{ { two dim},  }}*/
 int compare{0};
 std::sort(cars.begin(),cars.end(),[&compare](const auto& a, const auto& b){++compare;return a.maker<b.maker;});
 std::cout << "number of comparisons: " << compare  << '\n';
 for(const auto& car: cars)std::cout << car.maker << ' ' << car.model << '\n';
 return 0;
} 
