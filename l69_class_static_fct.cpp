#include<iostream>
#include<vector>
class KlasseA{/*pure static class is also called Monostates it is not possible????? to have several copies c++20 You can have copies*/
	private: static int s_i;
	public: static int get_i(){return s_i;}
};

int KlasseA:: s_i{9};/* HERE*/
class KlasseB{

	public: static int get_i_from_B(){return KlasseA::get_i();}/*static member functin can cal other static member functions BUT:*/
};
class KlasseC{
	private: int s_iC{90};
	public:  int get_i_from_C(){return s_iC;}/*NON STATIC to be called*/
};
/*static member functin CAN'T call other NON static member function WHITHOUT an objects*/
class KlasseD{
	public: static int get_i_from_D(){
//	return KlasseC::get_i_from_C();}};NOT COMPILING
	KlasseC c;
	return c.get_i_from_C();
	}
};


class KlasseE{
	private:static int s_iE;
	public: static int get_i_from_E(){return s_iE;}/*STATIC to be called*/
};
int KlasseE:: s_iE{90};/* HERE*/
class KlasseG{
	public: int get_i_from_G(){
	return KlasseE::get_i_from_E();
	}
};

class KlasseF{
	private:	static int s_iF/*{999}*/;/*FORBIDDEN*/
			static std::vector<char> s_vowel;
			static std::vector<char> s_alphabet;
	/*initialization of static member not possible in MONOSTATES*/
	public: /*static*/ KlasseF(){s_iF=999;}/*constructor CAN'T be static, now it is NOT a pure static Class*/
	       	static int get_i_from_F(){	return s_iF;}
	       	static std::vector<char> get_s_alphabet_from_F(){	return s_alphabet;}
};



class KlasseK{
	private:	static std::vector<char> s_vowel;
			static std::vector<char> s_alphabet;

	public:	       	static std::vector<char> get_s_alphabet_from_F(){	return s_alphabet;}

		       //	static char get_s_alphabet_from_F(){	return s_alphabet[1];}
};




std::vector<char> KlasseK::s_vowel{'A','E','I','O','U'};
std::vector<char> KlasseK::s_alphabet{  []{std::vector<char>v {}; for(char ch{'a'};ch<='z';++ch){v.push_back(ch);}return v;   }() };




int main(){
//	int Klasse:: s_i{9}; NOT HERE

	std::cout << "if a function is declared static it is callable directly without making an object of the class" << '\n';
	std::cout << "this is because they are not attached to a particular object like static member variable with ::"<< '\n';
	std::cout << "they don't have a this pointer, because the this pointer points to OBJECT that the function is working on"<< '\n';
	std::cout << "and NOT a class." << '\n';
	std::cout << KlasseA::get_i() << '\n';
	std::cout << "a static function CAN'T call a non static function without having created an object of the class before" << '\n';
	std::cout << KlasseD::get_i_from_D() << '\n';
	std::cout << "but from a NON static function you can call a static function " << '\n';
	KlasseG g;
	std::cout << g.get_i_from_G() << '\n';
	KlasseA e;
	std::cout << e.get_i() << '\n';
	KlasseA e2;
	std::cout << e2.get_i() << '\n';

//	std::cout << KlasseF::get_s_alphabet_from_F() << '\n';NOT WORKING
	return 0;
}
