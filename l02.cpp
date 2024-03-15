#include<iostream>

// a function is areusable sequence of statements designed to do a particulare job

void doPrint()/*callee or called function. void is return type, doPrint isidentifier */
{/*{....} body of function*/
std::cout<<"begin doPrint function \n";
std::cout<<"in doPrint function \n";
std::cout<<"end doPrint function \n";
// a function can not contain an other function
// void nested_function()
// {
// std::cout<<"this is not allowed \n";
// {
}/*no semicolon, because it is not a statement but a declaration*/

// void is return value

int read_input()
{
 int x;
 std::cin>>x;
 return x;
}
void doPrint2(int i)
{
 std::cout << i<< '\n';
// return void; wrong
}






int main()
{
 std::cout<<"begin main function \n";
 std::cout<<"main calls doPrint function \n";
 //interupting the main function cpu remembers where it has interupted main
 doPrint();/*this is a function call. The function initiating the call is the caller here main*/
 //continue main
 std::cout<<"main continues after calls doPrint function \n";

 std::cout<<"main calls read function \n";
 read_input();



 std::cout<<"before return 0 of  function \n";



 //Abreviation DRY=Don't Repeat Yourself::
 //bad:
 int k{};
 std::cout << "enter int\n";
 k=read_input();
 int l{};
 std::cout << "enter int\n";
 l=read_input();
 std::cout << k << "+" << l << "=" << k+l << '\n';
 //better:
 int m{read_input()};
 int n{read_input()};
 std::cout << m << "+" << n << "=" << k+l << '\n';
 doPrint2(read_input() + read_input());/*argument ad_input() + read_input() is expression two functions calls, but*/
 /*we don't know witch read_input is called first*/
 /*if this matters better do so:*/
 doPrint2(m+n);
 
 doPrint2(9);/*call initialisats x of doPrint function by copy 9 int x */

 return 0;/*return 0 to the calling program here console*/
 /*return value from main is called status code or exit code*/
 /*there are three exit codes 0 , EXIT_SUCCESS or EXIT_FAILURE in #include<cstdlib>*/
 std::cout<<"after return 0 of function this will not be reached\n";
}
