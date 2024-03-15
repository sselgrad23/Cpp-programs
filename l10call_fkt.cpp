//g++-11 -Wall -o p1 l10call_fkt.cpp
#include <iostream>
auto func(int x, int y)
{
    return x+y;
}
auto func_ref(int& x, int& y)
{
    return x+y;
}
void fkt_ref_addresse (int* x,int* y,int* res){*res=*x+*y;}/*argumemt ist pointer nicht mehr value*/
int main()
{
    auto result{0};


    result = func(10,20);/*call by value*/
    std::cout<<"result = "<<result<<'\n';
    auto a{30},b{40};
    result = func_ref(a,b);/*call by reference*/
    std::cout<<"result = "<<result<<'\n';
    auto res{0};
    int* ptr_to_a{&a},* ptr_to_b{&b},* ptr_to_res{&res};
    fkt_ref_addresse(ptr_to_a,ptr_to_b,ptr_to_res);
    std::cout<<"a = "<<*ptr_to_a<<"b = "<<*ptr_to_b<<"res = "<<*ptr_to_res<<'\n';
    std::cout<<"res = "<<res<<'\n';

    int *ptr_to_int{nullptr};
    ptr_to_int=&result;/*Pointer auf ind durch:  =&*/
    std::cout<<"result = "<<*ptr_to_int<<'\n';

    int (*ptrFunc)(int,int){nullptr};    
    std::cout<<"ptrFunc=func: ptrFunc assozieiert mit func. =& ist nicht noetig\n";
    ptrFunc=func;/* pointer to function. "=&" ist nicht noetig */
    
    std::cout<<"erste Moeglichkeit: result = (*ptrFunc)(30,40). *ptrFunc ist Speicherzelle mit Adresse in der Zelle ptrFunc \n";
    result = (*ptrFunc)(30,40);/*Aufruf von func ueber POINTER*/
    std::cout<<"result = "<<*ptr_to_int<<'\n';
    
    std::cout<<"zweie Moeglichkeit: result = ptrFunc(30,40)\n";
    result = ptrFunc(40,50);/*Aufruf von func ueber POINTER*/
    std::cout<<"result = "<<*ptr_to_int<<'\n';;

 

    
    return 0;
}
