#include<iostream>
#include<utility>/*swap*/
#include<functional>/*std::function*/

void selectionSort(int* array, int size, std::function<bool(int,int)>comp_fct )
//void selectionSort(int* array, int size, bool(*comp_fct)(int,int) )
//void selectionSort(int* array, int size, bool comp_fct(int,int) )/*Works too: parameter function type converted to pointer to function typ*/
{
 for(int startIndex{0};startIndex<(size-1);++startIndex)
 {
	 int bestIndex{startIndex};
	 for(int currentIndex{startIndex + 1};currentIndex < size; ++currentIndex)
	 {
		 if(comp_fct(array[bestIndex],array[currentIndex]))bestIndex=currentIndex;
	 }
	 std::swap(array[startIndex],array[bestIndex]);
 }
}

void printArray(int *array, int size)
{
	for(int index{0};index<size;++index)
	{
		std::cout << array[index] <<' ';
	}
}



// callback functions:
bool ascending(int x,int y){return x>y;}
bool descending(int x,int y){return x<y;}
bool evensfirst(int x,int y){
	if((x%2==0)&&!(y%2==0))return false;
	if(!(x%2==0)&&(y%2==0))return true;
	return ascending(x,y);
}
int main()
{

 std::cout << "callback function is a function used as an argument to an other function\n";
 int array[9]{34,5,22,8,77,12,1,89,55};
  selectionSort(array,9,descending);
 printArray(array,9);
 std::cout << '\n';
 selectionSort(array,9,ascending);
 printArray(array,9);
 std::cout << '\n';
 selectionSort(array,9,evensfirst);
 printArray(array,9);


 return 0;
} 
