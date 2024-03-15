#include<iostream>
class Simple
{
	private:int m_id;
		int *iptr{&m_id};
		int id;
	public:Simple(int id):m_id{id}{this->id=id;}/*same id identifier this makes sense but dont use it better m_*/
	       void showAddress(){ std::cout << "address of class Simple " << this << " and m_id " << iptr << '\n';}
	       void setID(int id){m_id=id;}/*this is converted by the compiler tp void setID(*Simple const this,int id){this->m_id=id;}*/
	       int getID(){return m_id;}
};
int main(){
Simple s{1};
s.setID(2);/*this converted by the compiler to setID(&s,2) */
std::cout << s.getID() << '\n';
s.showAddress();

Simple p{1};
p.setID(2);/*this converted by the compiler to setID(&s,2) */
std::cout << p.getID() << '\n';
p.showAddress();



return 0;
}
