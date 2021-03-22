#ifndef Stack_H
#define Stack_H
#include <cstdlib>

template <typename T>
class ListNode{
public:
	ListNode<T>(T d);
	~ListNode<T>();
	T data;
	ListNode<T>* next;
};

template <typename T>
ListNode<T>::ListNode(T d){
	data = d;
	next = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
}

template <typename T>
class GenStack{
public:
	GenStack<T>();
	~GenStack<T>();
	int size();
	bool isEmpty();
	void push(T d);
	T pop();
	T peek();

private:
	ListNode<T>* top;
	int isize;
};

template <typename T>
GenStack<T>::GenStack(){
	top = NULL;
	isize = 0;
}

template <typename T>
GenStack<T>::~GenStack(){
	//create new node
	ListNode<T>* current = top;

	while (current != NULL){
		ListNode<T>* temp = current;
		current = current->next;
		delete temp;
	}
	top = NULL;
}

template <typename T>
bool GenStack<T>::isEmpty(){ //constatnt
	return isize == 0;
}

template <typename T>
int GenStack<T>::size(){ //constatnt
	return isize;
}

template <typename T>
void GenStack<T>::push(T d){ //BIG O 1
	//create new node
	ListNode<T>* newNode = new ListNode<T>(d);

	if (top == NULL){
		//if the top is empty then the new node is the top node
		top = newNode;
	}
	else{
		//else top is old tops next thing
		newNode->next = top;
		top = newNode;
	}
	//add to size
	++isize;
}

template <typename T>
T GenStack<T>::pop(){ //constatnt
	//get top data
	T returnVal = top->data;
	//if it's empty
	if(top == NULL){
		return 0;
	}
	else{
		ListNode<T>* newNode = top;
		//the new top once pop the olds
		top = top->next;
	}
	//decrement the size
	--isize;
	//return what's at the top
	return returnVal;
}

template <typename T> //gets item at the top of stack
T GenStack<T>::peek(){
	return top->data;
}
#endif
