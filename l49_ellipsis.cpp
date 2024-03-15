#include<iostream>
#include<cstdarg>/*elipsis*/
double findAverage(int count, ...)
{
	double sum{0};
	va_list list;/*create a list*/
	va_start(list,count);
	for(int arg{0};arg<count;++arg){std::cout << va_arg(list,int)<< '\n';sum +=va_arg(list,int);}
	va_end(list);/*clean up list*/
	return sum/count;
}

int main()
{

 std::cout << findAverage(4, 4,5,2,1)  << '\n';

 std::cout << findAverage(7, 3,4,5,2,1,23,45)  << '\n';
 return 0;
} 
