#include<iostream>
#include<string>
class Car
{
	private:std::string m_name;
		int m_id;
	public:Car(const std::string& name, int id):m_name{name},m_id{id}{}
	       const std::string& getName()const{return m_name;}
	       int getId()const{return m_id;}
};
class CarLot
{
	private:static Car s_carLot[4];
	public:CarLot()=delete;
	       static Car* getCar(int id)
	       {
		       for(int count{0};count<4;++count){if(s_carLot[count].getId()==id){return& (s_carLot[count]);}}
	       		return nullptr;
	       }
	       
};
Car CarLot::s_carLot[4]{ {"Prius",4},{"Corolla",6},{"Accord",9},{"Civis",5} };
Car c5{"Audi",0};

class Driver
{
	private:std::string m_name;
		int m_carId;
	public:Driver(const std::string& name,int id):m_name{name},m_carId{id}{}
	       const std::string& getName()const {return m_name;}
	      int getCarId()const{return m_carId;} 
};
int main(){
std::cout << "Bad example only for learning with pointers it would be quicker and had no rearch loop\n";

	std::string n{"Bill"};
	int id{9};
	Driver d{n,id};
	Car* car{CarLot::getCar(d.getCarId()) };
	if(car)	std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else std::cout << d.getName() << " could not find his car\n";

	return 0;
}
