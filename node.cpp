#include"node.h"
#include<iostream>

using namespace std;

template<typename T>
LinkedList<T>::Node::Node(T value, Node* next_node, Node* prev_node) {
	val = value;
	next = next_node;
	prev = prev_node;
}


template<typename T>
LinkedList<T>::Node* LinkedList<T>::Node::findIndex(int index) {
	if (index == 0) {
		return this;
	}
	else if (next != nullptr) {
		return next->findIndex(index - 1);
	}
	throw out_of_range("Index out of range");
}


template<typename T>
LinkedList<T>::Node* LinkedList<T>::Node::findValue(T value) {
	if (val == value) {
		return this;
	}
	else if (next != nullptr) {
		return next->findValue(value);
	}
}


template<typename T>
LinkedList<T>::Node* LinkedList<T>::Node::findEnd() {
	if (next != nullptr) {
		return next->findEnd();
	}
	return this;
}


template<typename T>
void LinkedList<T>::Node::printList() {
	cout << val << " ";
	if (next != nullptr) {
		next->printList();
	}
	else {
		cout << endl;
	}
}