#include<iostream>
#include<functional>

void invoke(const std::function<void()>& fct){fct();}


int main()
{
int i{0};
auto count{[i]()mutable{std::cout << ++i <<'\n';}};/*avoid mutable lambdas*/
count();/*prints 1*/
auto anotherCount{count};/*creates a copy of count*/
count();/*prints 2*/
anotherCount();/*prints 2 to, becaus has its own copy*/
i=0;/*i is now 0 but:*/
invoke(count);/*prints 3,because i in lambda is 2 and std::function make a copy of the lambda object*/
invoke(count);/*also prints 3,because i in lambda is 2 and std::function makes ANOTHER copy of the lambda object*/
invoke(count);/*also prints 3*/
//better this::
invoke(std::ref(count));/*still prints 3 but now std::ref make sure that only one count exists*/
invoke(std::ref(count));/*prints 4*/
invoke(std::ref(count));
invoke(std::ref(count));
 return 0;
} 
