#include<iostream>
#include<string>
auto prtstrg(const std::string& str){return [&](){std::cout << str << '\n';};}
int main()
{
//DON'T DO THIS:
auto strng{prtstrg("HALLO")};/*the lambda captures the reference to string "HALLO", but it dies at end of prtstrg*/
strng();/*has now a dangling refernce can caus trouble*/

 return 0;
} 
