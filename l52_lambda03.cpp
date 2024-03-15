//g++-11 -Wall -o p l38_find_sort.cpp -std=c++2a


#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<string_view>
int main()
{

 std::cout << "Default captures "  << '\n';
 std::cout << "= by value copies & by reference"  << '\n';



 constexpr std::array<std::string_view,6> a{"die", "Macht", "der", "Zwerge","ist","gross"};
 for(auto i : a)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::string such2{};
 std::cin >>such2;
 std::string such3{};
 std::cin >>such3;
 int counter4=0;
 int counter5=0;


 std::ranges::for_each
	(a, 
	//	[   such2,such3,&counter4,&counter5    ](std::string_view str)
//		[   =,&counter4,&counter5    ](std::string_view str)
//		= stands for such2,such3 is by value you don't need to declare Preprocessor find the right ones or
//                               new variable, NO TYPE NEEDED because of typededuction, but needs MUTABLE because changes value
		[  &, such2,such3,counterTotal{counter4 + counter5}    ](std::string_view str)
		mutable/*for counterTotal*/
		{ /*such2="ert"; will NOT compile*/
		if(str.find(   such2    )!=std::string_view::npos)++counter4;		
		if(str.find(   such3    )!=std::string_view::npos)++counter5;
counterTotal=counter4 +counter5;/*you need this in capture is only the initialisation to 0 despite counter4,5 are by refernce */
std::cout <<"in lambda first " << counter4 << '+' << " second " << counter5 << '=' << counterTotal<<'\n';
		}
	);
std::cout <<"in main   " <<  counter4 << ' ' << counter5 <<'\n';




		 return 0;
} 
