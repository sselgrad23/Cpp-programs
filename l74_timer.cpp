#include<iostream>
#include<chrono>/*std::chrono*/
#include<cstddef>/*std::size_t*/
#include<array>
#include<numeric>/*std::iota*/
const int g_arrayElements{10000};
class Timer
{
	private: using clock_type = std::chrono::steady_clock;
		 using second_type=std::chrono::duration<double,std::ratio<1> >;
		 std::chrono::time_point<clock_type>m_beg{clock_type::now()};/*declaration and instanziation of m_beg*/
	public:void reset(){m_beg=clock_type::now();};
	       double elapsed()const{return std::chrono::duration_cast<second_type>(clock_type::now()-m_beg).count();}

};
int main(){
	std::array<int, g_arrayElements>array;
	std::iota(array.rbegin(),array.rend(),1);
	Timer t;
	std::sort(array.begin(),array.end());
	std::cout << "time taken " << t.elapsed() << "seconds" << '\n';
	return 0;
}
