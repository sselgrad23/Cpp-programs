#include<iostream>
template<typename T>
T average(const T* myArray,int numValues){T sum{0};for (int i{0};i<numValues;++i)sum+=myArray[i];
	sum/=numValues;return sum;}
class Cents
{
	private:int m_cents{};
	public:Cents(int cents):m_cents(cents){}
	       friend bool operator<(const Cents& c1, const Cents& c2){return(c1.m_cents<c2.m_cents);}
	       friend std::ostream& operator<<(std::ostream& ostr,const Cents& c){ostr << c.m_cents; return ostr;}
		Cents& operator+=(const Cents& cents){m_cents+=cents.m_cents; return* this;}
		Cents& operator/=(int x){m_cents/=x; return *this;}
};
template<typename T>
const T& max(const T& x,const T& y){return(x<y)?y:x;/*you need to overload operator<*/}
int main(){
Cents nickle{5};
Cents dime{10};
Cents bigger=max(nickle,dime);
std::cout << bigger << "is bigger\n";
int intArray[]{5,6,7,8,9};
std::cout<< average(intArray,5)<< '\n';
std::cout <<"operators to overload: << += /=\n";
Cents centsArray[]{Cents{5},Cents{10},Cents{15},Cents{3}};
std::cout << average(centsArray,4)<<'\n';
	return 0;
}
