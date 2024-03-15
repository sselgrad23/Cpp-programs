#include<iostream>
#include<string>
class Course
{
	private:std::string m_name;
		const Course* m_prerequisite;
	public:Course(const std::string& name,const Course* prerequisite=nullptr)
	       :m_name{name},m_prerequisite{prerequisite}{}
};



int main(){
	std::cout << "reflexiv association means relalations with same type of object.\n";
Course c1;
Course c2(c1);/*not working*/

	return 0;
}
