#include<iostream>
#include<string>
class Person
{
	public:
	std::string m_name{};
	int m_age{};
	Person(const std::string& name="",int age=0):m_name{name},m_age{age}{}
	const std::string& getName() const {return m_name;}
	int getAge() const {return m_age;}
};
class Player : public Person
{
	public:double m_battingAv{};
	public:	int m_homeRuns{};
	       Player(double battingAv=0.0,int homeRuns=0):m_battingAv{battingAv},m_homeRuns{homeRuns}{};
	       void get_Name_homeRuns_battingAv() const {std::cout<<m_name<<": "<< m_homeRuns << ' ' << m_battingAv <<'\n';}
};

int main(){
Person joe{};
joe.m_name="Joe";
std::cout << joe.m_name << ' ' <<joe.m_age <<'\n';
Player bill{12.6,100};
bill.m_name="Bill ";
bill.m_age=23;
std::cout << bill.m_name << ' ' <<bill.m_age << '\n';
bill.get_Name_homeRuns_battingAv() ;
	return 0;
}
