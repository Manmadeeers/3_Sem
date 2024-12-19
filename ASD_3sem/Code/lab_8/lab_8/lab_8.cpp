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
		//system("cls");
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
			//if row count or column count is 0 - add 0 to the matrix
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}
			else if (weights[i - 1] <=j) {//if current weight is less or equal to simmilar weight itrerator 
				//chose the maximum between the sum of profit of this element and similar index element form a previous row
				// and the simmilar index element itself
				//and maximum of two of them is added to the matrix
				matrix[i][j] = max(profits[i - 1] + matrix[i - 1][j - weights[i - 1]], matrix[i - 1][j]);
			}
			else {
				//in all other cases current element of matrix is written as the simmilar index element from a previous row
				matrix[i][j] = matrix[i - 1][j];
			}
			/*printMatrix(matrix, number_of_things + 1, MAX_bag_weight + 1);
			system("pause");*/
		}
	}
	printMatrix(matrix, number_of_things + 1, MAX_bag_weight + 1);

	cout << "The maximum profit you can get is: " << matrix[number_of_things][MAX_bag_weight] << endl;

	//tracing back to define which elements will be in a backpack
	vector<int>itemsInBackpack;
	int current_row = number_of_things;
	int current_column = MAX_bag_weight;
	while (current_column > 0 && current_row > 0) {
		if (matrix[current_row][current_column] != matrix[current_row - 1][current_column]) {
			itemsInBackpack.push_back(current_row - 1);
			current_column -= weights[current_row - 1];
		} 
		current_row--;
	}
	

	cout << "<-----Elements in a backpack----->" << endl;
	for (int i = 0; i < itemsInBackpack.size(); i++) {
		cout << "Element number " << i + 1 << ": ";
		cout << '{';
		cout<<" Name: " << names[itemsInBackpack[i]] << " , ";
		cout << "Weight: " << weights[itemsInBackpack[i]] << " , ";
		cout << "Price: " << profits[itemsInBackpack[i]] << "}";
		cout << endl;
	}

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