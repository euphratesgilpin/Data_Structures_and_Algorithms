#pragma once

#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL);
	~TreeNode();
	T item;
	TreeNode<T>* leftTree, * rightTree;
	bool search(T key);
	int depth();
private:
};
template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* left, TreeNode<T>* right)
	: item(i), leftTree(left), rightTree(right)
{
}
template <typename T>
TreeNode<T>::~TreeNode()
{
	delete leftTree;
	delete rightTree;
}

template <typename T>
bool TreeNode<T>::search(T key) {

	if (key == item) {
		return true;
	}
	bool lT = false;
	if (leftTree) {
		lT = leftTree->search(key);
	}
	bool rT = false;
	if (rightTree) {
		rT = rightTree->search(key);
	}
	return lT || rT;
}

template <typename T>
int TreeNode<T>::depth() {
	
	int dL = 0;
	if (leftTree) {
		dL = leftTree->depth();
	}
	int dR = 0;
	if (rightTree) {
		dR = rightTree->depth();
	}
	if (dL < dR) {
		return dR + 1;
	}
	else {
		return dL + 1;
	}

	return 0;

}
