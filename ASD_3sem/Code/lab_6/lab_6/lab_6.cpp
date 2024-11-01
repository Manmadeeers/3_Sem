//<-------------------->
//
// Realization of Hafman's algorithm
// 
//<-------------------->
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define SUM_SYMBOL '$'
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
	if (Node1->freq != Node2->freq) {
		return Node1->freq < Node2->freq;
	}
	return Node1->symbol < Node2->symbol;
}

void assignCodes(Node* root, string current_code, map<char, string>& codes) {
	if (!root) {
		return;
	}
	if (isLeaf(root)) {
		codes[root->symbol] = current_code;
		return;
	}
	assignCodes(root->left, current_code + "0", codes);
	assignCodes(root->right, current_code + "1", codes);
}

void printCodes(map<char, string>codes) {
	string encoded_line;
	for (const auto&pair:codes) {
		cout << pair.first << " : " << pair.second << endl;
		encoded_line += pair.second;
	}
	cout << endl << endl<<"Encoded line: " << encoded_line << endl;
}
//<---end of util functions--->

void buildHaffman(string line) {
	if (line == "") {  
		return;
	}
	vector<Node*>Nodes;
	map<char, string>Codes;

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

	sort(Nodes.begin(), Nodes.end(), sortNodes);
	cout << "Nodes" << endl;
	printNodes(Nodes);

	while (Nodes.size() > 1) {
		Node* SummaryNode = new Node();
		Node* leftNode = Nodes[0];
		Node* rightNode = Nodes[1];
		SummaryNode->freq = leftNode->freq + rightNode->freq;
		SummaryNode->symbol = SUM_SYMBOL;
		SummaryNode->left = leftNode;
		SummaryNode->right = rightNode;
		Nodes.erase(Nodes.begin());
		Nodes.erase(Nodes.begin());
		Nodes.push_back(SummaryNode);
		//cout << leftNode->symbol << "+" << rightNode->symbol << endl;
		sort(Nodes.begin(), Nodes.end(), sortNodes);
	}
	cout<<"Summary: " << Nodes[0]->freq << endl;
	
	assignCodes(Nodes[0], "", Codes);
	cout << "Huffman codes: " << endl;
	printCodes(Codes);

}

void main() {
	string line_to_encode;
	cout << "Enter the line to be encoded: ";
	getline(cin, line_to_encode);
	buildHaffman(line_to_encode);
}