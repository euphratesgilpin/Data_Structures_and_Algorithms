#include <iostream>
#include "TreeNode.h"

using namespace std;

int main1() {

	// build the leaf nodes
	TreeNode<string>* friday = new TreeNode<string>("Friday"); // level 2
	TreeNode<string>* saturday = new TreeNode<string>("Saturday"); // level 2
	TreeNode<string>* thursday = new TreeNode<string>("Thursday"); // level 2
	TreeNode<string>* wednesday = new TreeNode<string>("Wednesday"); // level 2
	// build the nodes on level 1
	TreeNode<string>* monday = new TreeNode<string>("Monday", friday, saturday);
	TreeNode<string>* tuesday = new TreeNode<string>("Tuesday", thursday, wednesday);
	// build the root which is also the tree
	TreeNode<string>* tree = new TreeNode<string>("Sunday", monday, tuesday);
	
	/*
	bool e = tree->search("Monday");
	cout << e;
	e = tree->search("Tuesday");
	cout << e;
	e = tree->search("Wednesday");
	cout << e;
	e = tree->search("Thursday");
	cout << e;
	e = tree->search("Friday");
	cout << e;
	e = tree->search("Saturday");
	cout << e;
	e = tree->search("Sunday");
	cout << e;
	e = tree->search("Eepday");
	cout << e;
	*/

	int d = tree->depth();
	cout << d;


	delete tree;
	return 0;
}