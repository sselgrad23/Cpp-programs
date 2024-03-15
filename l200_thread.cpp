#include<iostream>
#include<thread>
int arr[30];

void fkt(int start,int stop,int cont){for(auto i{start};i<stop;++i)arr[i]=cont;}

//void fkt(int n){arr[n]=2;};
int main(){
	std::thread t1(fkt,0,10,100);
	std::thread t2(fkt,10,20,200);
	std::thread t3(fkt,20,30,300);
	t1.join();
	t2.join();
	t3.join();
	for(auto i{0};i<30;++i)std::cout<< arr[i] <<'\n';
	return 0;
}
