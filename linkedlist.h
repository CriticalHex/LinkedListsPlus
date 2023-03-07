#pragma once
template<typename T>
class LinkedList {
public:
	template<typename S> class Node;
	Node* root;
	int len;
	LinkedList(T value);
	void insertFront(T value);
	void insert(int index, T value);
	Node<T>* getIndex(int index);
	T pop(int index);
	T pop();
	void append(T value);
	void remove(T value);
	void reverse();
	void swapNodes(Node* node1, Node* node2);
	void fullSwap();
};