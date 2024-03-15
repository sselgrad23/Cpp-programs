#include<iostream>

void print_1();/*forward declaration*/
void print_2();/*forward declaration but no body later declared*/

int add(int x, int y);/*forward declaration but no body later declared*/

int main()
{
print_1();

//print_2(); will compile because no call to function print02() otherwise Linker error
//linker needes a definition for every identifier
return 0;
}



void print_1()/*definition implemets or instanciates the forward declaration similar to int i; i=5;*/
{
std::cout<<"hal 1 \n";
}
int add(int x, int y)/*implements function add()*/
{
 int z{x+y};/*instantiates variable z*/
 return z;
}


