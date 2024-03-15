#include<iostream>
#include<memory>

std::unique_ptr<int*> pass_through(std::unique_ptr<int*> p){return p;}


struct arr{int a[10];};
int main()
{
	int* ptrA=new int[5];
	int* ptrB{nullptr};
	ptrB=ptrA;
	ptrB[1]=99;
	ptrA[1]=88;/*access to 5 int arr over two pointer can causes problems*/
	std::cout<<ptrA[1]<<'\n';
	std::cout<<ptrB[1]<<'\n';
	ptrB=std::move(ptrA);/*ptrB and ptrA have access*/
	if(ptrA==nullptr)std::cout<<"ptrA is pointing at "<<ptrA<<'\n';
	ptrB[2]=321;
	ptrA[2]=123;
	std::cout<<ptrB[2]<<'\n';

	std::unique_ptr<int*> p = std::make_unique<int*>(ptrA);

	std::cout<<*(*p+1)<<'\n';

//	std::unique_ptr<int*> q = std::make_unique<int*>(ptrA);
	std::unique_ptr<int*> q = std::move(p);/*delete for you p*/

	if(p==nullptr)std::cout<<"after std::move(p) p is pointing at "<<p<<'\n';

//	std::cout<<*(*p+1)<<'\n';/* Segmentation fault*/
	std::cout<<*(*q+1)<<'\n';

	return 0;
}
