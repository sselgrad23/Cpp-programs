#include<iostream>

int main(){
	std::cout << "to qualify as a composition, an object and a member (part) must have the following relationship:\n";
	std::cout << "1.member must be declared as part of object.\n";
	std::cout << "2.member is only declared in its object at a time.\n";
	std::cout << "3.member has its existence managned by its object.\n";
	std::cout << "4.member does not know about the existence of the object=unidirectoral relationship\n";
	std::cout << "to qualify as a aggregation point 2 and 3 change the part can belong to more than one object and\n";
        std::cout << "it does not have its existence managed by the object.\n"
	std::cout << "composition human body agrregation is not responsible for creating parts. nor destroying.\n";
	std::cout << "part can live on after aggregation is destroyed. Person Homeadress.\n";

	return 0;
}
