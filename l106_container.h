//l106_container.h

#ifndef l106_CONTAINER_H
#define l106_CONTAINER_H
#include<cassert>
#include<initializer_list>
class l106_container
{
	private:int m_length{};
		int* m_data{};
	public:l106_container()=default;
	       l106_container(std::initializer_list<int>list):l106_container(static_cast<int>(list.size())){
		       int count{0};
		       for(auto element : list){m_data[count]=element;++count;}
	       }
	       l106_container(int length):m_length{length}{assert(length>=0 && "as0");if(length>0)m_data=new int [length];}
	       l106_container(const l106_container &)=delete;/*avoid shallow copy*/	
	       l106_container& operator=(const l106_container& list)=delete;/*avoid shallow copy*/	

	       l106_container& operator=(std::initializer_list<int>list){
			int length{static_cast<int>(list.size())};
			if(length!=m_length){
				delete[] m_data;
				m_length=length;
				m_data=new int[length]{};
				int count{0};
				for(auto element:list){m_data[count]=element;++count;}
			}
			return* this;
	       }	       






	       ~l106_container(){delete[] m_data;}
	       void erase(){delete[] m_data; m_data=nullptr; m_length=0;}
	       int& operator[](int index){assert((index >=0 && index < m_length)&& "as1"); return m_data[index];}
	       void reallocate(int newLength){erase();if(newLength<=0)return;m_data=new int[newLength];m_length=newLength;}
	       void resize(int newLength){
		       if(newLength==m_length)return; 
		       if(newLength<=0){erase();return;}
		       int* data{new int[newLength]};
		       if(m_length>0){
			       int elementsToCopy{(newLength>m_length)? m_length:newLength};
			       for(int index{0};index<elementsToCopy; ++index)data[index]=m_data[index];
		       }
		       delete[] m_data;
		       m_data=data;
		       m_length=newLength;
	       }
	       void insertBefore(int value, int index){
		       assert((index>=0&&index<=m_length)&& "as3");
		       int* data{new int[m_length+1]};
		       for(int before{0};before<index;++before)data[before]=m_data[before];
		       data[index]=value;
		       for(int after{index};after<m_length;++after)data[after+1]=m_data[after];
		       delete[] m_data;
		       m_data=data;
		       ++m_length;
	       }
	       void remove(int index){
		       assert((index>=0&&index<=m_length)&& "as4");
		       if(m_length==1){erase();return;}
		       int* data{new int[m_length-1]};
		       for(int before{0};before<index;++before)data[before]=m_data[before];
		       for(int after{index+1};after<m_length;++after)data[after-1]=m_data[after];
		       delete[] m_data;
		       m_data=data;
		       --m_length;
	       }
	       void insertAtBeginning(int value){insertBefore(value,0);}
	       void insertAtEnd(int value){insertBefore(value,m_length);}
	       int getLength() const {return m_length;}
};
#endif	       

