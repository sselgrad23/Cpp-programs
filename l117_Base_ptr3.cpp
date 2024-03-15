#include<iostream>
#include<string_view>
#include<string>
#include<array>
class Animal
{
	protected:std::string m_name;
	protected:Animal(std::string_view name):m_name{name}{}
		  Animal(const Animal&)=default;
		  Animal& operator=(const Animal&)=default;
	public:std::string_view getName() const{return m_name;}/*no need to make Virtual because not over written in derived*/
	     virtual  std::string_view speak()const{return "?? ";}
};
class Cat:public Animal
{
public:Cat(std::string_view name):Animal{name}{};
virtual std::string_view speak()const{return "meow  ";}
};
class Dog:public Animal
{
public:Dog(std::string_view name):Animal{name}{};
virtual std::string_view speak()const{return "woof ";}
};
int main(){
const Cat fred{"fred"};
const Cat misty{"misty"};
const Cat zeke{"zeke"};
const Dog ben{"ben"};
const Dog bill{"bill"};
const Dog top{"top"};
const auto animals{std::to_array<const Animal*>({&fred,&misty,&zeke,&ben,&bill,&top})};
//now virtual
for(const auto animal : animals){std::cout <<animal->getName() << " saya " << animal->speak() <<'\n';}
	return 0;
}
