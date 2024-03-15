#include<iostream>
auto sumTo(int sumto)
{
//	std::cout << "sunTo("<<sumto<<") called,";
	if(sumto<=0)
	{
		std::cout <<sumto<<"is <=0 ";
		return 0;
	}
	else if (sumto==1)
	{

		return 1;
	}
	else 
	{
		int ret{sumTo(sumto - 1) + sumto};
		std::cout  << "sunTo("<<sumto<<") called,"<<"so we return sumTo("<< sumto -1 <<") + "<< sumto <<'\n';
		return ret;
	}	
}
int main()
{

 std::cout << sumTo(5)  << '\n';

 return 0;
} 
