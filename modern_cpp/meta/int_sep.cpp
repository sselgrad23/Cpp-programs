#include<iostream>
#include<type_traits>
#include<utility>
template<typename T, T... ints>
void print_sequence(std::integer_sequence<T,ints...>int_seq){
    if(std::is_same<int,T>::value){ 
        int s{0};
        ((s+=ints), ...);
        ((std::cout<<ints<<' '), ...);
        std::cout<<s<<'\n';
    }
    if(std::is_same<double,T>::value){
        double s{0.0};
        ((s+=ints), ...);
        ((std::cout<<ints<<' '), ...);
        std::cout<<s<<'\n';
    }
}


int main()
{
print_sequence(std::integer_sequence<int,1,2,3,4>{});
print_sequence(std::integer_sequence<double ,1.1,2.1,3.1,4.1>{});
	return 0;

}
