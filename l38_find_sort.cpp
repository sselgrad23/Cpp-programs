//g++-11 -Wall -o p l38_find_sort.cpp -std=c++2a


#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
int next() {return 6;}
bool IsSEVEN(int i){if(i==7)return true;else return false;}
bool greater(int a, int b){return (a>b);}
void times_four(int& i){i*=4;}
int main()
{

 std::cout << "std::find returns an iterator "  << '\n';
 std::cout << "example a pointer:"  << '\n';

 std::vector v{7,7,7,1,3,2,3,4,5,6,7,5,2};
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
// auto ptr{v.begin()};
// ++ptr;++ptr;
 auto ptr {std::find( v.begin(),v.end(),2)};/*pointer ptr initialzed at element 2*/ 
 v.erase(ptr);/*with erase pointer points to next element*/

 ptr =std::find(ptr,v.end(),2);/*second 2 */
 v.erase(ptr);

 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
// auto ptr{v.begin()};
// ++ptr;++ptr;
 v.erase(std::remove(v.begin(),v.end(),3),v.end());
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 v.erase(std::remove(v.begin(),v.end(),next()),v.end());/*next returns an int*/
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';


// v.erase(std::remove_if(v.begin(),v.end(),true),v.end());
// for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
// std::cout << '\n';

auto found{std::find_if(v.begin(),v.end(),IsSEVEN)};/*IsSEVEN pointer to function bool IsSEVEN(int)*/
if(found == v.end())std::cout<<"no 7"<<'\n';else std::cout<<"7 found \n";   


auto count{std::count_if(v.begin(),v.end(),IsSEVEN)};/*IsSEVEN pointer to function bool IsSEVEN(int)*/
std::cout << "number of 7: " << count <<'\n';

std::vector v2{5,4,0,8,6,1,7};
for(auto i : v2)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
std::sort(v2.begin(),v2.end(),greater);/*greater pointer to custom function*/
 for(auto i : v2)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

std::vector v3{9,5,6,3,8,1,2,9};
for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
std::sort(v3.begin(),v3.end(),std::greater{});/*std::greater is a type not a callable function so it neds {} to instantiate an object of this type*/
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 std::erase(v3,3);/*g++-11*/
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 std::for_each(v3.begin(),v3.end(),times_four);
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
//since c++20;
 std::ranges::for_each(v3,times_four);
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

  for(auto& i : v3)times_four(i);/*i is NOT a  pointer*/
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 std::for_each(std::next(v3.begin()),v3.end(),times_four);/*std::next pointer to next element*/
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';



 
 return 0;
} 
