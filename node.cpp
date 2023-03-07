#include"node.h"
#include<iostream>

using namespace std;

template<typename T> template<typename S>
LinkedList<T>::Node<S>::Node(S value, LinkedList<T>::Node<S>* next_node, LinkedList<T>::Node<S>* prev_node) {
	val = value;
	next = next_node;
	prev = prev_node;
}


template<typename T> template<typename S>
LinkedList<T>::Node<S>* LinkedList<T>::Node<S>::findIndex(int index) {
	if (index == 0) {
		return this;
	}
	else if (next != nullptr) {
		return next->findIndex(index - 1);
	}
	throw out_of_range("Index out of range");
}


template<typename T> template<typename S>
LinkedList<T>::Node<S>* LinkedList<T>::Node<S>::findValue(S value) {
	if (val == value) {
		return this;
	}
	else if (next != nullptr) {
		return next->findValue(value);
	}
}


template<typename T> template<typename S>
LinkedList<T>::Node<S>* LinkedList<T>::Node<S>::findEnd() {
	if (next != nullptr) {
		return next->findEnd();
	}
	return this;
}


template<typename T> template<typename S>
void LinkedList<T>::Node<S>::printList() {
	cout << val << " ";
	if (next != nullptr) {
		next->printList();
	}
	else {
		cout << endl;
	}
}