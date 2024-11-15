//<-------------------->
// 
// solving the classical knapsack problem in bottom-up manner
//
//<-------------------->

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//<-----utility functions----->
void printMatrix(vector<vector<int>>matrix, int lines, int columns) {
	cout << "MATRIX:" << endl;
	cout << '\t';
	for (int w = 0; w < columns; w++) {
		cout << w <<'\t';
	}
	cout << endl << endl;
	for (int i = 0; i < lines; i++) {
		cout << '\t';
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] <<'\t';
		}
		cout<<'\t' << i << endl;
	}
}
//<-----end of util----->

void packBag(int MAX_bag_weight, int number_of_things) {

	vector<int>weights(number_of_things);
	vector<int>profits(number_of_things);
	vector<string>names(number_of_things);


	for (int i = 0; i < number_of_things; i++) {
		cout << "Item number " << i + 1 << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter the item's name: ";
		getline(cin, names[i]);
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Enter the item's weight: ";
		cin >> weights[i];
		cout << "Enter the item's price: ";
		cin >> profits[i];
		system("cls");
	}
	for (int i = 0; i < number_of_things; i++) {
		cout << "{" << names[i] << ',' << weights[i] << ',' << profits[i] << '}';
	}
	cout << endl << endl;

	vector<vector<int>>matrix(number_of_things+1 , vector<int>(MAX_bag_weight+1));
	for (int i = 0; i < number_of_things+1; i++) {
		for (int j = 0; j < MAX_bag_weight+1; j++) {
			matrix[i][j] = 0;
		}
	}
	printMatrix(matrix, number_of_things+1, MAX_bag_weight+1);

	for (int i = 0; i < number_of_things + 1; i++) {
		for (int j = 0; j < MAX_bag_weight+1; j++) {
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else if (weights[i - 1] <=j) {
				matrix[i][j] = max(profits[i - 1] + matrix[i - 1][j - weights[i - 1]], matrix[i - 1][j]);
			}
			else {
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}
	printMatrix(matrix, number_of_things + 1, MAX_bag_weight + 1);

	cout << "The maximum profit you can get is: " << matrix[number_of_things][MAX_bag_weight];
}


void main() {
	int MAX_bag_weight;
	cout << "Enter the maximum weight the bag can take: ";
	cin >> MAX_bag_weight;
	int amount_of_stuff;
	cout << "Enter the number of element's you've got: ";
	cin >> amount_of_stuff;
	packBag(MAX_bag_weight, amount_of_stuff);
}