#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <class T>
class Queue{
	public:
		Queue(int theCapacity = 10);
		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;
		void push(const T& obj);
		void pop();
	private:
		T* queue;
		int front;
		int rear;
		int capacity;
};
template <class T>
Queue<T>::Queue(int theCapacity):capacity(theCapacity){
	if(capacity<1)	throw "The capacity cannot >=0.";
	front = rear = 0;
	queue = new T[capacity];
}
template <class T>
inline bool Queue<T>::IsEmpty() const{
	return (front==rear);
}
template <class T>
inline T& Queue<T>::Front() const{
	if(IsEmpty())	throw "The queue is empty.";
	return queue[(front+1)%capacity];
}
template <class T>
inline T& Queue<T>::Rear() const{
	if(IsEmpty())	throw "The queue is empty.";
	return queue[rear];
}
template <class T>
void Queue<T>::push(const T& obj){
	if((rear+1)%capacity==front){
		T* newQueue = new T[2*capacity];
		int start = (front+1)%capacity;
		if(start<2){
			copy(queue+start,queue+capacity-start,newQueue);
		}
		else{
			copy(queue+start,queue+capacity,newQueue);
			copy(queue,queue+rear+1,newQueue+capacity-start);
		}
		front = 2*capacity-1;
		rear = capacity-2;
		capacity*=2;
		delete[] queue;
		queue = newQueue;
	}
	rear = (rear+1)%capacity;
	queue[rear] = obj;
}
template <class T>
void Queue<T>::pop(){
	if(IsEmpty())	throw "the queue is empty.";
	front = (front+1)%capacity;
	queue[front].~T();
}
int main(){
}




















	
