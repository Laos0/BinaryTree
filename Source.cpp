#include <iostream>
#include <string>

using namespace std;


class Node {
	
public:
	Node() {
		ele = string();
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
	// Data stored in this node
	string ele;
	// what this node is pointing too
	Node* parent;
	Node* left;
	Node* right;
	
	// My functions

	// Check if the node is the root
	bool isRoot() {
		// if the node that calls this method has no parent then it is the root, so return true, otherwise false
		// the node that calls this method can be called this->

		return this->parent == nullptr;
	}

	// Check if the node is an external
	bool isExternal() {
		// the node that calls this method is called this->
		//check if both left and right is null, if so, then it is an external otherwise a internal 
		return this->left == nullptr && this->right == nullptr;
	}

	bool isInternal() {
		return !isExternal();
	}
};

class BinaryTree {
private: 
	int size;
	Node* root;
public:
	BinaryTree() {
		// the size of the binary tree
		size = 0;
		// The root of the binary tree
		root = nullptr;
	}
	// Return the size of the binary tree
	int getSize() {
		return size;
	}
	// Setting the Binary Tree size 
	void setBinaryTreeSize(int num) {
		this->size = num;
	}
	// Check to see if the binary Tree is empty
	bool isEmpty() {
		if (size == 0) {
			return true;
		}

		return false;
	}
	// Setting the root for the binary treee
	void setRoot(Node* node) {
		root = node;
	}
	// Retreiving the root of the binary tree
	Node* getRoot() {
		return this->root;
	}

	//----------------- Traversal Algorithm ----------------------
	// post-order
	void postOrder(Node* node) {
		if (node != nullptr) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->ele << " ";
		}
		else {
			return;
		}
	}

	// ADD SUB MULT DIVIDE METHOD

	int evaluateExpression(BinaryTree T, Node* node) {
		if (node->isInternal()) {
			//T++
			//cout << T << endl;
			int left = evaluateExpression(T, node->left);
			int right = evaluateExpression(T, node->right);
			return addSubMultDiv(left, right, node->ele);
		}
		else {
			return stoi(node->ele);
		}

	}
	// Print tree expression
	string printExpression(BinaryTree T, Node* node) {
		if (node->isInternal()) {
			//T++;
			//cout << T << endl;
			string left = printExpression(T, node->left);
			string right = printExpression(T, node->right);
			string expression = "(" + left + " " + node->ele + " " + right + ")";
				
			return expression;
		}
		else {
			return node->ele;
		}

	}
	int addSubMultDiv(int num1, int num2, string operation) {
		
		int total;

		if (operation.compare("-") == 0) {
			total = num1 - num2;
			//cout << num1 << "-" << num2 << endl;
		}
		else if (operation.compare("+") == 0) {
			total = num1 + num2;
			//cout << num1 << "+" << num2 << endl;
		}
		else if (operation.compare("/") == 0) {
			total = num1 / num2;
			//cout << num1 << "/" << num2 << endl;
		}
		else if (operation.compare("*") == 0) {
			total = num1 * num2;
			//cout << num1 << "*" << num2 << endl;
		}

		return total;
	}
	

};


int main() {

	/////////// ALL EXTERNAL NODES SHOULD HAVE NUMERICAL OPERANDS  & ALL INTERNAL NODES SHOULD HAVE ARITHMIC OPERATIONS 

	// Creating my Binary Tree
	BinaryTree myBTree;
	myBTree.setBinaryTreeSize(19);

	// Creating my nodes: Need a total of 9 interals and 10 externals = 19 nodes total
	Node* node1 = new Node; // The root
	node1->ele = "-"; // internal

	Node* node2 = new Node; // The left child of the root, internal
	node2->ele = "/";

	Node* node3 = new Node; // The right child of the root, internal
	node3->ele = "+";

	Node* node4 = new Node; // The left child of node2, internal
	node4->ele = "*";

	Node* node5 = new Node; // The right child of node2, internal
	node5->ele = "+";

	Node* node8 = new Node; // left child of node4, internal
	node8->ele = "+";

	Node* node13 = new Node; // left child of node8, external
	node13->ele = "3";

	Node* node14 = new Node; // right child of node8, external
	node14->ele = "1";

	Node* node9 = new Node; // right child of node4, external
	node9->ele = "3";

	Node* node10 = new Node; // left child of node5, internal
	node10->ele = "-";

	Node* node15 = new Node; // left child of node10, external
	node15->ele = "9";

	Node* node16 = new Node; // right child of node 10, external
	node16->ele = "5";

	Node* node11 = new Node; // right child of node5, external
	node11->ele = "2";

	Node* node6 = new Node; // the left child of node3, internal
	node6->ele = "*";

	Node* node12 = new Node; // The left child of node6, external
	node12->ele = "3";

	Node* node17 = new Node; // right child of node6, internal
	node17->ele = "-";

	Node* node18 = new Node; // left child of node17, external
	node18->ele = "7";

	Node* node19 = new Node; // right child of node17, external
	node19->ele = "4";

	Node* node7 = new Node; // right child of node3, external
	node7->ele = "6";

	// Constructing the Binary Tree
	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;
	node2->parent = node1;

	node3->left = node6;
	node3->right = node7;
	node3->parent = node1;

	node4->left = node8;
	node4->right = node9;
	node4->parent = node2;

	node5->left = node10;
	node5->right = node11;
	node5->parent = node2;

	node6->left = node12;
	node6->right = node17;
	node6->parent = node3;

	node7->parent = node3;

	node8->left = node13;
	node8->right = node14;
	node8->parent = node4;

	node9->parent = node4;

	node10->left = node15;
	node10->right = node16;
	node10->parent = node5;

	node11->parent = node5;

	node12->parent = node6;

	node13->parent = node8;

	node14->parent = node8;

	node15->parent = node10;

	node16->parent = node10;

	node17->left = node18;
	node17->right = node19;
	node17->parent = node6;

	node18->parent = node17;

	node19->parent = node17;
	


	// assign the root to the tree
	myBTree.setRoot(node1);

	// Check to see information on a node: 
	
	/*
	cout << node6->isExternal() << endl; // false / 0: it is an internal node
	cout << node6->left->ele << endl; // expect a 3, which is node12's ele
	cout << node6->right->ele << endl; // expect node17, an internal node, which is "-"
	cout << node6->isInternal() << endl; // expect true, or a 1
	cout << myBTree.getRoot()->ele << endl; // expect node1, which is an internal node that has an element of "-"
	*/
	
	cout << "Printing my Binary Tree in post-order" << ": ";
	myBTree.postOrder(node1);
	//myBTree.evaluateExpression(0, node1);

	cout << endl;

	cout << endl;
	
	//cout << myBTree.evaluateExpression(0, node1); // print -13

	cout << myBTree.printExpression(myBTree, node1) << " = " << myBTree.evaluateExpression(myBTree, node1) << endl;

	system("pause");

	return 0;
}