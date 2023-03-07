#pragma once
#include"linkedlist.h"

template<typename T> template<typename S>
class LinkedList<T>::Node {
public:
	Node* findIndex(int index);
	Node* findValue(S value);
	Node* findEnd();
	void printList();
	Node(S value, Node* next_node = nullptr, Node* prev_node = nullptr);
	S val;
	Node* next;
	Node* prev;
};