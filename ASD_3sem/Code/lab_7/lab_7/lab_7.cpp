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
	cout << endl<<endl;
}
bool sortSequence(int first, int second) {
	return first < second;
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
	vector<int>numbers;
	getSequence(sequence, numbers);
	cout << "Sequence: " << endl;
	printSequence(numbers);
	sort(numbers.begin(), numbers.end(), sortSequence);
	cout << "Sorted sequence: " << endl;
	printSequence(numbers);
}

void main() {

	string src_sequence;
	cout << "Enter the source sequence(through coma): ";
	getline(cin, src_sequence);
	findMaxSubsequence(src_sequence);

}