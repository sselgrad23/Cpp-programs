//g++-11 -Wall -o p l101_stdREFwrapper.cpp -std=c++2a

#include<iostream>
#include<functional>
#include<vector>
#include<string>

int main(){
	std::cout << "fixed arrays and various std libraries lists can not hold references, because\n";
	std::cout << "list elements must be assignable and reference can't be reassigned.\n";
	std::cout << "Therefore std::refernce_wrapper:\n";
	std::string tom{"Tom"};
	std::string berta{"Berta"};

//	std::vector<std::string &>>names{tom,berta};
	std::vector<std::reference_wrapper<std::string>>names{tom,berta};
	std::string jim{"Jim"};
	names.push_back(jim);
//	for(auto name : names)names.get()+="Beam";
	std::cout << jim << '\n';

	return 0;
}
