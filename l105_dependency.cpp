#include<iostream>
class Point
{
	private:double m_x,m_y,m_z;
	public:Point(double x,double y,double z):m_x{x},m_y{y},m_z{z}{}
	       friend std::ostream& operator<<(std::ostream& out,const Point point)
	       { 
		       out << "Point( "<<point.m_x<<" ,"<< point.m_y<<" ,"<<point.m_z<< ")";
		       return out;
	       }

};
int main(){
Point point1(2.9,3.3,7.8);
std::cout << point1 <<'\n';
	return 0;
}
