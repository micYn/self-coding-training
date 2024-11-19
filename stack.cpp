#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <class T> 
void ChangeSize1D(const T* a,const int oldSize, const int newSize){
	if(newSize <0)	throw "New size of the array must >=0";
	T* temp;
	temp = new T[newSize];
	int number = min(oldSize,newSize);
	copy(a,a+number,temp);
	delete[] a;
	a = temp;
}
template <class T>
class Stack{
	public:
		Stack(int theCapacity = 10);
		~Stack();
		bool IsEmpty() const;
		T& Top() const;
		void push(const T& obj);
		void pop();
	private:
		T* stack;
		int top;
		int capacity;
};
template <class T>
Stack<T>::Stack(int theCapacity):capacity(theCapacity){
	if(capacity<1)	throw "The capacity must >0";
	stack = new T[capacity];
	top = -1;
}
template <class T>
inline bool Stack<T>::IsEmpty() const{
	if(top == -1)	return true;
	else return false;
}
template <class T>
inline T& Stack<T>::Top() const{
	if(IsEmpty())	throw"The Stack is empty.";
	return stack[top];
}
template <class T>
void Stack<T>::push(const T& obj){
	if(top==capacity-1){
		ChangeSize1D(stack,capacity,capacity*2);
		capacity*=2;
	}
	stack[++top] = obj;
}
template <class T>
void Stack<T>::pop(){
	if(IsEmpty())	throw"The Stack is empty. Cannot pop.";
	stack[top--].~T();
}		
int main(){
}
	
