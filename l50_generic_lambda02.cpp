#include<algorithm>
#include<array>
#include<iostream>
#include<string_view>
int main(){
std::cout<<"if lambdas has one or more auto parameter are called generic lambdas:\n";
constexpr std::array words{"only","fools","are","believing","intelligence","is","qualy","distibuted"};
//adjacent_find stops at the first true
std::cout<<"it is better to put the lambda as an initozer than to use it directly:\n";

const auto same_first_letter{std::adjacent_find(words.begin(),words.end(),/*lbd*/[](const auto& a, const auto& b){return(a[0]==b[0]);}/*lbd*/)};
if(same_first_letter != words.end()){std::cout<<*same_first_letter<<" and "<< *std::next(same_first_letter)<<" are consecutives and have the same first letter\n";}



//std::count_if stops at end for every
const auto two_letter{std::count_if(words.begin(),words.end(),[](std::string_view str){return(str.length()==2);})};
std::cout<< "Number of two letter words are: "<< two_letter <<'\n';

return 0;
}
