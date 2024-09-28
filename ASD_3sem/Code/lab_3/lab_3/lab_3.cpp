//<-------------------->
//Dijkstra's algorythm for graph where each edge has a weight
// for convinience the graph itself will be implemented as an adjacency matrix
// 
//<--------------------->
#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;

const int NodesInGraph = 9;
vector<vector<int>>AdjMatrix(NodesInGraph, vector<int>(NodesInGraph));
char Letters[] = { 'A','B','C','D','E','F','G','H','I' };
vector<int>Distancies(NodesInGraph, INF);
vector<bool>VisitedNodes(NodesInGraph, false);

void AddNode(char Source, char Dest, int Weight) {
	//convert char to int decimal
	int Src_num = Source - 65;
	int Dest_num = Dest - 65;

	AdjMatrix[Src_num][Dest_num] = Weight;
	AdjMatrix[Dest_num][Src_num] = Weight;
}

void PrintGraph() {
	cout << "Adjacency matrix: " << endl;
	cout << '\t';
	for (int l = 0; l < 9; l++) {
		cout<<'\t' << Letters[l] << ' ';
	}
	cout << endl;

	for (int i = 0; i < NodesInGraph; i++) {
		cout<<'\t';
		for (int j = 0; j < NodesInGraph; j++) {
			cout<<'\t' << AdjMatrix[i][j] << ' ';
		}
		cout<<'\t' << Letters[i];
		cout << endl;
	}
	cout << endl << endl;
}

int findMinDist() {
	int MIN = INT_MAX;
	int MinIndex;

	for (int i = 0; i < NodesInGraph; i++) {
		if (!VisitedNodes[i] && Distancies[i] <= MIN) {
			MIN = Distancies[i];
			MinIndex = i;
		}
	}
	return MinIndex;
}

void PrintDijkstra(int start) {
	cout << "Solution:" << endl;
	for (int i = 0; i < NodesInGraph; i++) {
		if (i != start) {
			cout << "Length of the shortest path from " << Letters[start] << " to " << Letters[i] << " is " << Distancies[i] << endl;
		}
	}
}

void Dijkstra(char StartVertex) {
	int Start = StartVertex - 65;
	Distancies[Start] = 0;

	for (int i = 0; i < NodesInGraph - 1; i++) {
		int U = findMinDist();

		VisitedNodes[U] = true;

		//check all the nodes 
		for (int i = 0; i < NodesInGraph; i++) {
			if (!VisitedNodes[i] && AdjMatrix[U][i]!=0 && Distancies[U] != INF && Distancies[U] + AdjMatrix[U][i] < Distancies[i]) {
				//set the minimal distance from start node to this current node to the new meaning
				Distancies[i] = Distancies[U] + AdjMatrix[U][i];
			}
		}
	}

	PrintDijkstra(Start);
}


void main()
{
	cout << "Implementing the graph" << endl;
	AddNode('A', 'B', 7);
	AddNode('A', 'C', 10);
	AddNode('B', 'F', 9);
	AddNode('B', 'G', 27);
	AddNode('C', 'F', 8);
	AddNode('C', 'E', 31);
	AddNode('F', 'H', 11);
	AddNode('E', 'D', 32);
	AddNode('D', 'H', 17);
	AddNode('D', 'I', 21);
	AddNode('H', 'I', 15);
	AddNode('G', 'I', 15);

	PrintGraph();

	char StartVertex;
	cout << "Enter the start vertex for dijkstra algorithm: ";
	cin >> StartVertex;
	while (!(StartVertex >= 'A' && StartVertex <= 'I')) {
		cout << "Enter the correct letter: ";
		cin >> StartVertex;
	}

	Dijkstra(StartVertex);

}