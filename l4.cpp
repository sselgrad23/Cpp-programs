// preprocessor before compiler. the preprocessor is a programm that make an translation of cpp file
//it manipulates the text in each cpp file. A translation unit is the result 
#include<iostream>/*# = preprocessor directive it replaces this line with that what is in iostream*/
#include"inc.h"

#define PI 3.14/* PI will be repaced with 3.14*/
#define k 0.9
#define name_of_program "l4"

void fkt()
{
#define wert 321
}

void doSomething();

int main()
{
 #ifdef name_of_program

 std::cout << cout() << " " << cin() << " " << PI << name_of_program <<'\n';
 #endif


 //better c++ style
 #if defined (k)
 std::cout << " " << k << '\n';
 #endif

 #if !defined (q)
 #define q 17.2
 std::cout << " " << q << '\n';
 #endif

 #if 0/*get not compiled*/
 std::cout << " " << wert << '\n';
 #endif

 #if defined (wert) /*gets compiled preprocessor don't care where wert is defined*/
 std::cout << " " << wert << '\n';
 #endif


 #define PRINT/*has only impact on this file not on fkt.cpp file therefor Not Printing in doSomething */

 doSomething();

 //header file should not contain functions and variable definitions exept symbolic constance like:
 //const,constexp, symbolic constants 

 return 0;
}
