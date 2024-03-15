#include<iostream>
#include<vector>
class Myclass
{
	public:  static std::vector<char> s_char;
	public:class init_static{public:init_static(){for(char ch{'a'};ch<='z';++ch)s_char.push_back(ch);}};
	private: static init_static s_initilizer;
};
std::vector<char> Myclass::s_char{};/*Definition*/
Myclass::init_static Myclass::s_initilizer{};/*Definition of s_initilizer causes contructor of class initstatic to fill in characters in Myclass::s_char*/


int main(){

	return 0;
}
