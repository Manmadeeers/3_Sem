//<-------------------->
// 
// finding Minimal Spanning Tree (MST) via different algorythms
// 
//<-------------------->

#include <iostream>
#include <vector>
#include <algorithm>
#define INF INT_MAX
using namespace std;
const int NodesInGraph = 8;
vector<vector<int>>AdjMatrix(NodesInGraph, vector<int>(NodesInGraph));
struct Edge {
	int Source;
	int Destination;
	int Weight;

	bool operator<(const Edge& other) {
		return Weight < other.Weight;
	}
	bool operator>(const Edge& other) {
		return Weight > other.Weight;
	}
};

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
int findMinKey(vector<int>Key, vector<bool>Visited) {
	int Min = INF;
	int MinIndex;
	for (int i = 1; i < NodesInGraph; i++) {
		if (Visited[i] == false && Key[i] < Min) {
			Min = Key[i];
			MinIndex = i;
		}
	}
	return MinIndex;
}

void PrintPrim(vector<Edge>Edges) {
	cout << "Edge\tWeight:" << endl;
	for (int i = 0; i < Edges.size(); i++) {
		cout << Edges[i].Source+1 << "---" << Edges[i].Destination+1 << " : " << Edges[i].Weight << endl;
	}
}

void Prim(int StartVertex) {
	vector<bool>Visited(NodesInGraph, false);
	vector<Edge>StoreOrder;

	Visited[StartVertex] = true;
	int count_edges = 0;
	int minimum_weight = 0;
	while (count_edges < NodesInGraph - 1) {
		int Min = INF;
		int x= -1;
		int y = -1;
		for (int i = 0; i < NodesInGraph; i++) {
			for (int j = 0; j < NodesInGraph; j++) {
				if (AdjMatrix[i][j] < Min) {
					if (i != j && !(Visited[i] == false && Visited[j] == false) && !(Visited[i] == true && Visited[j] == true)) {
						Min = AdjMatrix[i][j];
						x = i;
						y = j;
					}

				}
			}
		}
		if (x != -1 && y != -1) {
			Edge newEdge;
			newEdge.Source = x;
			newEdge.Destination = y;
			newEdge.Weight = Min;
			StoreOrder.push_back(newEdge);
		}
		minimum_weight += Min;
		Visited[x] = true;
		Visited[y] = true;
		count_edges++;
	}
	PrintPrim(StoreOrder);
	cout << "MST minimum weight: " << minimum_weight << endl << endl;
}
void GetEdges(vector<Edge>& Edges) {
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			if (AdjMatrix[i][j] != 0 && AdjMatrix[i][j] != INF) {
				Edge newEdge;
				newEdge.Source = i;
				newEdge.Destination = j;
				newEdge.Weight = AdjMatrix[i][j];
				Edges.push_back(newEdge);
			}
		}
	}
}

bool SortEdges(const Edge&E1, const Edge& E2) {
	return E1.Weight<E2.Weight;
}

void PrintKruskal(vector<Edge>Edges) {
	cout << "Edge\tWeight:" << endl;
	for (int i = 0; i < Edges.size(); i++) {
		cout << Edges[i].Source + 1 << "---" << Edges[i].Destination + 1 << " : " << Edges[i].Weight << endl;
	}
}

void Kruskal() {
	vector<Edge> Edges;
	GetEdges(Edges);
	PrintKruskal(Edges);
	sort(Edges.begin(), Edges.end(), SortEdges);
	cout << "Edges sorted in non-decreasing order:" << endl;
	PrintKruskal(Edges);
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
	 
	int StartVertexPrim;
	cout << "Enter the start vertex for Prim's algorythm: ";
	cin >> StartVertexPrim;
	Prim( StartVertexPrim-1);

	
	cout << "And now Kruskal's algorythm: " << endl << endl << endl;
	Kruskal();
}