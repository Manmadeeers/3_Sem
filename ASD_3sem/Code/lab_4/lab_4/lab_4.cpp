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
vector<vector<int>>DMatrix(NodesInGraph, vector<int>(NodesInGraph));
vector<vector<int>>SMAtrix(NodesInGraph, vector<int>(NodesInGraph));


//possibly parameters should be transfered by the link to InitMatrix functions 
void InitDMatrix(vector<vector<int>>DMatrix) {
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			DMatrix[i][j] = INF;
		}
	}
}

void InitSMatrix(vector<vector<int>>SMatrix) {
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			SMatrix[i][j] = j+1;
		}
	}
}

void AddRelation(int Source,int Destination,int Weight) {
	D0matrix[Destination-1][Source-1] = Weight;
}

void PrintMatirx(vector<vector<int>>Matrix) {
	cout << "The matrix is: " << endl << endl;
	for (int k = 0; k < NodesInGraph; k++) {
		cout << '\t' << k + 1;
	}
	cout << endl << endl;
	for (int i = 0; i < NodesInGraph; i++) {
		cout << '\t';
		for (int j = 0; j < NodesInGraph; j++) {
			cout << Matrix[i][j] << '\t';
		}
		cout<<i+1 << endl;
	}
	cout << endl << endl;
}

void FloydWorshall() {

	int LeadingLC = 1;//needs substraction because of an array
	for (int k = 0; k < NodesInGraph; k++) {
		for (int i = 0; i < NodesInGraph; i++) {
			for (int j = 0; j < NodesInGraph; j++) {
				if (D0matrix[i][j] > (D0matrix[i][k] + D0matrix[k][j])&&(D0matrix[k][j]!=INF&&D0matrix[i][k]!=INF)) {
					DMatrix[i][j] = D0matrix[i][k] + D0matrix[k][j];
					SMAtrix[i][j] = k + 1;
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

	PrintMatirx(D0matrix);
	DMatrix = D0matrix;
	FloydWorshall();
	PrintMatirx(DMatrix);
	PrintMatirx(SMAtrix);
	/*InitSMatrix(S0Matrix);
	PrintMatirx(S0Matrix);

	InitDMatrix(DMatrix);
	InitSMatrix(SMAtrix);
	DMatrix = D0matrix;
	SMAtrix = S0Matrix;*/

	//FloydWorshall();
	//PrintMatirx(DMatrix);
	//PrintMatirx(SMAtrix);

}