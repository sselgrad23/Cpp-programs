//g++-11 -Wall -o p l38_find_sort.cpp -std=c++2a


#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

class myfind:std::find{

};



int main()
{

 std::cout << "std::find returns an iterator "  << '\n';
 std::cout << "example a pointer:"  << '\n';

 std::vector v{7,7,7,1,3,2,3,4,5,6,7,5,2};
 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';

 auto ptr {std::find( v.begin(),v.end(),2)};/*pointer ptr initialzed at element 2*/ 
 v.erase(ptr);/*with erase pointer points to next element*/

 //ptr =std::find(ptr,v.end(),2);/*second 2 */
 //v.erase(ptr);

 for(auto i : v)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';


 
 return 0;
} 
