//<-------------------->
//
// finding the longest increasing subsequence (LIS) from a sequence
// 
//<-------------------->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//<-----utility functions----->
void printSequence(vector<int>numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		if (i != numbers.size() - 1) {
			cout << numbers[i] << ',';
		}
		else {
			cout << numbers[i];
		}


	}
}
bool isSorted(vector<int>sequence) {
	for (int i = 0; i < sequence.size(); i++) {
		if (i<sequence.size() - 1 && sequence[i]>sequence[i + 1]) {
			return false;
		}
	}
	return true;
}
bool inSubsequence(vector<int>subsequence,int number) {
	for (int i = 0; i < subsequence.size(); i++) {
		if (number == subsequence[i]) {
			return true;
		}
	}
	return false;
}
void getSequence(string sequence,vector<int>&numbers) {
	string tmp = "";
	for (int i = 0; i < sequence.length(); ++i) {


		tmp += sequence[i];
		if (sequence[i] == ','|| i == sequence.length() - 1) {
			numbers.push_back(stoi(tmp));
			tmp = "";
			continue;
		}
	}
}
//end of utility functions

void findMaxSubsequence(string sequence) {
	vector<int>src_sequence;
	getSequence(sequence, src_sequence);
	if (isSorted(src_sequence)) {
		cout << "Given sequence is already sorted in increasing order.So LIS is the sequence itself" << endl;
		cout << "LIS: {";
		for (int i = 0; i < src_sequence.size(); i++) {
			if (i < src_sequence.size() - 1) {
				cout << src_sequence[i] << ',';
			}
			else {
				cout << src_sequence[i];
			}
		}
		cout << "}" << endl;
		cout << "Length of LIS: " << src_sequence.size() << endl;
		return;
	}
	cout << "Given sequence: " << endl;
	printSequence(src_sequence);
	cout << endl;

	vector<int>subsequence(src_sequence.size(),1);
	vector<int>store_LIS;
	int MaxLength = 1;
	for (int i = 0; i < src_sequence.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (src_sequence[i] > src_sequence[j]) {
				subsequence[i] = max(subsequence[i], subsequence[j] + 1);
				store_LIS.push_back(j);
			}
			MaxLength = max(MaxLength, subsequence[i]);
		}
	}
	//FIX
	cout << "Max length: " << MaxLength;
	cout << "Sequence" << endl;
	for (int i = 0; i < store_LIS.size(); i++) {
		cout << src_sequence[store_LIS[i]] << " ";
	}
	cout << endl;
}

void main() {

	string src_sequence;
	cout << "Enter the source sequence(through coma): ";
	getline(cin, src_sequence);
	if (src_sequence.empty()) {
		cout << "Given sequence is empty. Could not proceed further operations" << endl;
		return;
	}
	findMaxSubsequence(src_sequence);

}