#include<iostream>
int add(int x,int y){int res{x+y};return res;}
int addAnomym(int x, int y){return x+y;}/*x+y is created as anonymous object to hold and return result of x+y HERE return*/
void print(int i){std::cout << i <<'\n';}


class Cents{
	private:int m_cents{};
	public:Cents(int cents){m_cents=cents;}
	       int getCents()const {return m_cents;}/*Don't forget const */
	       int non_const_getCents() {return m_cents;}
};
void print(const Cents& cents){
	std::cout<< cents.getCents() <<'\n';
}

void non_const_print(Cents& cents){
	std::cout<< cents.non_const_getCents() <<'\n';
}






int main(){
        print(9-3);/*9-3 is anonymous object*/
        //NORMAL
	Cents ct{78};
	print(ct);
	non_const_print(ct);
	print(Cents{7});/*Cent{7} anonymous class object it was not declared Cents c{7} print(c)*/
	int i{99};

	print(Cents{i});/*Cent{7} anonymous class object it was not declared Cents c{7} print(c)*/
//	non_const_print(Cents{8}); ERROR cannot bind a non const(Cent{8}is const to 
	return 0;
}
