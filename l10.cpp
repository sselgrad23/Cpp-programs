#include<iostream>
void print()
{
 std::cout << " MAIN\n";
}


namespace foo{
 void printFOO()
 {
  std::cout << "foo\n";
 }
 void printHELLO()
 {
  ::print();

  printFOO();
 }
}




int main()
{
foo::printHELLO();

return 0;
}
