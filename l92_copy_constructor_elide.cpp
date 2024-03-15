#include<iostream>
class Something
{
	public: Something()=default;
		Something(const Something&){std::cout << "copy constructor called\n";}
};
Something foo(){return Something();}/*copy constructor nomally called here*/
Something goo(){Something s; return s;}/*copy constructor normaly called here*/

int main(){
	std::cout << "inti s1\n";
	Something s1=foo();/*copy constuctor normally called here*/
	std::cout << "inti s2\n";
	Something s2=goo();/*copy constuctor normally called here*/
	return 0;
}
