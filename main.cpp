#include<iostream>
#include"linkedlist.h"

using namespace std;

int main() {
	LinkedList<int> train(0);
	for (int i = 1; i < 10; i++) {
		train.append(i);
	}
	train.root->printList();

}