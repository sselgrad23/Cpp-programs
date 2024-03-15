#include<iostream>
#include<cassert>
class InitList{
//	private:int m_list[10]{};
	private:int m_list[10]{0,1,2,3,4,5,6,7,8,9};
	public:void setItem(int index, int v){m_list[index]=v;}
	       int getItem(int index)const{return m_list[index];}
	       int* getList(){return m_list;}
	       //better overload operator[]
	       int& operator[](int index);/*You have written class InitList so you have acces to left side-> member function*/
	       /*it must return the addres of an int or else list[3] would be an integer then 5=9 compiler error*/
	       //for const list:
	       const int& operator[](int index)const;
};
int& InitList::operator[](int index){assert(index>=0&&index<static_cast<int>(std::size(m_list)));return m_list[index];}
const int& InitList::operator[](int index)const{assert(index>=0&&index<static_cast<int>(std::size(m_list))); return m_list[index];}
class Stupid{
	public:void operator[](const std::string& index);
};
void Stupid::operator[](const std::string& index){std::cout << index;}
int main(){

	Stupid stupid{};
	stupid["Hello World"];




	InitList list{};/*c23 multidimensional Arrays possible*/
	list.setItem(2,3);/*confusing what is 2 and what is 3*/
	list.getList()[2]=4;/*syntacticaly odd*/
//better:
	list[3]=27;/*[] higher precendence than = ,so list[3] is evaluated first. it calls function operator[] whitch returs a refernce*/
	           /*list.m_list[3] so: list.m_list[3]=27*/
		   /*l-side assignment= must have a l-value whitch means an address in memory, here a reference so compiler gives no warning*/
	std::cout << list[3] <<'\n';
	const InitList constlist{};
	//constlist[2]=1; not working because of const
	std::cout << constlist[2] <<'\n';
	InitList* list_new(new InitList{});/*size given 10*/
//	list_new[2]=3;WRONG
	(*list_new)[2]=3;
	delete list_new;


	list[55]=10;
	return 0;
}
