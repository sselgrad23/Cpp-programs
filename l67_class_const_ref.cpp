#include<iostream>

static int counter{0};/*you don't need static because of default*/
class Date
{
	private: int m_year{};int m_month{}; int m_day{};
	public:Date(int year,int month,int day){ setDate(year,month,day);}


	       void setDate(int year,int month,int day){ m_year=year;m_month=month,m_day=day;}

	       int getYear(){return m_year;}/*NO const NEEDE becaus of printDate(Date&*/
	       int getMonth(){return m_month;}
	       int getDay(){return m_day;}
//	       int (*fctptr)(){};
//	       fctptr = & getDay;
	       void printDate(Date& date){std::cout << date.getYear() << ' ' << date.getMonth() << ' ' << date.getDay() << '\n';}




// overload functions is working becaus const isqualifier is considered part of the function signatur, so they ar considered as
// DIFFRENT funktions
	       int getYear()const{return m_year;}/*const NEEDE becaus of printDate(const*/
	       int getMonth()const{return m_month;}/*if a function ist declared const all members are treated as const*/
	       int getDay()const{std::cout<<++counter<< ' ';return m_day;}/*so return is also a const*/
	       int count()const{std::cout<<++counter<< ' ';return counter;}/*so return is also a const???? No here*/
void printDate2(const Date& date){std::cout << date.getYear() << ' ' << date.getMonth() << ' ' << date.getDay() << date.count() << '\n';}


};
int main(){

Date d1(1999,12,5);
d1.printDate(d1);
d1.printDate2(d1);
d1.printDate2(d1);
d1.printDate2(d1);
	return 0;
}
