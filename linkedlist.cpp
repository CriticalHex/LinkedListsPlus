#include"linkedlist.h"
#include"node.cpp"
#include<stdexcept>

using namespace std;

template<typename T>
LinkedList<T>::LinkedList(T value) {
	root = new Node(value);
	len = 1;
}


template<typename T>
void LinkedList<T>::insertFront(T value) {
	Node* oldRoot = root;
	Node* newRoot = new Node(value, oldRoot);
	oldRoot->prev = newRoot;
	root = newRoot;
	len++;
}


template<typename T>
void LinkedList<T>::insert(int index, T value) {
	if (index >= len) {
		this->append(value);
		return;
	}
	if (abs(index) >= len or index == 0) {
		this->insertFront(value);
		return;
	}
	Node* oldNode = getIndex(index);
	Node* newPrev = oldNode->prev;
	Node* newNode = new Node(value, oldNode, newPrev);
	newPrev->next = newNode;
	oldNode->prev = newNode;
	len++;
}


template<typename T>
T LinkedList<T>::pop() {
	T removed;
	Node* endNode = getIndex(len - 1);
	removed = endNode->val;
	endNode->prev->next = nullptr;
	len--;
	return removed;
}


template<typename T>
T LinkedList<T>::pop(int index) {
	T removed;
	if (index == 0) {
		removed = root->val;
		root = root->next;
		root->prev = nullptr;
	}
	else {
		Node* atIndex = getIndex(index);
		removed = atIndex->val;
		Node* newPrev = atIndex->prev;
		Node* newNext = atIndex->next;
		if (newNext != nullptr) {
			newNext->prev = newPrev;
		}
		if (newPrev != nullptr) {
			newPrev->next = newNext;
		}
	}
	len--;
	return removed;
}


template<typename T>
LinkedList<T>::Node* LinkedList<T>::getIndex(int index) {
	root->findIndex(index);
}