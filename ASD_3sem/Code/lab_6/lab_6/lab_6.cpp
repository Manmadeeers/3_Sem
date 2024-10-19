//<-------------------->
//
// Realization of Hafman's algorithm
// 
//<-------------------->
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#define SUM_SYMBOL '#'
using namespace std;

struct Node {
	char symbol;
	int freq;
	Node* left;
	Node* right;
};

//<---utility functions--->

bool isLeaf(Node* root) {
	return root->left == nullptr && root->right == nullptr;
}

int countFreq(char symb, string line) {
	int freq = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == symb) {
			freq++;
		}
	}
	return freq;
}
bool checkPresense(char symb, vector<Node*>Nodes) {
	for (int i = 0; i < Nodes.size(); i++) {
		if (Nodes[i]->symbol == symb) {
			return true;
		}
	}
	return false;
}
void printNodes(vector<Node*>Nodes) {
	for (int i = 0; i < Nodes.size(); i++) {
		cout << Nodes[i]->symbol << " : " << Nodes[i]->freq << endl;
	}
}

bool sortNodes(const Node* Node1, const Node* Node2) {
	return Node1->freq < Node2->freq;
}

//<---end of util functions--->

void buildHaffman(string line) {
	if (line == "") {
		return;
	}
	vector<Node*>Nodes;

	for (int i = 0; i < line.size(); i++) {
		Node* NewNode = new Node();
		char current = line[i];
		int freq = countFreq(current, line);
		if (!checkPresense(current, Nodes)) {
			NewNode->freq = freq;
			NewNode->symbol = current;
			NewNode->left = nullptr;
			NewNode->right = nullptr;
			Nodes.push_back(NewNode);
		}
	}

	printNodes(Nodes);
	sort(Nodes.begin(), Nodes.end(), sortNodes);
	cout << "Sorted nodes" << endl;
	printNodes(Nodes);

	while (Nodes.size() > 1) {
		Node
	}


}

void main() {
	string line_to_encode;
	cout << "Enter the line to be encoded: ";
	getline(cin, line_to_encode);
	buildHaffman(line_to_encode);
}