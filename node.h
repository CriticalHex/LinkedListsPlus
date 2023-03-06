#pragma once
#include"linkedlist.h"

template<typename T>
class LinkedList<T>::Node {
public:
	Node* findIndex(int index);
	Node* findValue(T value);
	Node* findEnd();
	void printList();
	Node(T value, Node* next_node = nullptr, Node* prev_node = nullptr);
	T val;
	Node* next;
	Node* prev;
};