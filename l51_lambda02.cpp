//g++-11 -Wall -o p l38_find_sort.cpp -std=c++2a


#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<string_view>
int counter=0;
int counter2=0;
int counter3=0;
void IsSEVEN(int i){if(i==7)++counter;}
int main()
{

 std::cout << "std::find returns an iterator "  << '\n';
 std::cout << "example a pointer:"  << '\n';
 std::cout << "lambda(anonymous function not a function but functor) definition [](){} is of type functor"  << '\n';

 std::vector v3{7,7,7,1,3,2,3,4,5,6,7,5,2};
 for(auto i : v3)std::cout << i << ' ';/*i is NOT a  pointer*/
 std::cout << '\n';
 std::ranges::for_each(v3,[](int i){if(i==7)++counter;});
 std::cout << counter << '\n';
 
 constexpr std::array<std::string_view,5> a{"der", "die", "Zwerge","ist","geross"};
 for(auto i : a)std::cout << i << ' ';/*i is NOT a  pointer*/
 counter=0;/*example of lambda literal*/
 std::ranges::for_each(a,[](std::string_view str){if(str.find("er")!=std::string_view::npos)++counter;});

 std::cout << counter << '\n';
 counter=0;
 //this will NOT compile:
// std::string search{};
// std::cin >>search;
//std::ranges::for_each(a,[](std::string_view str){if(str.find(   serach    )!=std::string_view::npos)++counter;});
//lambdas can only access global identifiers, entities known at compile time with static storage duration:

 static std::string search{"er"};
//                                                                                                   global identifier 
 std::ranges::for_each(a,[](std::string_view str){if(str.find(   search    )!=std::string_view::npos)++counter;});
 std::cout << counter << '\n';
 counter=0;
//lamda capture clause
// static int counter1=0;
 std::string such1{};/*free to change*/
 std::cin >>such1;
//                      capture clause can't change ii                   now working
std::ranges::for_each(a,[   such1    ](std::string_view str){if(str.find(   such1    )!=std::string_view::npos)++counter;});
std::cout << counter << '\n';
//will NOT work because counter is read only to lambdab but gets changed in function at duration of lambda:
//int counter1{0};
//std::ranges::for_each(a,[   counter1    ](std::string_view str){if(str.find(  "die"    )!=std::string_view::npos)++counter1;});
 std::string such2{};
 std::cin >>such2;
 std::string such3{};
 std::cin >>such3;
//                      capture clause                                 now working
std::ranges::for_each
	(a,/*list of variable to give access, but must NOT changed of lambda's duration, inside the lambda they are copies(colnes with same name) and init with the value of outer scope here what we type in */
		[   such2,such3    ](std::string_view str)
		{ /*such2="ert"; will NOT compile*/
		if(str.find(   such2    )!=std::string_view::npos)++counter2;/*count2 MUST be declalare in Global space*/
		
		if(str.find(   such3    )!=std::string_view::npos)++counter3;
		}
	);
std::cout << counter2 << ' ' << counter3 <<'\n';
std::cout << " now lambda capture with mutable counter4/5 will show 0, since ONLY copies in labda definition get changed" <<'\n';


 std::cin >>such2;

 std::cin >>such3;
 int counter4=0;
 int counter5=0;
//                      capture clause                                 now working
std::ranges::for_each
	(a,/*list of variable to give access, but must NOT changed of lambda's duration, inside the lambda they are copies(colnes with same name) and init with the value of outer scope here what we type in */
		[   such2,such3,counter4,counter5    ](std::string_view str)
		mutable/*now all caputerd can be changed*/
		{ /*such2="ert"; will NOT compile*/
		if(str.find(   such2    )!=std::string_view::npos)++counter4;/*count4 MUST be declalare in Global space or MUTABLE*/
		
		if(str.find(   such3    )!=std::string_view::npos)++counter5;

std::cout <<"in lambda " << counter4 << ' ' << counter5 <<'\n';
		}
	);
std::cout <<"in main " <<  counter4 << ' ' << counter5 <<'\n';

std::cout << " now lambda capture WITHOUT MUTABLE but REFERENCE to counter4/5, will show the right in main" <<'\n';

std::cin >>such2;
 std::cin >>such3;
 counter4=0;
 counter5=0;
 std::ranges::for_each
	(a, 
		[   such2,such3,&counter4,&counter5    ](std::string_view str)
//		mutable/*not needet because of reference */
		{ /*such2="ert"; will NOT compile*/
		if(str.find(   such2    )!=std::string_view::npos)++counter4;
		
		if(str.find(   such3    )!=std::string_view::npos)++counter5;

std::cout <<"in lambda " << counter4 << ' ' << counter5 <<'\n';
		}
	);
std::cout <<"in main   " <<  counter4 << ' ' << counter5 <<'\n';




		 return 0;
} 
