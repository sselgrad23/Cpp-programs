#include<iostream>
#include<cstdint>/*for fixed width*/
#include<cmath>/*abs*/
#include<algorithm>/*max*/
void print(int x)
{
std::cout << x << '\n';
}


void print2(const int x)/*runtime constant = const initialization during RUNTIME when called */
{/*compiler keeps track whether compile or runtime const*/
std::cout << x << '\n';/*x cant be changed during function*/
}

bool approximatelyEqual(double a, double b, double epsilon)
{
 return(std::abs(a-b)<=(std::max(std::abs(a),std::abs(b))*epsilon));
}



int main()
{
 std::cout << "bool:\t\t\t" << sizeof(bool) << " bytes\n";/*sizeof is not function it is a unitary operator like -*/
 std::cout << "char:\t\t\t" << sizeof(char) << " bytes\n";/*/t for tabular*/
 std::cout << "long long:\t\t" << sizeof(long long) << " bytes\n";/*/t for tabular*/
 std::cout << "long long long:\t\t" << 0  << " bytes\n";/*/t for tabular*/

 unsigned short x{65535};
 std::cout << "x was: \t\t\t" << x << '\n';
 x=65536;
 std::cout << "x is now: \t\t" << x << '\n';
 x=65537;
 std::cout << "x is now: \t\t" << x << '\n';
 x=0;
 std::cout << "x is now: \t\t" << x << '\n';
 x=-1;
 std::cout << "x is now: \t\t" << x << '\n';
 x=-2;
 std::cout << "x is now: \t\t" << x << '\n';

 std::int16_t i{5};
 std::cout << i;

// std::uint8_t i{5};8 to 64

 std::cout << "least 8: " << sizeof(std::int_least8_t)*8 << " bits\n";  /*behaves like a char therefore avoid*/ 
 std::cout << "least16: " << sizeof(std::int_least16_t)*8 << " bits\n";   
 std::cout << "least32: " << sizeof(std::int_least32_t)*8 << " bits\n"; 
 std::cout << "least64: " << sizeof(std::int_least64_t)*8 << " bits\n";
 std::cout << '\n';   

 std::cout << "fast 8: " << sizeof(std::int_fast8_t)*8 << " bits\n";   /*faster but more memory*/
 std::cout << "fast16: " << sizeof(std::int_fast16_t)*8 << " bits\n";  /*64*/ 
 std::cout << "fast32: " << sizeof(std::int_fast32_t)*8 << " bits\n";  /*64*/
 std::cout << "fast64: " << sizeof(std::int_fast64_t)*8 << " bits\n";  /*64*/
 std::cout << "std::size_t " << sizeof(std::size_t) << " byts\n";  /*64*/
 /*floats*/
// std::cout << std::setprecision(16);  geht nicht
 std::cout << 3.33333333333333333333333f << '\n';/*f=float*/
 std::cout << 3.33333333333333333333333 << '\n';/*double*/
double zero{0.0};
double posinf{5/zero};
std::cout << posinf << '\n';
double neginf{-5/zero};
std::cout << neginf << '\n';
double nan{zero/zero};
std::cout << nan << '\n';
// inf = indetrerminate
//bool
bool b{false};

 std::cout << b << '\n';
 std::cout << !b << '\n';
// std::cout <<boolalpha;  geht nicht

 std::cout << b << '\n';

 std::cout << "enter Integer";
 int x1{};
 std::cin>>x1;
 if(x1>0)std::cout << "the value is positiv\n";
 else if(x1<0)std::cout << "the value is negativ\n";
 else std::cout << "the value is 0\n";

 std::cout << "\"This is a quoted text\"\n";
 std::cout << "this String contains a single backslash \\\n";
 std::cout << "6F in hex is char'\x6F'\n";

 print(static_cast<int>(5.5));/*explicit type conversion cast a double to int*/
 std::cout << static_cast<int>('a') << '\n';

 std::cout << static_cast<unsigned int>(-5);
 std::int8_t myint {65};
 std::cout << myint << '\n';/*prints letter A*/
 std::cout << static_cast<int>(myint) << '\n';
 //const
 print2(9);/*Runtime initializatin of const int in print2 funktion*/
// const int con0; This gives a warning :uninitialized const
// con0=3;  and this gives an error
 const int con {9};/*Compile-time const*/
 const int con2 {3+4};/*also Compile-time const. compiler resolves 3+4  */
 constexpr int con3 {90}; /*better forces compil-time const*/
// error:
// int num;
// std::cin>>num;
// constexpr int con4{num};


 //bad: don't do this old c style
 #define Max_NUM 40
 // if this is in a header and later in main is int Max_Num it gets copie and pasted
 // Macros don't follow scoping rules!!!! 
 //better because when debuging you see 40 not omly Max_Num
 const int maxNum {40};
 if(true)std::cout << "true " << maxNum << '\n';
 bool t = true;
 if(t)std::cout << "true " << maxNum << '\n';

 if(1)std::cout << "true " << maxNum << '\n';

//avoid != and == with floats:
//after Donald Knuth
 if( approximatelyEqual(0.99,0.99,0.01))std::cout << "equal\n";else std::cout << "not equal\n";


 return 0;
}
