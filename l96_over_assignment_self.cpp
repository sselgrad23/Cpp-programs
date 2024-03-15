#include<iostream>
class MyString
{
	private:char* m_data{};
		int m_length{};
	public:MyString(const char* data=nullptr, int length=0):m_length{length}
	       {
		       if(length){m_data=new char[length];for(int i{0};i<length;++i){m_data[i]=data[i];}}
	       }
		       ~MyString(){delete[] m_data;}
		       MyString& operator=(const MyString& str);
		       friend std::ostream& operator<< (std::ostream& out,const MyString& s);

};
std::ostream& operator<< (std::ostream& out,const MyString& s){out << s.m_data;return out;}
MyString& MyString::operator=(const MyString& str)
{

//IMPORTANT TO AVOID dangling pointer detect selfassignmet:(selfassignment guard
if(this==&str)return *this;//return alredy here, if address of implicit object is the same as of the object beeing passed
if (m_data)delete[] m_data;/*delete if something is in m_data*/
m_length=str.m_length;
m_data = new char[str.m_length];
for(int i{0};i<str.m_length;++i)m_data[i]=str.m_data[i];
return *this;

}
int main(){
MyString alex("Alex",5);/*null terminated therefore not 4*/
MyString employee;/*implicit object*/
employee=alex;
	std::cout <<employee<<'\n';
alex=alex;
	std::cout <<alex<<'\n';
MyString s{s};/*will compile but when run will abort invalide free*/

	return 0;
}
