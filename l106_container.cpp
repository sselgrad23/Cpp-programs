#include<iostream>
#include"l106_container.h"

int main(){
l106_container array(10);
for(int i{0};i<10;++i)array[i]=i+1;
array.resize(8);
array.insertBefore(20,5);
array.remove(3);
array.insertAtEnd(30);
array.insertAtBeginning(40);
for(int i{0};i<array.getLength();++i)std::cout<< array[i] << ' ';
std::cout <<'\n';

l106_container arr{5,3,5,1,9};
for(int i{0};i<arr.getLength();++i)std::cout<< arr[i] << ' ';
std::cout <<'\n';
arr={2,2,2,2,2,2,2,2,2,2,2};
for(int i{0};i<arr.getLength();++i)std::cout<< arr[i] << ' ';
std::cout <<'\n';


	return 0;
}
