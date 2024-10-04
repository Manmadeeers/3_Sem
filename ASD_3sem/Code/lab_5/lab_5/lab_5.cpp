//<-------------------->
// 
// finding Minimal Spanning Tree (MST) via different algorythms
// 
//<-------------------->
#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;
const int NodesInGraph = 8;
vector<vector<int>>AdjMatrix(NodesInGraph, vector<int>(NodesInGraph));

void addRelation(int Source,int Dest,int Weight) {
	//substraction because of a human input
	AdjMatrix[Source-1][Dest-1] = Weight;
	//graph is undirected
	AdjMatrix[Dest - 1][Source - 1] = Weight;
}

void InitMatrix(vector < vector<int>>& Matrix){
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			if (i == j) {
				Matrix[i][j] = 0;
			}
			else {
				Matrix[i][j] = INF;
			}
			
		}
	}
}

void printMatrix(vector < vector<int>>Matrix) {
	cout << '\t';
	for (int i = 0; i < NodesInGraph; i++) {
		cout << i + 1 << '\t';
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
		cout << i + 1 << endl;
	}
}


void PrimMST(vector<vector<int>>Matrix, int StartVertex) {
	vector<bool>InMST(NodesInGraph, false);
	vector<int>MST(NodesInGraph,0);
	InMST[StartVertex] = true;
	int edge_iterator = 0;
	int x, y;
	cout << "Edge : Weigth" << endl;
	while (edge_iterator < NodesInGraph - 1) {
		int Minimum = INF;
		x = 0;
		y = 0;
		for (int i = 0; i < NodesInGraph; i++) {
			if (InMST[i]) {
				for (int j = 0; j < NodesInGraph; j++) {
					if (!InMST[j] && AdjMatrix[i][j]) {
						if (Minimum > AdjMatrix[j][j]) {
							Minimum = AdjMatrix[i][j];
							x = i;
							y = j;
						}
					}
				}
			}

		}
		cout << x+1 << " - " << y+1 << " : " << AdjMatrix[x][y] << endl;
		InMST[y] = true;
		edge_iterator++;
	}

}


void main()
{
	InitMatrix(AdjMatrix);
	//initializing an adjacency matrix
	addRelation(1, 2, 2);
	addRelation(1, 5, 2);
	addRelation(1, 4, 8);
	addRelation(2, 3, 3);
	addRelation(2, 5, 5);
	addRelation(2, 4, 10);
	addRelation(3, 5, 12);
	addRelation(3, 8, 7);
	addRelation(4, 5, 14);
	addRelation(4, 6, 3);
	addRelation(4, 7, 1);
	addRelation(5, 7, 4);
	addRelation(5, 8, 8);
	addRelation(5, 6, 11);
	addRelation(6, 7, 6);
	addRelation(7, 8, 9);

	cout << "The source matrix: " << endl;
	printMatrix(AdjMatrix);
	 
	int StartVertexPrima;
	cout << "Enter the start vertex for Prima algorythm: ";
	cin >> StartVertexPrima;

	PrimMST(AdjMatrix, StartVertexPrima-1);
}