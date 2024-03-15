#include<iostream>
#include<cstddef>/*size_t*/
template<typename T,size_t const Size>
class Dummy_array
{
	T data[Size]={};
	public:
	T const& GetAt(size_t const index) const
	{
		if(index<Size)return data[index];
//		throw std::out_of_range("index out of range");
	}
	void SetAt(size_t const index,T const&value)
	{
		if(index<Size)data[index]=value;
	}
	size_t GetSize()const{return Size;}
};
template<typename T,typename C,size_t const Size>
class Dummy_array_iterator_type
{
	private:
		size_t index;
		C& collection;
	public:
		Dummy_array_iterator_type(C& collection,size_t const index):index(index),collection(collection){}
		bool operator !=(Dummy_array_iterator_type const& other){return index!=other.index;}

		T const & operator*()const{return collection.GetAt(index);}
		Dummy_array_iterator_type& operator++(){++index;return *this;}
		Dummy_array_iterator_type& operator++(int)
		{
			auto temp=*this;
			++*temp;
			return temp;
		}
};

template<typename T,size_t const Size>
using Dummy_array_iterator=Dummy_array_iterator_type<T,Dummy_array<T,Size>,Size>;

template<typename T,size_t const Size>
using Dummy_array_const_iterator=Dummy_array_iterator_type<T,Dummy_array<T,Size>const,Size>;



template<typename T,size_t const Size>
inline Dummy_array_iterator<T,Size>begin(Dummy_array<T,Size>&collection){return Dummy_array<T,Size>(collection,0);}
template<typename T,size_t const Size>
inline Dummy_array_iterator<T,Size>end(Dummy_array<T,Size>&collection){return Dummy_array<T,Size>(collection,collection.GetSize());}

template<typename T,size_t const Size>
inline Dummy_array_const_iterator<T,Size>begin(Dummy_array<T,Size>const &collection){return Dummy_array<T,Size>(collection,0);}
template<typename T,size_t const Size>
inline Dummy_array_const_iterator<T,Size>end(Dummy_array<T,Size>const &collection){return Dummy_array<T,Size>(collection,collection.GetSize());}





template<typename T,size_t const Size>
void print_Dummy_array(Dummy_array<T,Size>const & arr){

for(auto&& e:arr){std::cout<<e<<'\n';}
};


int main()
{
	Dummy_array<int,3>arr;
	arr.SetAt(0,44);
	arr.SetAt(1,15);
	arr.SetAt(2,22);
//	auto dIter=std::begin(arr);
//print_Dummy_array(Dummy_array<int,3>arr);

for(auto&& e:arr){std::cout<<e<<'\n';}



	return 0;
}
