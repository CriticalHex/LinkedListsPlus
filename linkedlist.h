#pragma once
template<typename T>
class LinkedList {
public:
	class Node;
	Node* root;
	int len;
	LinkedList(T value);
	void insertFront(T value);
	void insert(int index, T value);
	Node* getIndex(int index);
	T pop(int index);
	T pop();
};