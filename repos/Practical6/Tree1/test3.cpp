#include <iostream>
#include "TreeNode.h"

using namespace std;

template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree) {
	if (tree == NULL) {
		tree = new TreeNode<T>(key);
	}
	else if (key < tree->item) {
		tree->leftTree = search(key, tree->leftTree);
	}
	else if (key > tree->item) {
		tree->rightTree = search(key, tree->rightTree);
	}
	return tree;
}

TreeNode<int>* bst() {
	// sort sequence
	int* hold = new int[7];
	hold[0] = 6;
	hold[1] = 23;
	hold[2] = 12;
	hold[3] = 69;
	hold[4] = 17;
	hold[5] = 29;
	hold[6] = 7;

	/*
	int temp;
	bool sorted = false;
	do {
		sorted = true;
		for (int i = 0; i < 7; i++) {
			if (hold[i] > hold[i + 1]) {
				temp = hold[i];
				hold[i] = hold[i + 1];
				hold[i + 1] = temp;
				sorted = false;
			}
		}
	} while (sorted == false);

	for (int i = 0; i < 7; i++) {
		cout << hold[i] << " ";
	}
	*/
		// given 6, 23, 12, 69, 17, 29, 7
		// after sorting: 6, 7, 12, 17, 23, 29, 69
		// using search with insertion method to build the balanced BST
	TreeNode<int>* tree = NULL;
	tree = search(17, tree);
	tree = search(7, tree);
	tree = search(6, tree);
	tree = search(12, tree);
	tree = search(29, tree);
	tree = search(23, tree);
	tree = search(69, tree);
	return tree;
}

int sigma(TreeNode<int>* tree) {
	if (tree == NULL) return 0;
	else {
		return tree->item + sigma(tree->leftTree) + sigma(tree->rightTree);
	}
}

int maxnum(TreeNode<int>* tree) {
	int num = 0;
	if (tree == NULL) return 0;
	else {
		
		while (tree != NULL) {
			num = tree->item;
			tree = tree->rightTree;
		}
	}
	return num;
}



int main() {


	// build the bst
	TreeNode<int>* tree = bst();
	// sigma
	cout << "Sum of the nodes = " << sigma(tree) << endl;
	// maxnum
	cout << "Maximum number in the tree = " << maxnum(tree) << endl;
	// depth
	cout << "Depth of tree = " << tree->depth() << endl;
	// search using the search function in TreeNode class:
	// 69 found in tree, return true (1)
	cout << tree->search(69) << endl;
	// 70, not found in tree, return false (0)
	cout << tree->search(70) << endl;
	// search using the search with insertion function:
	// 69 found in tree, tree is unchanged
	tree = search(69, tree);
	// 70, not found in tree, 79 is inserted and new tree is returned
	tree = search(70, tree);
	cout << "Depth of tree = " << tree->depth() << endl;
	cout << "Maximum number in the tree = " << maxnum(tree) << endl;
	// free the tree memory
	delete tree;
	return 0;
}
