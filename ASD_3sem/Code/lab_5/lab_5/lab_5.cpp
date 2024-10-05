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

void PrintPrim(vector<int>MST) {
	cout << "Relation\tWeight" << endl << endl;
	for (int i = 0; i < NodesInGraph; i++) {
		if (i + 1 < NodesInGraph) {
			cout << MST[i]+1 << " - " << MST[i + 1]+1 << " : " << AdjMatrix[MST[i]][MST[i + 1]] << endl;
		}
	}
}

int FindMinDist(vector<int>Dist, vector<bool>Visited) {
	int Min = INF;
	int MinIndex;
	for (int i = 0; i < NodesInGraph; i++) {
		if (!Visited[i] && Dist[i] < Min) {
			Min = Dist[i];
			MinIndex = i;
		}
	}
	return MinIndex;
}


void Prim(vector<vector<int>>Matrix, int StartVertex) {
	vector<bool>Visited(NodesInGraph, false);
	vector<int>MST;
	vector<int>Dist(NodesInGraph, INF);
	Dist[StartVertex] = 0;
	Visited[StartVertex] = true;
	MST.push_back(StartVertex);
	int CountEdges = 0;
	int CurrentLine = StartVertex;
	int Next;
	
	while (CountEdges < NodesInGraph-1) {
		int Min = FindMinDist(Dist, Visited);
		Visited[Min] = true;

		int ForMST;
		int ForDist;
		for (int i = 0; i < NodesInGraph; i++) {

			if (AdjMatrix[Min][i] && Visited[i] == false && AdjMatrix[Min][i] < Dist[i]) {
				ForMST = i;
				Dist[i] = AdjMatrix[Min][i];
			}
		}
		MST.push_back(ForMST);
		CountEdges++;
	}
	PrintPrim(MST);
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

	Prim(AdjMatrix, StartVertexPrima-1);
}