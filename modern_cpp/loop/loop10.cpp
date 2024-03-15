#include<iostream>
#include<iterator>
#include<cstddef>
//class Doub{
//    int m_a;
//    int m_b;
//    public:
//        Doub():m_a{0},m_b{0}{}
//		friend std::ostream& operator<<(std::ostream& out,const Doub& d);
//};
//std::ostream& operator<<(std::ostream& out,const Doub& d){ out <<"a: " <<d.m_a << " b: "<<d.m_b; return out;}


template<size_t const s>
class XX{
	private:
        struct Doub{
            int m_a;
            int m_b;
            friend std::ostream& operator<<(std::ostream& out,const Doub& d){ out <<"a: " <<d.m_a << " b: "<<d.m_b; return out;}
        };
        Doub m_data[s];
	public:
		struct Iterator{
			using iterator_category = std::forward_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = Doub;
			using pointer           = Doub*;
			using reference         = Doub&;
			Iterator(pointer ptr):m_ptr(ptr){}
			reference operator*()const{return *m_ptr;}
			pointer   operator->(){return m_ptr;}
			Iterator& operator++(){m_ptr++; return *this;}
			Iterator operator++(int){Iterator tmp=*this; ++(*this);return tmp;}
			friend bool operator==(const Iterator&a, const Iterator& b){return a.m_ptr==b.m_ptr;};
			friend bool operator!=(const Iterator&a, const Iterator& b){return a.m_ptr!=b.m_ptr;};
		private:
			pointer m_ptr;
		};
//    XX(int s):m_s{s}{}
    Iterator begin(){return Iterator(&m_data[0]);}
    Iterator end(){return Iterator(&m_data[s]);}
    void set(int a,int b,int index){m_data[index].m_a=a;m_data[index].m_b=b;}
//    void fill(int a,int b,int index){m_data[index].m_a=a;m_data[index].m_b=b;}
    
};
class Integers{
	public:
		struct Iterator{
			using iterator_category = std::forward_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = int;
			using pointer           = int*;
			using reference         = int&;
			Iterator(pointer ptr):m_ptr(ptr){}
			reference operator*()const{return *m_ptr;}
			pointer   operator->(){return m_ptr;}
			Iterator& operator++(){m_ptr++; return *this;}
			Iterator operator++(int){Iterator tmp=*this; ++(*this);return tmp;}
			friend bool operator==(const Iterator&a, const Iterator& b){return a.m_ptr==b.m_ptr;};
			friend bool operator!=(const Iterator&a, const Iterator& b){return a.m_ptr!=b.m_ptr;};
		private:
			pointer m_ptr;
		};
Iterator begin(){return Iterator(&m_data[0]);}
Iterator end(){return Iterator(&m_data[5]);}
	private:
	int m_data[5];
	};

int main(){
//Doub dd{23,45};
//std::cout<<dd<<'\n';

	Integers integers;
	std::fill(integers.begin(),integers.end(),3);
	std::fill(integers.begin(),integers.end(),3);
	std::fill(integers.begin(),integers.end(),3);
	std::fill(integers.begin(),integers.end(),3);
	for(auto i: integers)std::cout<< i<<' ';
	std::cout<<'\n';
	XX <6> xx;
    xx.set(8,9,0);
    xx.set(1,3,1);
    xx.set(2,4,2);
    xx.set(1,1,3);
    xx.set(8,7,4);


//	std::fill(xx.begin(),xx.end(),(3,7));
	std::fill(integers.begin(),integers.end(),(7));
	for(auto i: integers)std::cout<< i<<' ';
	std::cout<<'\n';
	for(auto i: xx)std::cout<< i<<'\n';
	std::cout<<*std::begin(xx);
	std::cout<<*std::end(xx);	
	return 0;
}
