//g++-11 -Wall -o p l46_func_stack_heap.cpp -std=c++2a
#include<iostream>
void fkt(){fkt();}/*function calling itselfe so often until stack is full */
int main()
{

 std::cout << "the memory program is using: code(or text) segment for compiled program read only\n";
 std::cout << "bss segment = uninitilalized data segment. for static variables and zero-initialized global variables\n";
 std::cout << "data or initialized data segment . for static variables?????? and initialized global variables\n";
 std::cout << "heap or free store for dynamic allocated variable SLOW\n";
 std::cout << "call stack for function parameter and related information and for local variables implemented as\n";
 std::cout << "stack data structur three operations: peek() look at top, pop() take top element off, push() put element on top\n";
 std::cout << "call stack segment holds memory for call stack. when main() is pushed on the stack by operating system it starts execution\n";
 std::cout << "when a function cll is encounterd the function is pushed on stack at end it gets popped off.\n";
 std::cout << "elements popped and pushed ar Stack frames, if popped memory is not cleand but pointer is lowerd, next push overrides.\n";
 std::cout << "stack size in Windown 1MB unix 8MB. if to full Stack overflow. stack entering other memory.\n";

 int arr[10000000];/*stack overflow = Segentation fault*/
 std::cout << "never reached";


 return 0;
} 
