// g++ -Wall -o p l01.cpp -st=c++11
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int five ()
{
 return 5;
}




int main(/*arguments of function main*/){
int x;/*'int x' is a declaration statemant. This special kind of declaration statement is called a Definition*/
/* after every statement is a semicolon*/
/*In c++ direct Access to memory is not allowed. Access is indirectly over an object*/
/*An object is a region in the RAM or storage, which holds a value and other assoziated properties*/
/*an object can have a name like here 'int' or has no name aanonymous objects*/
/*a named object is called variable*/
/*its name is its identifier, here 'x'. behind x is an address to reach the object in storage*/
/*in c++ a function is not an object but in general programming*/
/*this declaration statement makes the compiler prepare that we call a variabe x and may want later */
/*memory cell to store a value in it. whenever the compiler sees x it knows that we are referencing */
/*this variable(named object)*/
/*after compiling the program can run. when it is run the variable(objec)t will be instantiated*/
/*Instantiated means the object gets created. The object gets memory and assigned an address to it */
/*an instantiated Object is also called an Instance*/
/*to create an object means: the operating system gives an address to the begin of a part of the memory*/
/*how big this part of memory is, is defined by the type of the object*/
/*if x is instantiated at memory allocation 100010100 always the computer will go to this adress to*/
/*read or write to this address when the is x*/
/*the type 'int' tells the compiler what type of value is later stored in the variable. How many Ram is needed*/
/*to put the value in. For an int it is 16 bit bits*/
x=5;/*this is a copy assignment*/
/*= is an assignment operator.It copies the value 5(left) into the object x (memory cells)(right) */

/*this is called an assignment step one: definition int x;    than  assignment x=5;*/

/*you can do this in one line*/
int y=5;/*this it is called initialisation  here copy initialisation from c*/
/*or*/
int z(5);/*this it is called direct initialisation*/
/*or*/
int a{5};/*this it is called a direct brace initialisation*/
/*or*/
int b={5};/*this it is called a copy brace initialisation*/
/*or*/
int c{};/*this it is also an initialisation set to 0*/
/*<< is called insert operator*/
cout << x << y << z<< endl;/*two flushes one from cout and one from endl*/
cout << a << b << c <<'\n';/*this is better: only one flush from cout*/
std::cin >> c;
cout << c << '\n';

// Difference:
//initialisation:The object is given n known valu at the point of definition int x =10;
//Assignment:The object is given a value beyond the point of definition int v; v=10;
//Uninitializied: The object has not been given a known value yet int k;
int d();/*generates a warning*/
cout << d << '\n';/*warning: the address of ‘int d()’ will always evaluate as ‘true’ [-Waddress] Output 1*/
int e{};/*generates no warning */
cout << e << '\n';                                                                             /*Output 0*/
int f;/*uninitialized -> warning: ‘f’ may be used uninitialized in this function [-Wmaybe-uninitialized] unexpected result*/
cout << f << '\n';                                                                           /*Output 0*/
// identifier can contain letter Number and _ Identifier can not be keywords. the cant start with a number they should start with a
//lower case  good car_owner bad Car_owner bad CarOwner
//Formating best:
//main()
//{
//} 
//Google style:
//main{
//}
cout << "hello World\n";/*" hello world\n" is called a literal here becase of bein not alterated literal constant*/ 
int p{ 5};/*5 is literal constant*/
//operators:
//unitary operator -  like -5 -operator takes  literal 5 and flips it to produce new output value -5
//binary operator +   like 3 + 4 || << operator takes std::cout as left side and the right side as output 
//ternary operator later
// number of operands a operator takes ic called a operators arity

//Expressions:
//an expression is a combination of literals variable,operators and function calls that can be executed to produce a single value.
// the execution of the expression is called an evaluation and the outcome a result of the expression


int m{2};/*initialize with literal value 2*/
int q{five()};/*initialize with a function return value 5*/
int r{p};/*initialize with variable value 5*/
/* type=*/ int /*identifier=*/ n {/*expression=*/ 2+7};/*initialize with computed value 9  2+7 (two literals one operator) is an expression but needs no semicolon    */

n=7+7;/*this is an expression statement. Expression 7+7 followed by a ; semicolon*/
//programm to dublicate an input value:
cin>>n;
//bad:
n=n*2;/*old c style */
cout<<n<<'\n';
//better
cin>>n;
int double_n{n*2};/*new variable but useless wast*/
cout<<double_n<<'\n';
//best
cin>>n;
cout<< n*2<<'\n';/*best compute by expression where neede n is not alterate and can be used again*/
float fl{};
std::cout<<"f "<<fl<<'\n';
float gl{},hl{};
std::cout<<"gl "<<gl<<"Hl "<<hl<<'\n';
gl=1.1f;

return 0;/*return value of main is 0*/
}
