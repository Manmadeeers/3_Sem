//<-------------------->
// 
//Breadth First Search(BFS) and Depth First Search(DFS)
// for multiple graph implementations
// The Graph itself and all the remaining info is below
//
//<-------------------->

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//for adjacency matrix
int NodesInGraph = 10;
vector<vector<int>>AdjacencyMatrix(NodesInGraph, vector<int>(NodesInGraph));



void PrintAdjMatrix() {
	cout << "Adjacency matrix: " << endl;
	for (int i = 0; i < NodesInGraph; i++) {
		for (int j = 0; j < NodesInGraph; j++) {
			cout << AdjacencyMatrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void AddEdgeMatrix(int Line, int Column) {
	//set connections in both ways because the graph is unoriented
	AdjacencyMatrix[Line-1][Column-1] = 1;
	AdjacencyMatrix[Column-1][Line-1] = 1;
}

void AdjBFS(int Start) {
	vector<bool>VisitedNodes(AdjacencyMatrix.size(), false);
	queue<int>BFSQ;
	BFSQ.push(Start);
	VisitedNodes[Start] = true;

	int Current;
	while (!BFSQ.empty()) {
		Current = BFSQ.front();

		cout << Current+1 << ' ';
		BFSQ.pop();
		//checking all the elements of a single line
		for (int i = 0; i < AdjacencyMatrix[Current].size(); i++) {
			if (AdjacencyMatrix[Current][i] == 1 && (!VisitedNodes[i])) {
				BFSQ.push(i);
				VisitedNodes[i] = true;
			}
		}

	}
}

void AdjDFS(int Start) {
	vector<bool>VisitedNodes(AdjacencyMatrix.size(), false);
	stack<int>DFSStack;
	DFSStack.push(Start);
	VisitedNodes[Start] = true;

	int Current;
	while (!DFSStack.empty()) {
		Current = DFSStack.top();
		cout << Current+1 << ' ';
		DFSStack.pop();
		for (int i = 0; i < AdjacencyMatrix[Current].size(); i++) {
			if (AdjacencyMatrix[Current][i] == 1 && (!VisitedNodes[i])) {
				DFSStack.push(i);
				VisitedNodes[i] = true;
			}
		}
	}
}
//for edge list

vector<pair<int,int>>EdgeList;

void PrintEdgeList()
{
	for (int i = 0; i < EdgeList.size(); i++) {
		if (i != 0 && i % 2 == 0) {
			cout << endl;
		}
		cout << " { " << EdgeList[i].first << " , " << EdgeList[i].second << " } ";
	}
	cout << endl;
}

void AddEdge(int FromVertex,int ToVertex) {
	//twoside connection because graph is unoriented
	EdgeList.push_back({ FromVertex,ToVertex });
	EdgeList.push_back({ ToVertex,FromVertex });
}

void EdgeListBFS(int Start) {
	//the size is doubled because there are two-side connection between ech node
	vector<bool>VisitedNodes(NodesInGraph+1, false);
	queue<int>EdgeQ;
	EdgeQ.push(Start);
	VisitedNodes[Start] = true;
	int Current;

	while (!EdgeQ.empty()) {
		Current = EdgeQ.front();
		EdgeQ.pop();

		cout << Current << ' ';

		//to check all the elements of an array
		for (int i = 0; i < EdgeList.size();i++) {
			if (EdgeList[i].first == Current && !(VisitedNodes[EdgeList[i].second])) {
				VisitedNodes[EdgeList[i].second] = true;
				EdgeQ.push(EdgeList[i].second);
			}
			else if (EdgeList[i].second == Current && (!VisitedNodes[EdgeList[i].first])) {
				VisitedNodes[EdgeList[i].first] = true;
				EdgeQ.push(EdgeList[i].first);
			}
		}
	}
	cout << endl;
}

void EdgeListDFS(int Start) {
	vector<bool>VisitedNodes(NodesInGraph + 1, false);
	stack<int>EdgeS;
	EdgeS.push(Start);
	VisitedNodes[Start] = true;
	int Current;

	while (!EdgeS.empty()) {
		Current = EdgeS.top();
		EdgeS.pop();
		cout << Current << " ";

		for (int i = 0; i < EdgeList.size(); i++) {
			if (EdgeList[i].first == Current && (!VisitedNodes[EdgeList[i].second])) {
				VisitedNodes[EdgeList[i].second] = true;
				EdgeS.push(EdgeList[i].second);
			}
			else if (EdgeList[i].second == Current && (!VisitedNodes[EdgeList[i].first])) {
				VisitedNodes[EdgeList[i].first] = true;
				EdgeS.push(EdgeList[i].first);
			}
		}
	}
	cout << endl;
}

//adjacency list
vector<vector<int>>AdjacencyList(NodesInGraph);

void AddConnection(int Source, int Destination) {
	//the connection is doubled because graph is unoriented
	AdjacencyList[Source-1].push_back(Destination);
	AdjacencyList[Destination-1].push_back(Source);
}

void PrintAdjList()
{
	for (int i = 0; i < AdjacencyList.size(); ++i) {
		cout << i + 1 << ": ";
		for (int j = 0; j < AdjacencyList[i].size(); ++j) {

			cout << AdjacencyList[i][j] <<" -> ";
		}
		cout<<" NULL " << endl;
	}
}

void AdjListBFS(int Start) {
	vector<bool>VisitedNodes(NodesInGraph, false);
	queue<int>AdjQ;
	AdjQ.push(Start);
	VisitedNodes[Start] = true;
	int Current;

	while (!AdjQ.empty()) {
		Current = AdjQ.front();
		cout << Current+1 << ' ';
		AdjQ.pop();

		//to processs each element
		for (const auto& node : AdjacencyList[Current]) {
			if (!VisitedNodes[node-1]) {
				VisitedNodes[node-1] = true;
				//obligatory to substract 1
				AdjQ.push(node-1);
			}
		}
	}
	cout << endl;
}

void AdjListDFS(int Start) {
	vector<bool>VisitedNodes(NodesInGraph, false);
	stack<int>AdjS;
	VisitedNodes[Start] = true;
	AdjS.push(Start);
	int Current;

	while (!AdjS.empty()) {
		Current = AdjS.top();
		cout << Current + 1 << ' ';
		AdjS.pop();

		for (const auto& node : AdjacencyList[Current]) {
			if (!VisitedNodes[node - 1]) {
				VisitedNodes[node - 1] = true;
				AdjS.push(node - 1);
			}
		}
	}
	cout << endl;

}


void main()
{
	
	//Adjacency matrix 
	AddEdgeMatrix(1, 2);
	AddEdgeMatrix(1, 5);
	AddEdgeMatrix(2, 7);
	AddEdgeMatrix(2, 8);
	AddEdgeMatrix(7, 8);
	AddEdgeMatrix(8, 3);
	AddEdgeMatrix(5, 6);
	AddEdgeMatrix(6, 4);
	AddEdgeMatrix(4, 9);
	AddEdgeMatrix(9, 10);

	PrintAdjMatrix();

	int AdjBFSStart;
	cout << "Enter the start node for BFS in adjacency matrix: ";
	cin >> AdjBFSStart;
	cout << "BFS for Adjacency matrix: ";
	AdjBFS(AdjBFSStart-1);
	cout << endl;

	int AdjDFSStart;
	cout << "Enter the start node for DFS in adjacency matrix: ";
	cin >> AdjDFSStart;
	cout << "DFS for adjacency matrix: ";
	AdjDFS(AdjDFSStart-1);
	cout << endl;

	//edge list
	AddEdge(1, 2);
	AddEdge(1,5);
	AddEdge(2,7);
	AddEdge(2,8);
	AddEdge(7,8);
	AddEdge(8,3);
	AddEdge(5,6);
	AddEdge(6,4);
	AddEdge(4,9);
	AddEdge(9,10);

	cout << "Edge list: " << endl;
	PrintEdgeList();
	int EdgeBFSStart;
	cout << "Enter the start vertex for BFS in Edge List: ";
	cin >> EdgeBFSStart;
	cout << "BFS for Edge List: ";
	EdgeListBFS(EdgeBFSStart);
	int EdgeDFSStart;
	cout << "Enter the start vertex for DFS in edge list: ";
	cin >> EdgeDFSStart;
	cout << "DFS for edge list: ";
	EdgeListDFS(EdgeDFSStart);

	//adjacency list
	AddConnection(1, 2);
	AddConnection(1, 5);
	AddConnection(2, 7);
	AddConnection(2, 8);
	AddConnection(7, 8);
	AddConnection(8, 3);
	AddConnection(5, 6);
	AddConnection(6, 4);
	AddConnection(4, 9);
	AddConnection(9, 10);

	cout << "Adjacency list: " << endl;
	PrintAdjList();

	int AdjListBFSStart;
	cout << "Enter the start vertex for BFS in Adjacency list: ";
	cin >> AdjListBFSStart;
	AdjListBFS(AdjListBFSStart-1);

	int AdjListDFSStart;
	cout << "Enter the start vertex for DFS in adjacency List: ";
	cin >> AdjListDFSStart;
	AdjListDFS(AdjListDFSStart-1);
}