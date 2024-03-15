#include<iostream>
#include<memory>/*for unique_ptr*/

struct B{virtual ~B()=default;virtual void bar(){std::cout<<"B::bar()\n";}};
struct D:B{
	D(){std::cout<<"D::D()\n";}
	~D(){std::cout<<"D::~D()\n";}
	void bar(){std::cout<<"D::bar()\n";}
};
std::unique_ptr<D> pass_through(std::unique_ptr<D> p){
p->bar();
return p;
}	
int main(){
	std::unique_ptr<D> p = std::make_unique<D>();

	p->bar();
	std::unique_ptr<D> q = pass_through(std::move(p));
/*	p->bar(); Segmentation fault contense of p moved to q*/
	if(p==nullptr)std::cout<<p<<" = nullptr"<<'\n';
	q->bar();

	return 0;
}
