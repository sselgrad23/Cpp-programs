#include<iostream>
#include<vector>
template <typename T> void prtNUMofEL(const std::vector<T> &v){std::cout << "num of el:" << v.size() << '\n';}
template <typename T> void prtEL(const std::vector<T> &v)
{
 for(auto i : v)std::cout << i << ' '; 
 std::cout << '\n';
}
template <typename T> void prtEL2(const std::vector<T> &v)
{
 auto start{std::begin(v)};/*std::begin(v) is a pointer pointing at beginn of block*/
 auto end  {std::end(v)};
 std::cout << * std::begin(v) << '\n';
 std::cout << * end   << '\n';
 for(auto ptr{start}; ptr != end; ++ptr)std::cout <<  * ptr << ' ';/*ptr is a pointr so * ptr. ptr is an ITERATOR*/ 
 std::cout << '\n';
}
template <typename T> void prtStack(const std::vector<T> s)
{
 for(auto el : s )std::cout <<  el << ' ';/*ptr is a pointr so * ptr. ptr is an ITERATOR*/ 

 std::cout << "cap: " << s.capacity()<< " size: " << s.size() << '\n';
}





int main()
{
 std::cout << "Vector like dynamic memory new delete but automatic clean up like c# or java\n";
 std::vector v {6,4,2,7,5,9,0};
 v.at(2)=1;
 std::cout << "number of elements: " << v.size() << '\n';
 for(auto i : v) std::cout << i << ' ' ;
 std::cout << '\n';

 std::vector vd {6.1,4.1,2.1,7.1,5.1,9.1,0.1};
 vd.at(2)=0.0;
 std::cout << "number of elements: " << vd.size() << '\n';
 for(auto i : vd) std::cout << i << ' ' ;
 std::cout << '\n';

 prtEL(v);
 prtNUMofEL(v);
 prtEL(vd);
 prtNUMofEL(vd);

 std::cout << "Resizing a vector with .resize:\n";
 v.resize(10);
 vd.resize(10);
 prtEL(v);
 prtNUMofEL(v);
 prtEL(vd);
 prtNUMofEL(vd);

 v.resize(4);
 vd.resize(4);

 prtEL(v);
 prtNUMofEL(v);
 prtEL(vd);
 prtNUMofEL(vd);

 std::cout << vd.size() << ' ' << vd.capacity() << '\n';
 
 vd={6.1,4.1};
 std::cout << vd.size() << ' ' << vd.capacity() << '\n';/*capacity what can goes in size what is in*/
 std::cout << "compacting bools:\n";
 std::vector vb {true,false,false,true,true,false,false};
 prtEL(vb);
 prtNUMofEL(vb);


 prtEL2(vd);

 
 std::vector<int> s  {23,24,25,26};
 prtStack(s);
 s.push_back(34);
 prtStack(s);
 s.push_back(3);
 prtStack(s);
 std::cout << "top of stack: " << s.back() << '\n';
 s.pop_back();
 prtStack(s);
 s.pop_back();
 prtStack(s);
 std::cout << "top of stack: " << s.back() << '\n';
 std::cout << "resizing expensive so .reserve\n";


 std::vector<int> sr{};
 sr.reserve(10);
 sr={23,24,25,26};
 prtStack(sr);

 return 0;
} 
