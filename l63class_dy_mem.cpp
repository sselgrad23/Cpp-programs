// g++-11 -Wall -o p l01.cpp -st=c++11
#include<iostream>

template<typename T>void print( T a){std::cout<< a<<'\n';}
template<typename T>T bigger( T a,T b){return(a>b?a:b);}
template<typename T>T smaller( T a,T b){return(a<b?a:b);}


//template <typename T> 
//class Paar{
//private:m_a{};
//m_b{};
//public:Paar(T a,T b)
//}







template <typename T> 
class Memory_Manage{
private:    int m_num_of_units{};
            int m_cell_nr{};
            T m_containce;
            T* m_ptr{};
public:     Memory_Manage():m_num_of_units{1}{m_ptr=new T [m_num_of_units];} 
            Memory_Manage(int num_of_units):m_num_of_units{num_of_units}{m_ptr=new T [m_num_of_units];}
            ~Memory_Manage(){delete [] m_ptr;}

            void set_Value(int cell_nr, T containce){m_ptr[cell_nr]=containce;}
            T return_Value(int cell_nr){return m_ptr[cell_nr];}
            T* return_pointer(){return m_ptr;}
};



int main(/*arguments of function main*/){
print(1);
print(1.2);
print("hallo");
print(bigger(9,99));
print(smaller(9.1,99.9));






Memory_Manage<int> nn;
std::cout<<nn.return_Value(0)<<'\n';

Memory_Manage<int> mm(9);
mm.set_Value(4,17);
std::cout<<mm.return_Value(4)<<'\n';
mm.return_pointer()[4]=12;
std::cout<<mm.return_Value(4)<<'\n';




return 0;
}
