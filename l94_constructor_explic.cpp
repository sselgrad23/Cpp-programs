#include<iostream>
#include<string>
class MyString{
	private: std::string m_string;
	public:explicit MyString(int x){m_string.resize(x);}
	       MyString(const char* string){m_string = string;}
		friend std::ostream& operator<<(std::ostream& out,const MyString& s);
};

std::ostream& operator<<(std::ostream& out,const MyString& s){out << s.m_string;return out;}
void printString(const std::ostream& s){std::cout <<s;}
int main(){
//MyString mine='x'; NOT compile because of exlicit
//printString('x');
//BUT::
	printString( static_cast<MyString>(5));
	return 0;
}
