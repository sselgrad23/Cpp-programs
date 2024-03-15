#include<iostream>
#include<cassert>
#include<cstring>
class MyString
{
	private:int m_length{};/*same folge as in initilizer*/
		char* m_data{};

	public:MyString(const char* source="")
	       {
		       std::cout << "MyString\n";
		       assert(source);
		       m_length=std::strlen(source+1);/*null terminated*/
		       m_data=new char [m_length];
		       for(int i{0};i<m_length;++i)m_data[i]=source[i];
	       }
	       MyString(const MyString& source):m_length(source.m_length),m_data(source.m_data){}/*the default copy constructor would look*/
	       /*like this, it would not copy the letters nor give memory*/
		~MyString(){std::cout << "~MyString\n";   delete m_data;}
		char* getString(){return m_data;}
		int getLength(){return m_length;}	

};
int main(){

MyString hello{"hello world"};
{
MyString copy{hello};/*will compile but abort because try to delete memory which does not exist (second delete)DANGELING pointer in first object */
}
//will not compile under c20!
//std::cout << hello.getString <<'\n';
std::cout<<"first look whether there is a standat library for the type for string the is one with a function for copy constructor\n";
std::cout<<"if not then write one, always try first to take the work of others!\n";
return 0;
}
