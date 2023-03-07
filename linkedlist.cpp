#include"linkedlist.h"
#include"node.h"
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
void LinkedList<T>::append(T value) {
	Node* end = root->findEnd();
	end->next = new Node(value, nullptr, end);
	len++;
}


template<typename T>
void LinkedList<T>::remove(T value) {
	if (root->val == value) {
		root = root->next;
		root->prev = nullptr;
		return;
	}
	if (Node* found = root->findValue(value) != nullptr) {
		Node* newPrev = found->prev;
		Node* newNext = found->next;
		if (newNext != nullptr) {
			newNext->prev = newPrev;
		}
		newPrev->next = newNext;
		return;
	}
	throw 0;
}


template<typename T>
void LinkedList<T>::reverse() {
	LinkedList newList = LinkedList(root->findEnd()->val);
	for (int i = len - 2; i >= 0; i--) {
		newList.append(root->findIndex(i)->val);
	}
	this = newList;
}


template<typename T> template<typename S>
LinkedList<T>::Node<S>* LinkedList<T>::getIndex<T>(int index) {
	return root->findIndex(index);
}


template<typename T>
void LinkedList<T>::fullSwap() {
	for (int i = 0; i < len; i += 2) {
		if (i + 1 < len) {
			swapNodes(getIndex(i), getIndex(i + 1));
		}
	}
}


template<typename T>
void LinkedList<T>::swapNodes(Node* node1, Node* node2) {
	Node* node1Prev = node1->prev;
	Node* node2Next = node2->next;
	node2->prev = node1Prev;
	node2->next = node1;
	node1->prev = node2;
	node1->next = node2Next;
	if (node1Prev != nullptr) {
		node1Prev->next = node2;
	}
	else {
		root = node2;
	}
	if (node2Next != nullptr) {
		node2Next->prev = node1;
	}
}