#include<iostream>
#include<plog/Log.h>
#include<plog/Initializer/RollingFileInitializer.h>
int getUserInput()
{
 PLOGD << "getUserInput() called";
 std::cout << "Enter a number: ";
 int x{};
 std::cin >> x;
 return x;
}

int main()
{
 plog::init(plog::debug,"Logfile.txt");
 PLOG << "main() called";
 int x{ getUserInput() };
 std::cout<< "you entere: " << x;
 return 0;
}
