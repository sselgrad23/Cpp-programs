#include<iostream>
// BAD place enum class FruitType{apple,banana,cherry};/*enum class act like a namespace therefore FruitType::*/
class Fruit
{
	public: enum /*class*/ FruitType{apple,banana,cherry};/*step 1. better placed*/
	public: enum class ToolType{hammer,spanner,cutter};/*step 1. better placed*/

	private:FruitType m_type {};
		Fruit::ToolType m_tool{};
		int m_percentageEaten{0};
	public:Fruit(FruitType type):m_type(type){};
	       FruitType getType()const{return m_type;}

	       Fruit::ToolType getToolType()const{return m_tool;}
	       int getpercentageEaten()const{return m_percentageEaten;}



};
int main(){
	Fruit apple{Fruit/*Type*/::apple};
	Fruit::ToolType hammer{Fruit::ToolType::hammer};
	if(apple.getType()==Fruit/*Type*/::apple)std::cout<< "I am an apple " << '\n';else std::cout << "I am NOT an apple " << '\n';

//	if(hammer.getToolType()==Fruit/*Type*/::ToolType::hammer)std::cout<< "I am a hammer " << '\n';else std::cout << "I am NOT a hammer " << '\n';
	return 0;
}
