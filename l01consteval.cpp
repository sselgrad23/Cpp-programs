#include<iostream>
#include<type_traits>
/*remove  constexpr for testing */
/*constexpr evaluation at compile time if argument known at compile time else run time*/
constexpr unsigned factorial(unsigned n){
if(std::is_constant_evaluated())return n<2?1:n*factorial(n-1);
else std::cout<<"run time\n";
return 0;
}
/*consteval makes sure that function gets evaluated at compile time */
consteval unsigned factorial2(unsigned n){return n<2?1:n*factorial(n-1);}


int main(){
constexpr unsigned x{factorial(5)};/*argument known at compile time-> evaluation at compile time */
std::cout<<x<<'\n';
auto w{0};
std::cin>>w;
const unsigned k{factorial(w)};/*argument not known at compile time-> evaluation at run time */
std::cout<<k<<'\n';


const auto z{6};
unsigned y{factorial2(z)};/*consteval -> compile time*/
std::cout<<y<<'\n';

//std::cin>>w;
//unsigned p{factorial2(w)};/*will not compile*/
	return 0;
}
