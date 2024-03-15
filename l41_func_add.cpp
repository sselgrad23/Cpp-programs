//sudo add-apt-repository -y ppa:ubuntu-toochain-r/test
//sudo apt install -y g++-11
//g++-11 -Wall -o p l41_func_add.cpp -std=c++2atd

#include<iostream>

void mk12(int* ptr){*ptr=6;std::cout << *ptr  <<  " pointer pointing at address: " << ptr << " and address of pointer: " << &ptr << '\n';}/*pointer gets copied*/
void mk_ptr_NULL(int*& ptr){ptr=nullptr;} 
void prEl_NO_change(const int* ptr,int l){/*use const*/
        if (!ptr)return;
	for (int i{0};i<l;++i)std::cout<<ptr[i]<<' '; 
	std::cout<<'\n';
}
void prEl_with_change(int* ptr,int l){
        if (!ptr)return;
	ptr[2]=0;
	for (int i{0};i<l;++i)std::cout<<ptr[i]<<' '; 
	std::cout<<'\n';
}
int main()
{
 auto i{10};
 
 std::cout << i  <<  " address of i: " << &i << '\n';
 mk12(&i);
 std::cout << i  << '\n';
 auto ptr{&i};
 std::cout << " address of ptr: " << &ptr << '\n';
 mk12(ptr);
 mk_ptr_NULL(ptr);
 if(ptr==nullptr) std::cout << " ptr is pointing to: null \n";
 int a[6]{1,2,3,4,5,6};
 prEl_NO_change(a,6);/*array decays to pointer to first element */
 prEl_with_change(a,6);
 return 0;
} 
