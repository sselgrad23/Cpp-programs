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
	public:std::string_view getName() const{return m_name;}
	       std::string_view speak()const{return "?? ";}
};
class Cat:public Animal
{
public:Cat(std::string_view name):Animal{name}{};
std::string_view speak()const{return "meow  ";}
};
class Dog:public Animal
{
public:Dog(std::string_view name):Animal{name}{};
std::string_view speak()const{return "woof ";}
};
/*many classes -> many functins*/
void report(const Cat& cat){std::cout<<cat.getName() << " says "  << cat.speak() << '\n';}
void report(const Dog& dog){std::cout<<dog.getName() << " says "  << dog.speak() << '\n';}
/*better one only with Base, but you can not access Cat::speak nor Dog::speak*/
void report(const Animal& rAnimal){std::cout<<rAnimal.getName() << " says "  << rAnimal.speak() << '\n';}

int main(){
const Cat cat{"fred"};
std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';
const Dog dog{"Ben"};
std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';
std::cout << "pAnimal is a pointer to Animal and only sees the function of Animal\n";
std::cout << "if you would have made an pointer to Dog you can not use it for Cat\n";
std::cout << "What you want is a pointer to the derived Class, which point then to the FUNCTION of the DERIVED but not to the Base's fct.\n";
const Animal* pAnimal{&cat};
std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
pAnimal=&dog;
std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
const auto&cats{std::to_array<Cat>({{"fred"},{"misty"},{"zeke"}})};	
const auto&dogs{std::to_array<Dog>({{"bill"},{"jack"},{"pooky"}})};/*all bad for every object an array an function!!!!*/
for(const auto& cat : cats){std::cout << cat.getName()<<" says "<<cat.speak()<<'\n';}	
for(const auto& dog : dogs){std::cout << dog.getName()<<" says "<<dog.speak()<<'\n';}/*all bad*/	
const Cat fred{"fred"};
const Cat misty{"misty"};
const Cat zeke{"zeke"};
const Dog ben{"ben"};
const Dog bill{"bill"};
const Dog top{"top"};
const auto animals{std::to_array<const Animal*>({&fred,&misty,&zeke,&ben,&bill,&top})};
//still ?? becaus Base speak!!!!
for(const auto animal : animals){std::cout <<animal->getName() << " saya " << animal->speak() <<'\n';}
	return 0;
}
