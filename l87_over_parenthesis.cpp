//g++-11 -Wall -o p l87_over_parenthesis.cpp -std=c++2a
#include<iostream>
#include<cassert>
class Matrix
{
	private:double m_data[4][4][4]{};
	public:double& operator()(int dim1,int dim2, int dim3);
               double operator()(int dim1,int dim2,int dim3)const;
               void operator()();/*No parameter*/
};

double& Matrix::operator()(int dim1,int dim2,int dim3)
{assert(dim1>=0&&dim1<4);assert(dim2>=0&&dim2<4);assert(dim3>=0&&dim3<4);return m_data[dim1][dim2][dim3];}
double Matrix::operator()(int dim1,int dim2,int dim3)const
{assert(dim1>=0&&dim1<4);assert(dim2>=0&&dim2<4);assert(dim3>=0&&dim3<4);return m_data[dim1][dim2][dim3];}
void Matrix::operator()()
{
	for(int dim1{0};dim1<4;++dim1){
		for(int dim2{0};dim2<4;++dim2){
			for(int dim3{0};dim3<4;++dim3){
				m_data[dim1][dim2][dim3]=0.0;
			}
		}
	}
}
int main(){
	std::cout << "operator() allows to vary both the TYPE and NUMBER ofparameter it takes(! one Parameter, ++ 2 parameter  " << '\n';
	std::cout << "operator() must be implementet as MEMBER function, non OOP ()called functions. "<< '\n';
	Matrix matrix;
	matrix(1,2,3)=4.5;
	std::cout << matrix(1,2,3) << '\n';
	matrix();
	std::cout << matrix(1,2,3) << '\n';
	return 0;

	return 0;
}
