//<-------------------->
//
// Floyd-Worshell's algorythm realization
// 
// 
//<-------------------->


#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;

//constants
const int NodesInGraph = 6;
vector<vector<int>>D0matrix(NodesInGraph, vector<int>(NodesInGraph));
vector<vector<int>>S0Matrix(NodesInGraph, vector<int>(NodesInGraph));


void InitDMatrix(vector<vector<int>>&DMatrix) {
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			if (i == j) {
				DMatrix[i][j] = 0;
			}
			else {
				DMatrix[i][j] = INF;
			}
		}
	}
}

void InitSMatrix(vector<vector<int>>&SMatrix) {
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			if (i == j) {
				SMatrix[i][j] = 0;
			}
			else {
				SMatrix[i][j] = j + 1;
			}
			
		}
	}
}



//substraction needed because of "human" input
void AddRelation(int Source,int Destination,int Weight) {
	D0matrix[Source-1][Destination-1] = Weight;
}

void PrintMatirx(vector<vector<int>>Matrix) {
	cout << endl << endl;
	for (int k = 0; k < NodesInGraph; k++) {
		cout << '\t' << k + 1;
	}
	cout << endl << endl;
	for (int i = 0; i < NodesInGraph; i++) {
		cout << '\t';
		for (int j = 0; j < NodesInGraph; j++) {
			if (Matrix[i][j] == INF) {
				cout << "INF" << '\t';
			}
			else {
				cout << Matrix[i][j] << '\t';
			}
			
		}
		cout<<i+1 << endl;
	}
	cout << endl << endl;
}

void FloydWarshall(vector<vector<int>>&Matrix,vector<vector<int>>&Smatrix) {

	for (int k = 0; k < NodesInGraph; k++) {
		for (int i = 0; i < NodesInGraph; i++) {
			for (int j = 0; j < NodesInGraph; j++) {
				if (Matrix[i][j] > (Matrix[i][k] + Matrix[k][j])&&(Matrix[k][j]!=INF&&Matrix[i][k]!=INF)) {
					Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
					Smatrix[i][j] = k + 1;
				}
			}
		}
	}
}

void main() {
	cout << "Floyd-Worshell's algorythm implementation: " << endl;

	InitDMatrix(D0matrix);

	AddRelation(1, 2, 28);
	AddRelation(2, 1, 7);
	AddRelation(1, 3, 21);
	AddRelation(3, 1, 9);
	AddRelation(1, 4, 59);
	AddRelation(4, 1, 8);
	AddRelation(1, 5, 12);
	AddRelation(5, 1, 14);
	AddRelation(1, 6, 27);
	AddRelation(6, 1, 15);
	AddRelation(2, 3, 24);
	AddRelation(3, 2, 32);
	AddRelation(2, 6, 9);
	AddRelation(6, 2, 18);
	AddRelation(2, 5, 21);
	AddRelation(5, 2, 13);
	AddRelation(3, 4, 13);
	AddRelation(4, 3, 5);
	AddRelation(3, 5, 11);
	AddRelation(5, 3, 15);
	AddRelation(4, 5, 16);
	AddRelation(5, 4, 10);
	AddRelation(5, 6, 22);
	AddRelation(6, 5, 6);

	cout << "Start Dmatrix: ";
	PrintMatirx(D0matrix);
	InitSMatrix(S0Matrix);
	cout << "Start Smatirx: ";
	PrintMatirx(S0Matrix);

	FloydWarshall(D0matrix,S0Matrix);
	cout << "Updated Dmatrix: ";
	PrintMatirx(D0matrix);
	cout << "Updated Smatrix: ";
	PrintMatirx(S0Matrix);

}